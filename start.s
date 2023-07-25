.section .text
.global _start

_start:
    csrr    t0, mhartid             
    bnez    t0, loop       
    la      sp, endstack          
    j       main

loop:	
    wfi
    j       loop

