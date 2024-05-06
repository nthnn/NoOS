#ifndef NOOS_TYPES_H
#define NOOS_TYPES_H

typedef void*               any;

typedef char                rune;
typedef char*               string;

typedef signed char         i8;
typedef signed short int    i16;
typedef signed int          i32;
typedef signed long int     i64;

typedef unsigned char       u8;
typedef unsigned short int  u16;
typedef unsigned int        u32;
typedef unsigned long int   u64;

typedef unsigned long long  usize;

typedef float               num32;
typedef double              num64;

#define F(str) ((char*) str)

#endif