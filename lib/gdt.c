#include "gdt.h"
#include "print.h"

// Define the GDT entries
struct gdt_entry gdt_entries[5];

// Define the GDT pointer
struct gdt_ptr gdt_ptr;

// Assembly function to load the GDT
extern void load_gdt();

// Function to set a GDT entry
void set_gdt_entry(int index, uint32_t base, uint32_t limit, uint8_t access, uint8_t granularity) {
    // Set the base address
    gdt_entries[index].base_low    = base & 0xFFFF;
    gdt_entries[index].base_middle = (base >> 16) & 0xFF;
    gdt_entries[index].base_high   = (base >> 24) & 0xFF;

    // Set the limits
    gdt_entries[index].limit_low   = limit & 0xFFFF;
    gdt_entries[index].granularity = (limit >> 16) & 0x0F;

    // Set access flags
    gdt_entries[index].access = access;

    // Set granularity and limit flags
    gdt_entries[index].granularity |= (granularity & 0xF0);
}

// Function to initialize the GDT
void init_gdt() {
    // Set up the GDT entries
    set_gdt_entry(0, 0, 0, 0, 0); // Null segment
    set_gdt_entry(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); // Code segment
    set_gdt_entry(2, 0, 0xFFFFFFFF, 0x92, 0xCF); // Data segment

    // Load the GDT
    //gdt_ptr.limit = sizeof(gdt_entries) - 1;
    //gdt_ptr.base = (uint64_t)&gdt_entries[0];
    asm volatile("lgdt %0" : : "m"(gdt_ptr));
    printf("[os] init gdt");
    print_newline();
}
