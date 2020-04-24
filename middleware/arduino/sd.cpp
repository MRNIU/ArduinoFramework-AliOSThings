/*
 * Copyright (C) 2019 MRNIU
 */

#include <string.h>
#include <algorithm>
#include <include/sd.h>

#define DT_DIR     4
#define DT_REG     8
#define DT_LNK     10

using namespace SDLib;

/**
 * File constructor
 * 
 * @return     void
 */
File::File()
{
    fd = 0;
    filepath[0] = 0;
    this->f_offset = 0;
    aos_dir = NULL;
    return;
}

/**
 * File constructor
 *
 * @param[in]  filepath filepath
 * 
 * @return     void
 */
File::File(const char *filepath)
{
    this->fd = 0;
    strcpy(this->filepath, filepath);
    this->f_offset = 0;
    aos_dir = aos_opendir((this->get_parent_dir()).c_str());
    aos_rewinddir(this->aos_dir);
    return;
}

/**
 * File constructor
 *
 * @param[in]  fd       file descriptor
 * @param[in]  filepath filepath "/sdcard/test.txt"
 * 
 * @return     void
 */
File::File(int fd, const char *filepath)
{
    this->fd=fd;
    strcpy(this->filepath, filepath);
    this->f_offset = 0;
    aos_dir = aos_opendir((this->get_parent_dir()).c_str());
    aos_rewinddir(this->aos_dir);
    return;
}

/**
 * write a byte to file
 *
 * @param[in]  data  the byte which should be write
 * 
 * @return     number of bytes written
 */
size_t File::write(uint8_t data)
{
    ssize_t ret;
    ret = aos_write(this->fd, &data, sizeof(data));
    if(ret < 0){
        printf("ret = %d\n", ret);
        printf("write error!\n");
        return 0;
    }
    this->f_offset += sizeof(data);
    aos_lseek(this->fd, this->f_offset, SEEK_SET);
    return ret;
}

/**
 * write specified bytes to file
 *
 * @param[in]  buf  the buf which should be write
 * @param[in]  size number of bytes
 * 
 * @return     number of bytes written
 */
size_t File::write(const uint8_t * buf, size_t size)
{
    ssize_t ret;
    ret = aos_write(this->fd, buf, size);
    if(ret < 0){
        printf("ret = %d\n", ret);
        printf("write error!\n");
        return 0;
    }
    this->f_offset += size;
    aos_lseek(this->fd, this->f_offset, SEEK_SET);
    return ret;
}

/**
 * read a byte from file
 * 
 * @return      The data being read
 */
int8_t File::read()
{
    int8_t buf;
    aos_lseek(this->fd, this->f_offset, SEEK_SET);
    ssize_t ret = 0;
    ret = aos_read(this->fd, &buf, sizeof(buf));
    if(ret < 0){
        printf("ret = %d\n", ret);
        printf("read error!\n");
        return 0;
    }
    this->f_offset += sizeof(buf);
    return buf;
}

/**
 * read specified bytes from file
 *
 * @param[in]  buf      the buf which should be write
 * @param[in]  nbyte    number of bytes
 * 
 * @return     1 on success, 0 on failure
 */
int32_t File::read(void *buf, uint16_t nbyte)
{
    aos_lseek(this->fd, this->f_offset, SEEK_CUR);
    ssize_t ret = 0;
    ret = aos_read(this->fd, &buf, sizeof(buf));
    if(ret < 0){
        printf("ret = %d\n", ret);
        printf("read error!\n");
        return 0;
    }
    this->f_offset += nbyte;
    return 1;
}

/**
 * peek a byte from file
 * 
 * @return     The data being peek
 */
int8_t File::peek()
{
    int8_t buf;
    ssize_t ret = 0;
    aos_lseek(this->fd, this->f_offset, SEEK_SET);
    ret = aos_read(this->fd, &buf, sizeof(buf));
    if(ret < 0){
        printf("ret = %d\n", ret);
        printf("peek error!\n");
        return -1;
    }
    return buf;
}

/**
 * Check if there are any bytes available for reading from the file.
 * 
 * @return      the number of bytes available
 */
int32_t File::available()
{
    struct aos_stat file_st;
    int ret = aos_stat(this->filepath, &file_st);
    if(ret < 0){
        printf("ret = %d\n", ret);
        printf("available error!\n");
        return -1;
    }
    return file_st.st_size - f_offset -1;
}

/**
 * Ensures that any bytes written to the file are physically saved to the SD card. 
 * This is done automatically when the file is closed.
 * 
 * @return     void
 */
void File::flush()
{
    if(aos_sync(this->fd))
        printf("flush error!\n");
    return;
}

/**
 * Seek to a new position in the file, 
 * which must be between 0 and the size of the file (inclusive).
 *
 * @param[in]  pos    the position to which to seek
 * 
 * @return     1 on success, 0 on failure
 */
bool File::seek(uint32_t pos)
{
    off_t ret = 0;
    ret = aos_lseek(this->fd, pos, SEEK_SET);
    if(ret < 0){
        printf("seek error! ret = %ld\n", ret);
        return 0;
    }
    this->f_offset = pos;
    return 1;
}

/**
 * Get the current position within the file
 * 
 * @return     the position within the file
 */
uint32_t File::position()
{
    return this->f_offset;
}

/**
 * Get the size of the file.
 * 
 * @return     the size of the file in bytes
 */
uint32_t File::size()
{
    struct aos_stat file_st;
    int ret = 0;
    ret = aos_stat(this->filepath, &file_st);
    if(ret < 0){
        printf("size error! ret = %d\n", ret);
        return -1;
    }
    return file_st.st_size;
}

