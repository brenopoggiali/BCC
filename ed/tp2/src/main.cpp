#include "array.h"
#include <stdio.h>
#include <time.h>
#include <stdio.h>
#include <string>

void timer(){
  struct timespec start, end;
  // Pega o horário do sistema antes da execução do código
  clock_gettime(CLOCK_REALTIME, &start);
  // Código que você quer medir o tempo
  for (int i = 0; i < 1000000; i++) {
    string queen = "Elsa";
  }
  // Pega o horário do sistema depois da execução do código
  clock_gettime(CLOCK_REALTIME, &end);
  // Obtém a diferença entre o horário de fim e o de início
  long elapsed_time = 1.e+6 * (double) (end.tv_sec - start.tv_sec)
  + 1.e-3 * (double) (end.tv_nsec - start.tv_nsec);
  printf("Tempo de execução: %ld microssegundos\n", elapsed_time);
}

int main(int argc, char const *argv[]){
  printf("%s\n", *argv);
  int tamanhos[10] = {50000, 100000, 150000, 200000, 250000,
                      300000, 350000, 400000, 450000, 500000};
  string quickSorts[7] = {"QC", "QM3", "QPE", "QI1", "QI5",
                          "QI10", "QNR"};
  string types[3] = {"Ale", "OrdC", "OrdD"};

  Array crescente(10);
  Array decrescente(10);
  Array aleatorio(10);
  Array aleatorio2(10);

  decrescente.desc_array();
  aleatorio.shuffle_array();
  aleatorio.get_qc();

  crescente.print_array();
  decrescente.print_array();
  aleatorio.print_array();
  aleatorio2.shuffle_array();
  aleatorio2.print_array();

  printf("\n");

  aleatorio.print_array();

  aleatorio2.get_qm3();
  aleatorio2.print_array();

  decrescente.get_qpe();
  decrescente.print_array();

  return 0;
}
