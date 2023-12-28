#ifndef GDT_H
#define GDT_H

#include <stdint.h>


// Define the structure for the GDT pointer
struct gdt_ptr {
    uint16_t limit;         // The upper 16 bits of all GDT limits
    uint64_t base;          // The address of the first gdt_entry struct
} __attribute__((packed));

// Function to initialize the GDT
void init_gdt();

#endif // GDT_H
