section .data

x: dd 32
y: dd 50

msg1: db "x is greater than y",10,0
msg2: db "y is greater than x",10,0 


section .bss



section .text 

global _start     ;

_start:
    ; create stack frame
    push rbx
    mov rbx, rdx



    ; if(x > y) {
    ; msg1    
    ;} else {
    ; msg2    
    ;}

    mov eax, DWORD [x]
    mov ebx, DWORD [y]

    cmp eax, ebx
    jg .xGreatThanY
    push DWORD msg2
    syscall
    jmp .done
.xGreatThanY:
    push DWORD msg1
    syscall
    jmp .done  

.done: 

    ; destroy stack frame
    mov rdx, rbx
    pop rbx