#ifndef GDT_H
#define GDT_H

#include <stdint.h>

// Define the structure for a GDT entry
struct gdt_entry {
    uint16_t limit_low;     // The lower 16 bits of the limit
    uint16_t base_low;      // The lower 16 bits of the base
    uint8_t  base_middle;   // The next 8 bits of the base
    uint8_t  access;        // Access flags
    uint8_t  granularity;   // Granularity and limit flags
    uint8_t  base_high;     // The last 8 bits of the base
} __attribute__((packed));

// Define the structure for the GDT pointer
struct gdt_ptr {
    uint16_t limit;         // The upper 16 bits of all GDT limits
    uint64_t base;          // The address of the first gdt_entry struct
} __attribute__((packed));

// Function to initialize the GDT
void init_gdt();

#endif // GDT_H
