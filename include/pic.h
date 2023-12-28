#ifndef PIC_H
#define PIC_H

#include <stdint.h>

// Ports for the PICs
#define PIC1_COMMAND 0x20
#define PIC1_DATA    0x21
#define PIC2_COMMAND 0xA0
#define PIC2_DATA    0xA1

// Initialization command words
#define ICW1_INIT     0x10
#define ICW1_ICW4     0x01
#define ICW4_8086     0x01

// Function to initialize the PIC
void init_pic();

// Function to acknowledge an interrupt from the PIC
void pic_acknowledge(uint8_t irq);

#endif // PIC_H
