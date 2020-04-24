/*
 * Copyright (C) 2019 MRNIU
 */

#ifndef ARDUINO_CHARACTER_H
#define ARDUINO_CHARACTER_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <ctype.h>

inline bool isAlphaNumeric(int c) __attribute__((always_inline));
inline bool isAlpha(int c) __attribute__((always_inline));
inline bool isAscii(int c) __attribute__((always_inline));
inline bool isWhitespace(int c) __attribute__((always_inline));
inline bool isControl(int c) __attribute__((always_inline));
inline bool isDigit(int c) __attribute__((always_inline));
inline bool isGraph(int c) __attribute__((always_inline));
inline bool isLowerCase(int c) __attribute__((always_inline));
inline bool isPrintable(int c) __attribute__((always_inline));
inline bool isPunct(int c) __attribute__((always_inline));
inline bool isSpace(int c) __attribute__((always_inline));
inline bool isUpperCase(int c) __attribute__((always_inline));
inline bool isHexadecimalDigit(int c) __attribute__((always_inline));
inline int toAscii(int c) __attribute__((always_inline));
inline int toLowerCase(int c) __attribute__((always_inline));
inline int toUpperCase(int c)__attribute__((always_inline));

inline bool isAlphaNumeric(int c) 
{
  return ( isalnum(c) == 0 ? false : true);
}

inline bool isAlpha(int c)
{
  return ( isalpha(c) == 0 ? false : true);
}

inline bool isAscii(int c)
{
  return ( isascii (c) == 0 ? false : true);
}

inline bool isWhitespace(int c)
{
  return ( isblank (c) == 0 ? false : true);
}

inline bool isControl(int c)
{
  return ( iscntrl (c) == 0 ? false : true);
}

inline bool isDigit(int c)
{
  return ( isdigit (c) == 0 ? false : true);
}

inline bool isGraph(int c)
{
  return ( isgraph (c) == 0 ? false : true);
}

inline bool isLowerCase(int c)
{
  return (islower (c) == 0 ? false : true);
}

inline bool isPrintable(int c)
{
  return ( isprint (c) == 0 ? false : true);
}

inline bool isPunct(int c)
{
  return ( ispunct (c) == 0 ? false : true);
}

inline bool isSpace(int c)
{
  return ( isspace (c) == 0 ? false : true);
}

inline bool isUpperCase(int c)
{
  return ( isupper (c) == 0 ? false : true);
}

inline bool isHexadecimalDigit(int c)
{
  return ( isxdigit (c) == 0 ? false : true);
}

inline int toAscii(int c)
{
  return toascii (c);
}

inline int toLowerCase(int c)
{
  return tolower (c);
}

inline int toUpperCase(int c)
{
  return toupper (c);
}

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ARDUINO_CHARACTER_H */