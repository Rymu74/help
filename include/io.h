#ifndef IO_H
#define IO_H

#include <stdint.h>

// Function to write a byte to an I/O port
void outb(uint16_t port, uint8_t value);

// Function to read a byte from an I/O port
uint8_t inb(uint16_t port);

#endif // IO_H
