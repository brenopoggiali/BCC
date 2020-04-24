.data
    len_arr1: .word 3
    array1:
        arr1[0]: .word 1
        arr1[1]: .word 2
        arr1[2]: .word 3
    array2:
        arr2[0]: .word 3
        arr2[1]: .word 1
        arr2[2]: .word 2
    checked: .word -1
    #checked: .asciiz "checked" --> Caso for considerar os numeros negativos
    memory_change: .word 4      # "pulo" entre cada endereco de memória
    len_arr2: .word 3

.text
    lw s0, len_arr1
    lw t5, len_arr2
    lw t4, memory_change

    # Caso os vetores tenham tamanhos diferentes encerramos o programa
    bne s0, t5, is_not_permutation

    # Contadores de quantos elementos verificamos nos array1 e array2
    addi s3, s3, -1
    addi s4, s4, -1

    j find_arr1_first_index

load_element:
    addi s3, s3, 1
    beq s3, s0, is_permutation  # Todos os elementos foram verificados

    mul t1, s3, t4          # Somando 4 ao endereco
    add t1, s1, t1          # Endereco do proximo indice
    lw t2, 0(t1)            # Guardamos o endereco de arr1[i] no registrador t2
    j find_element

# .data alocou os elementos do arr1 sequencialmente na memoria
find_arr1_first_index:
    la s1 array1            # Endereco do primeiro elemento do array1
    j find_arr2_first_index

# Processo para encontrar o endereco do primeiro elemento do array2
find_arr2_first_index:
    la s2 array2            # Endereco do primeiro elemento do array2
    j load_element

find_element:
    addi s4 s4, 1
    beq s4, s0, is_not_permutation # Caso nao tenhamos achado par

    mul t1, s4, t4          # Somando 4 ao endereco
    add t1, s2, t1          # Endereco do proximo indice
    lw t3, 0(t1)            # Guardamos o endereco de arr2[j] no registrador t3

    bne t2, t3, find_element # Nao encontrou par, continua procurando

    lw t3, checked          # Caso o numero seja igual, marcamos a posicao
    sw t3, 0(t1)
    addi, s4, zero, -1      # Contador do arr2 = 0
    j load_element          # Conferimos o proximo elemento do arr1

is_not_permutation:
    addi a1, zero, 0
    addi a0, zero, 1
    j answer

is_permutation:
    addi a1, zero, 1
    addi a0, zero, 1

answer:
    ecall
