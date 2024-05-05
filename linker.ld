ENTRY(start)
OUTPUT_FORMAT(elf32-i386)
OUTPUT_ARCH(i386:i386)
SECTIONS {
    . = 0x100000;
    .text : { *(.text) }
    .data ALIGN(4096) : { *(.data) }
    .bss : { *(.bss) }
}
