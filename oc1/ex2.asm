.data
    entrada: .word 10
    controle: .word 1

.text
    lw s0, entrada
    lw x10, controle
    lw x11, entrada

fact:
    addi s0, s0, -1
    mul x11, x11, s0
    bne s0 x10, fact

answer:
  ecall