/**
 * Close the file.
 * Ensure that any data written to it is physically saved to the SD card.
 * 
 * @return     void
 */
void File::close()
{
    if(this->isDirectory())
        aos_closedir(this->aos_dir);
    else {
        aos_sync(this->fd);
        aos_close(this->fd);
    }
    return;
}

/**
 * get the name of the file
 * 
 * @return     filename
 */
char * File::name()
{
    return this->filepath;
}

/**
 * Determine whether the current file is a directory
 * 
 * @return     1 on yes, 0 on not
 */
bool File::isDirectory(void)
{
    aos_dir_t * dir;
    dir = aos_opendir(this->filepath);
    if(dir == NULL) {
        return 0;
    }
    aos_closedir(dir);
    return 1;
}

/**
 * Reports the next file or folder in a directory.
 *
 * @param[in]  mode   FILE_READ or FILE_WRITE
 * 
 * @return     File object
 */
File File::openNextFile(uint8_t mode)
{
    aos_dir_t * dir;
    aos_dirent_t * dirent;
    std::string file;
    std::string parpath;
    
    parpath = this->get_parent_dir();
    dir = aos_opendir(parpath.c_str());
    if(dir == NULL) {
        return File();
    }

    int32_t count = 0;
    while( (dirent = aos_readdir(dir) ) != NULL) {
        if(count < this->d_offset) {
            count++;
            continue;
        }
        std::string tmp(dirent->d_name);
        if(tmp.find(".") == 0) {
            count++;
            this->d_offset += 1;
            continue;
        }
        int fd = 0;
        file += parpath;
        file += "/";
        file += std::string(dirent->d_name);
        fd = aos_open(file.c_str(), FILE_READ);
        if(fd > 0){
            this->d_offset += 1;
            aos_closedir(dir);
            return File(fd, file.c_str());
        } else if(fd < 0) {
            this->d_offset += 1;
            aos_closedir(dir);
            return File(file.c_str());
        }
    }
    aos_closedir(dir);
    return File();
}

/**
 * rewindDirectory() will bring you back to the first file in the directory, 
 * used in conjunction with openNextFile().
 * 
 * @return     void
 */
void File::rewindDirectory(void)
{
    aos_rewinddir(this->aos_dir);
    this->d_offset = 0;
    return;
}

File::operator bool()
{
    if( this->filepath[0] != 0)
        return  true;
    return false;
}

std::string File::get_parent_dir(void)
{
    std::string parpath(this->filepath);
    std::string::size_type position;
    std::string flag = "/";

    if(this->isDirectory()) {
        position = parpath.rfind("/");
        if(position == parpath.length()-1){
            parpath.erase(position);
        }
        return parpath;
    } else {
        position = parpath.rfind(flag);
        parpath.erase(position, parpath.length() - position);
        return parpath;
    }
}

/**
 * Initializes the SD library and card.
 * 
 * @return     1 on success, 0 on failure
 */
int32_t SDClass::begin()
{
    // if(hal_sd_init()){
    //     printf("begin error!\n");
    //     return 0;
    // }
    return 1;
}

/**
 * call this when a card is removed.
 * 
 * @return     1 on success, 0 on failure
 */
int32_t SDClass::end()
{
    // if(hal_sd_finalize()){
    //     printf("end error!\n");
    //     return 0;
    // }
    return 1;
}

/**
 * Opens a file on the SD card
 *
 * @param[in]  filepath  the file path which should be open
 * @param[in]  mode      FILE_READ or FILE_WRITE
 * 
 * @return     File object
 */
File SDClass::open(const char *filepath, uint32_t mode)
{
    int32_t fd = 0;
    fd = aos_open(filepath, mode);
    if(fd < 0){
        // printf("fd = %ld\n", fd);
        // printf("open error!\n");
        return File(filepath);
    }
    return File(fd, filepath);
}

/**
 * Tests whether a file or directory exists on the SD card.
 *
 * @param[in]  filepath  the file path which should be test
 * 
 * @return     1 on yes, 0 on not
 */
int32_t SDClass::exists(const char *filepath)
{
    struct aos_stat file_st;
    int32_t res = 0;
    res = aos_stat(filepath, &file_st);
    if(res == -ENOENT){
        return 0;
    }
    return 1;
}

/**
 * Create a directory on the SD card.
 *
 * @param[in]  filepath  the file path which should be create
 * 
 * @return     1 on success, 0 on failure
 */
int32_t SDClass::mkdir(const char * filepath)
{
    int32_t res;
    res = aos_mkdir(filepath);
    if(res < 0){
        printf("aos_mkdir() = %ld\n", res);
        printf("mkdir error!\n");
        if(res == -22)
            printf("File exists or invalid argument!\n");
        return 0;
    }
    return 1;
}

/**
 * Remove a file from the SD card.
 *
 * @param[in]  filepath  the file path which should be remove
 * 
 * @return     1 on success, 0 on failure
 */
int32_t SDClass::remove(const char *filepath)
{
    int32_t res;
    res = aos_unlink(filepath);
    if(res < 0){
        printf("res = %ld\n", res);
        printf("remove error!\n");
        return 0;
    }
    return 1;
}

/**
 * Remove a directory from the SD card.
 *
 * @param[in]  filepath  the dir path which should be remove
 * 
 * @return     1 on success, 0 on failure
 */
int32_t SDClass::rmdir(const char *filepath)
{   
    int32_t res;
    res = aos_rmdir(filepath);
    if(res){
        printf("filepath: %s\n", filepath);
        printf("res = %ld\n", res);
        printf("rmdir error!\n");
        return 0;
    }
    return 1;
}
