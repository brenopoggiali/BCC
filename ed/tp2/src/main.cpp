#include "array.h"
#include <chrono>
#include <string>
#include <stdio.h>
#include <iostream>

// void timer(){
//   struct timespec start, end;
//   // Pega o horário do sistema antes da execução do código
//   clock_gettime(CLOCK_REALTIME, &start);
//   // Código que você quer medir o tempo
//   for (int i = 0; i < 1000000; i++) {
//     string queen = "Elsa";
//   }
//   // Pega o horário do sistema depois da execução do código
//   clock_gettime(CLOCK_REALTIME, &end);
//   // Obtém a diferença entre o horário de fim e o de início
  // long elapsed_time = 1.e+6 * (double) (end.tv_sec - start.tv_sec)
  // + 1.e-3 * (double) (end.tv_nsec - start.tv_nsec);
//   printf("Tempo de execução: %ld microssegundos\n", elapsed_time);
// }

int main(int argc, char const *argv[]){
  // printf("%s\n", *argv);
  struct timespec start, end;
  std::chrono::high_resolution_clock::time_point t1;
  std::chrono::high_resolution_clock::time_point t2;
  std::chrono::duration<double, std::micro> elapsed_time;

  string types[3] = {"Ale", "OrdC", "OrdD"};
  string quickSorts[7] = {"QC", "QM3", "QPE", "QI1", "QI5",
                          "QI10", "QNR"};
  int tamanhos[10] = {50000, 100000, 150000, 200000, 250000,
                      300000, 350000, 400000, 450000, 500000};

  for (int i = 0; i < 7; ++i){
    for (int j = 0; j < 1; ++j){
      for (int k = 0; k < 1; ++k){
        Array exemplo(10);

        // Get array type
        if(types[j] == "Ale") exemplo.shuffle_array();
        else if(types[j] == "OrdD") exemplo.desc_array();

        std::cout << "Antes: ";
        exemplo.print_array();

        // Get quickSort
        if (quickSorts[i] == "QC"){
          t1 = std::chrono::high_resolution_clock::now();
          exemplo.get_qc();
          t2 = std::chrono::high_resolution_clock::now();
        }else if (quickSorts[i] == "QM3"){
          t1 = std::chrono::high_resolution_clock::now();
          exemplo.get_qm3();
          t2 = std::chrono::high_resolution_clock::now();
        }else if (quickSorts[i] == "QPE"){
          t1 = std::chrono::high_resolution_clock::now();
          exemplo.get_qpe();
          t2 = std::chrono::high_resolution_clock::now();
        }else if (quickSorts[i] == "QI1"){
          t1 = std::chrono::high_resolution_clock::now();
          exemplo.get_qi(1);
          t2 = std::chrono::high_resolution_clock::now();
        }else if (quickSorts[i] == "QI5"){
          t1 = std::chrono::high_resolution_clock::now();
          exemplo.get_qi(5);
          t2 = std::chrono::high_resolution_clock::now();
        }else if (quickSorts[i] == "QI10"){
          t1 = std::chrono::high_resolution_clock::now();
          exemplo.get_qi(10);
          t2 = std::chrono::high_resolution_clock::now();
        }else{
          break;
        }

        std::cout << "Depois: ";
        exemplo.print_array();

        elapsed_time = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << quickSorts[i] << " ";
        std::cout << types[j] << " ";
        std::cout << tamanhos[k] << " ";
        std::cout << elapsed_time.count() << std::endl;
      }
    }
  }

  // Array crescente(10);
  // Array decrescente(10);
  // Array aleatorio(10);
  // Array aleatorio2(10);

  // decrescente.desc_array();
  // aleatorio.shuffle_array();
  // aleatorio.get_qc();

  // crescente.print_array();
  // decrescente.print_array();
  // aleatorio.print_array();
  // aleatorio2.shuffle_array();
  // aleatorio2.print_array();

  // printf("\n");

  // aleatorio.print_array();

  // aleatorio2.get_qm3();
  // aleatorio2.print_array();

  // decrescente.get_qpe();
  // decrescente.print_array();

  return 0;
}
