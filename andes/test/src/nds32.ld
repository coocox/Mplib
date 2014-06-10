/* ROM code linker script, for normal executables */
OUTPUT_FORMAT("elf32-nds32", "elf32-nds32", "elf32-nds32")
OUTPUT_ARCH(nds32)
/* define entry point of the program */
ENTRY(_start)

_ILM_BASE = 0x00600000; /* ILM base address */
_DLM_BASE = 0x00700000; /* DLM base address */
_ILM_SIZE = 0x10000; /*64Kb*/
_DLM_SIZE = 0x10000; /*64Kb*/
/*_DLM_SIZE = 0x0000;*/ /*64Kb*/
/*_ILM_SIZE = 0x2000;*/ /* 8Kb */
/*_DLM_SIZE = 0x2000;*/ /* 8Kb */


MEMORY
{
  /* first! be the default VMA/LMA base put at */
  /* define memory regin */
  /* syntax: region_name (attribute) : ORIGIN = starting-address, LENGTH = size-of-region-in-byte */
  /* attribute: rwxail! */
  /*
  FLASH (arx) : ORIGIN = 0x00000000, LENGTH = 16M
  SDRAM (awx) : ORIGIN = 0x10000000, LENGTH = 128M
  */

  SDRAM (awx) : ORIGIN = 0x00000000, LENGTH = 8M
}

SECTIONS
{
  /* Read-only sections, merged into text segment: */
  PROVIDE (__executable_start = ORIGIN(SDRAM)); 
  .nds32_init ORIGIN(SDRAM) : { KEEP(*(.nds32_init)) } > SDRAM
  PROVIDE (__text_begin = .);
  .text           :
  {
    *(.text .stub .text.* .gnu.linkonce.t.*)
    /* .gnu.warning sections are handled specially by elf32.em.  */
    *( .gnu.warning)
  } > SDRAM
  PROVIDE (__text_end = .);
  PROVIDE (__etext = .);
  PROVIDE (_etext = .);
  PROVIDE (etext = .);
  .rodata         : { *( .rodata .rodata.* .gnu.linkonce.r.*) } > SDRAM

  /* Adjust the address for the data segment.  We want to adjust up to
     the same address within the page on the next page up.  */
  /* Ensure the __preinit_array_start label is properly aligned.  We
     could instead move the label definition inside the section, but
     the linker would then create the section even if it turns out to
     be empty, which isn't pretty.  */
  .jcr            : { KEEP (*(.jcr)) } > SDRAM 
  /*. = DATA_SEGMENT_RELRO_END (0, .);*/
  PROVIDE (_data = .);
  __data_lmastart = LOADADDR (.data);
  PROVIDE(__data_begin = .);
  . = ALIGN(4);
  .data           :
  {
    __data_start = .;
    *(.data .data.* .gnu.linkonce.d.*)
  } > SDRAM 
  PROVIDE(__data_end = .);
  . = ALIGN(4);
  /* We want the small data sections together, so single-instruction offsets
     can access them all, and initialized data all before uninitialized, so
     we can shorten the on-disk segment size.  */
  .sdata_d          :
  {
    *(.sdata_d .sdata_d.*)
  } > SDRAM 
  .sdata_w          :
  {
    *(.sdata_w .sdata_w.*)
  } > SDRAM 
  .sdata_h          :
  {
    *(.sdata_h .sdata_h.*)
  } > SDRAM 
  .sdata_b          :
  {
    *(.sdata_b .sdata_b.*)
  } > SDRAM 
  _edata = .;
  _lmaend = .;
  PROVIDE (edata = .);
  . = ALIGN(4);
  PROVIDE (_bstart = .);
  __bss_start = .;
  PROVIDE (__sbss_start = .);
  PROVIDE (___sbss_start = .);
  .sbss_b           :
  {
    *(.sbss_b .sbss_b.*)
    . = ALIGN(2);
  } > SDRAM
  .sbss_h           :
  {
    *(.sbss_h .sbss_h.*)
    . = ALIGN(4);
  } > SDRAM 
  .sbss_w           :
  {
    *(.sbss_w .sbss_w.*)
  } > SDRAM
  PROVIDE (__sbss_end = .);
  PROVIDE (___sbss_end = .);
  PROVIDE(__bss_begin = .);
  .bss            :
  {
   *(.bss .bss.* .gnu.linkonce.b.*)
   /* Align here to ensure that the .bss section occupies space up to
      _end.  Align after .bss to ensure correct alignment even if the
      .bss section disappears because there are no input sections.  */
   . = ALIGN(32 / 8);
  } > SDRAM 
  PROVIDE(__bss_end = .);
  PROVIDE (_bend = .);
  _end = .;
  PROVIDE (end = .);
  /*. = DATA_SEGMENT_END (.);*/
  
/* BEGIN OF DEBUGGING INFO; DO NOT CHANGE ANYTHING STARTING FROM HERE */
  .comment       0 : { *(.comment) }
  /* DWARF debug sections.
     Symbols in the DWARF debugging sections are relative to the beginning
     of the section so we begin them at 0.  */
  /* DWARF 1.1 and DWARF 2 */
  .debug_aranges  0 : { *(.debug_aranges) }
  .debug_pubnames 0 : { *(.debug_pubnames) }
  /* DWARF 2 */
  .debug_info     0 : { *(.debug_info .gnu.linkonce.wi.*) }
  .debug_abbrev   0 : { *(.debug_abbrev) }
  .debug_line     0 : { *(.debug_line) }
  .debug_frame    0 : { *(.debug_frame) }
  .debug_str      0 : { *(.debug_str) }
  .debug_loc      0 : { *(.debug_loc) }
  .debug_macinfo  0 : { *(.debug_macinfo) }
/* END OF DEBUGGING INFO; DO NOT CHANGE ANYTHING BEFORE THIS LINE */

  /* set stack top symbol, _stack has to be 8 bytes aligned. */
  PROVIDE (_stack = ORIGIN(SDRAM) + LENGTH(SDRAM));
  /DISCARD/ : { *(.note.GNU-stack) } > SDRAM 
}

