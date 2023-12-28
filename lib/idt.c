// idt.c

#include "idt.h"
#include "io.h"

// Define the IDT entries
struct idt_entry idt_entries[256];

// Define the IDT pointer
struct idt_ptr idt_ptr;

// Function to set an IDT entry
void set_idt_entry(int index, uint64_t base, uint16_t selector, uint8_t type_attr) {
    // Set the base address
    idt_entries[index].base_low    = base & 0xFFFF;
    idt_entries[index].base_middle = (base >> 16) & 0xFFFF;
    idt_entries[index].base_high   = (base >> 32) & 0xFFFFFFFF;

    // Set the segment selector
    idt_entries[index].selector    = selector;

    // Set IST, type, and attributes
    idt_entries[index].ist         = 0;
    idt_entries[index].type_attr   = type_attr;

    // Set reserved field to 0
    idt_entries[index].reserved    = 0;
}

// Function to initialize the IDT
void init_idt();

// Assembly function to load the IDT
// ISR for keyboard interrupt
void keyboard_isr() {
    // Print a message indicating that a keyboard interrupt was received
    printf("Keyboard interrupt received\n");

    // Acknowledge the interrupt to the PIC
    pic_acknowledge(1); // Assuming keyboard is connected to IRQ1
}

// Function to initialize the IDT
void init_idt() {
    // Set up the IDT entries
    set_idt_entry(0x21, (uint64_t)keyboard_isr, 0x08, 0x8E); // Keyboard interrupt

    // Load the IDT using inline assembly
    asm volatile("lidt %0" : : "m"(idt_ptr));
    printf("[os] init idt");
    print_newline();
}
