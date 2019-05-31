#include "array.h"
#include <stdio.h>
#include <time.h>
#include <stdio.h>
#include <iostream>
#include <chrono>

using namespace std::chrono;

int main(int argc, char const *argv[]){
  printf("%s\n", *argv);
  int tamanhos[10] = {50000, 100000, 150000, 200000, 250000,
                      300000, 350000, 400000, 450000, 500000};
  string quickSorts[7] = {"QC", "QM3", "QPE", "QI1", "QI5",
                          "QI10", "QNR"};
  string types[3] = {"Ale", "OrdC", "OrdD"};
  for (int i = 0; i < 7; ++i){
    for (int j = 0; j < 1; ++j){
      for (int k = 0; k < 1; ++k){
        high_resolution_clock::time_point t1 = high_resolution_clock::now();

        Array teste(20);
        teste.shuffle_array();
        cout << quickSorts[i] << " " << types[j] << " " << tamanhos[k];
        teste.get_qc();
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        duration<double, std::micro> elapsed_time = duration_cast<duration<double>>(t2 - t1);
        cout << " " << elapsed_time.count() << endl;
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
