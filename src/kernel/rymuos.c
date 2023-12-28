#include <stdbool.h>
#include "print.h"
#include "gdt.h"
#include "idt.h"
#include "pic.h"



// Function to write a byte to an I/O port
//void outb(uint16_t port, uint8_t value) {
//    asm volatile ("outb %0, %1" : : "a"(value), "Nd"(port));
//}

void rymuos() {
    print_clear();
    print_set_color(15, 2);
    init_gdt();
    init_idt();
    init_pic();
    print_newline();
    print_newline();
    printf("rymuos$ ");
    asm volatile("sti");
    while (true) {
        asm volatile("hlt");
    }
}