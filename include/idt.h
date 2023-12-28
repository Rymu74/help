#ifndef IDT_H
#define IDT_H

#include <stdint.h>

// Define the structure for an IDT entry
struct idt_entry {
    uint16_t base_low;      // The lower 16 bits of the address to jump to when this interrupt fires
    uint16_t selector;      // Kernel segment selector
    uint8_t  ist;           // Interrupt Stack Table offset
    uint8_t  type_attr;     // Type and attributes
    uint16_t base_middle;   // The upper 16 bits of the address to jump to
    uint32_t base_high;     // The last 32 bits of the address to jump to
    uint32_t reserved;
} __attribute__((packed));

// Define the structure for the IDT pointer
struct idt_ptr {
    uint16_t limit;         // The upper 16 bits of all IDT limits
    uint64_t base;          // The address of the first idt_entry struct
} __attribute__((packed));

// Function to initialize the IDT
void init_idt();

#endif // IDT_H
