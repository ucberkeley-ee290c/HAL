#include "encoding.h"

//#if __riscv_xlen == 64
  #define LREG ld
  #define SREG sd
  #define REGBYTES 8
/*#else
  #define LREG lw
  #define SREG sw
  #define REGBYTES 4
#endif
*/

# /* start address for the .data section. defined in linker script */  
# .word  _data_source_start
# /* end address for the .data section. defined in linker script */
# .word  _data_target_start
# .word  _data_target_end
# /* start address for the .bss section. defined in linker script */
# .word  _bss_start
# /* end address for the .bss section. defined in linker script */
# .word  _bss_end

.align 4
.section .text.reset
.section .text.init
.globl _start
_start:
  # initialize registers
  li t0, 0x1001A000
  li t1, 0x1
  lw t1, 8(t0)
  lw t1, 0(t0)

  j _start
