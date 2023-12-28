#include "pic.h"
#include "io.h"
#include "print.h"
void init_pic() {
    // ICW1 - Initialization
    outb(PIC1_COMMAND, ICW1_INIT | ICW1_ICW4);
    outb(PIC2_COMMAND, ICW1_INIT | ICW1_ICW4);

    // ICW2 - Set the interrupt vector offset
    outb(PIC1_DATA, 0x20); // IRQs 0-7 will be mapped to interrupts 0x20-0x27
    outb(PIC2_DATA, 0x28); // IRQs 8-15 will be mapped to interrupts 0x28-0x2F

    // ICW3 - Configure cascading between PIC1 and PIC2
    outb(PIC1_DATA, 0x04);
    outb(PIC2_DATA, 0x02);

    // ICW4 - Set additional configuration
    outb(PIC1_DATA, ICW4_8086);
    outb(PIC2_DATA, ICW4_8086);
    printf("[os] init pic");
    print_newline();
}

void pic_acknowledge(uint8_t irq) {
    // If the interrupt came from the slave PIC, acknowledge it to both PICs
    if (irq >= 8) {
        outb(PIC2_COMMAND, 0x20);
    }

    // Acknowledge the interrupt to the master PIC
    outb(PIC1_COMMAND, 0x20);
}
