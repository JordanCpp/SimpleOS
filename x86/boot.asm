
.section .note.GNU-stack,"",@progbits

.section .multiboot
.align 4
.long 0x1BADB002
.long 0x00
.long - (0x1BADB002 + 0x00)

.section .text
.global _start

_start:

    call KernelMain

halt:
    hlt
    jmp halt
