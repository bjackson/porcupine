#ifndef _LIB_H
#define _LIB_H

#include "types.h"

int32_t printf(int8_t *format, ...);
void putc(uint8_t c);
int32_t puts(int8_t *s);
int8_t *itoa(uint32_t value, int8_t* buf, int32_t radix);
uint32_t strlen(const int8_t* s);
void set_cursor(int row, int col);
int8_t *strrev(int8_t* s);


#define VIDEO 0xB8000 //TODO: Redefine


/* Writes a byte to a port */
#define outb(data, port)                \
do {                                    \
} while(0)

#endif
