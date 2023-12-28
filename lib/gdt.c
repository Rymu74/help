#include "gdt.h"
#include "print.h"

// Define the GDT entries
struct gdt_entry gdt_entries[5];

// Define the GDT pointer
struct gdt_ptr gdt_ptr;

// Assembly function to load the GDT
extern void load_gdt();

// Function to set a GDT entry


// Function to initialize the GDT
void init_gdt() {
    // Set up the GDT entries


    // Load the GDT
    gdt_ptr.limit = sizeof(gdt_entries) - 1;
    gdt_ptr.base = (uint64_t)&gdt_entries[0];
    asm volatile("lgdt %0" : : "m"(gdt_ptr));
    printf("[os] init gdt");
    print_newline();
}
