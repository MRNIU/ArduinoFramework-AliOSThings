/*
 * Copyright (C) 2019 MRNIU
 */

#ifndef ARDUINO_SD_H
#define ARDUINO_SD_H

#include <string>

#ifdef __cplusplus
extern"C" {
#endif /* __cplusplus */ 

#include <aos/hal/sd.h>
#include <aos/vfs.h>
#include <fs/vfs_conf.h>
#include <sys/fcntl.h>

#ifdef __cplusplus
}
#endif /* __cplusplus */ 

#define FILE_READ O_RDONLY
#define FILE_WRITE (O_RDWR | O_CREAT | O_APPEND)
#ifndef ENOENT
#define ENOENT 2
#endif

namespace SDLib {

    class File {
    private:
        char filepath[VFS_PATH_MAX] = {0};
        int fd = 0;
        off_t f_offset = 0;
        aos_dir_t * aos_dir;
        int32_t d_offset = 0;
        std::string get_parent_dir(void);

    public:
        File(void);
        File(const char *filepath);
        File(int fd, const char *filepath);
        size_t write(uint8_t data);
        size_t write(const uint8_t * buf, size_t size);
        int8_t read();
        int32_t read(void *buf, uint16_t nbyte);
        int8_t peek();
        int32_t available();
        void flush();
        bool seek(uint32_t pos);
        uint32_t position();
        uint32_t size();
        void close();
        char * name();
        bool isDirectory(void);
        File openNextFile(uint8_t mode = O_RDONLY);
        void rewindDirectory(void);
        operator bool();
    };


    class SDClass {
    public:
        int32_t begin();
        int32_t end();
        
        File open(const char * filepath, uint32_t mode = FILE_READ);
        File open(const std::string &filepath, uint32_t mode = FILE_READ) { return open( filepath.c_str(), mode ); }

        int32_t exists(const char *filepath);
        int32_t exists(const std::string &filepath) { return exists(filepath.c_str()); }

        int32_t mkdir(const char *filepath);
        int32_t mkdir(const std::string &filepath) { return mkdir(filepath.c_str()); }
  
        int32_t remove(const char *filepath);
        int32_t remove(const std::string &filepath) { return remove(filepath.c_str()); }

        int32_t rmdir(const char *filepath);
        int32_t rmdir(const std::string &filepath) { return rmdir(filepath.c_str()); }
    };
}; /* namespace SDLib  */

__attribute__((unused)) static SDLib::SDClass SD;

using namespace SDLib;

#endif /* ARDUINO_SD_H */