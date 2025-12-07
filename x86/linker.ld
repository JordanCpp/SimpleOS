
ENTRY(_start)
OUTPUT_FORMAT(elf32-i386)

SECTIONS
{
    . = 0x1600000;
    
    .text : { 
        *(.multiboot)
        *(.text) 
    }
    
    .data : { *(.data) }
    .bss  : { *(.bss)  }
    .rodata : { *(.rodata) }
}
