.data
    entrada:.word 201
    um:.word 1

.text
    lw s0, entrada
    lw x10, um

is_even:
    add x5, s0, x0
    addi x6, x0, 2
    rem x11,x5, x6
    mul x11, x11, x11
    ecall
