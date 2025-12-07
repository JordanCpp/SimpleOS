
#
.extern InterruptHandler

#
.macro ISR_NO_ERRCODE number
.global isr\number
isr\number:
    pushal          
    pushl %ds
    pushl %es
    pushl %fs
    pushl %gs
    
    pushl $\number
    
    call InterruptHandler

    popl %eax
    popl %gs
    popl %fs
    popl %es
    popl %ds
    popal           

    iretl           
.endm

#
.macro ISR_ERRCODE number
.global isr\number
isr\number:
    pushal          
    pushl %ds
    pushl %es
    pushl %fs
    pushl %gs

    pushl $\number
    
    call InterruptHandler

    popl %eax
    popl %gs
    popl %fs
    popl %es
    popl %ds
    popal           

    addl $4, %esp
    iretl
.endm

#
ISR_NO_ERRCODE 0
ISR_NO_ERRCODE 1
ISR_NO_ERRCODE 2
ISR_NO_ERRCODE 3
ISR_NO_ERRCODE 4
ISR_NO_ERRCODE 5
ISR_NO_ERRCODE 6
ISR_NO_ERRCODE 7
ISR_ERRCODE    8          
ISR_NO_ERRCODE 9
ISR_ERRCODE    10        
ISR_ERRCODE    11         
ISR_ERRCODE    12         
ISR_ERRCODE    13         
ISR_ERRCODE    14
ISR_NO_ERRCODE 15
ISR_NO_ERRCODE 16
ISR_ERRCODE    17
ISR_NO_ERRCODE 18
ISR_NO_ERRCODE 19
ISR_NO_ERRCODE 32
ISR_NO_ERRCODE 33
