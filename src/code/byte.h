#pragma once
typedef unsigned char byte;
typedef unsigned int bits_unit;
typedef unsigned short uint16;
typedef unsigned int uint32;
#define BigLittleSwap16(A)        ((((uint16)(A) & 0xff00) >> 8) | \
                                                       (((uint16)(A) & 0x00ff) << 8))


#define BigLittleSwap32(A)        ((((uint32)(A) & 0xff000000) >> 24) | \
                                                       (((uint32)(A) & 0x00ff0000) >> 8) | \
                                                       (((uint32)(A) & 0x0000ff00) << 8) | \
                                                       (((uint32)(A) & 0x000000ff) << 24))
