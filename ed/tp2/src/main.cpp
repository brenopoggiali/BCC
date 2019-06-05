#include "array.h"
#include <chrono>
#include <string>
#include <stdio.h>
#include <iostream>

int main(int argc, char const *argv[]){
  // printf("%s\n", *argv);
  int n, moves, comparisons;
  long long microseconds;
  std::chrono::high_resolution_clock::time_point start;
  std::chrono::high_resolution_clock::time_point end;
  std::chrono::duration<double, std::micro> elapsed_time;

  string types[3] = {"Ale", "OrdC", "OrdD"};
  string quickSorts[7] = {"QC", "QM3", "QPE", "QI1", "QI5",
                          "QI10", "QNR"};
  int tamanhos[10] = {50000, 100000, 150000, 200000, 250000,
                      300000, 350000, 400000, 450000, 500000};

  for (int i = 0; i < 7; ++i){
    for (int j = 0; j < 3; ++j){
      for (int k = 0; k < 10; ++k){
        double *median_time = new double[21];
        for (int t = 0; t < 1; ++t){
          Array exemplo(tamanhos[k]);
          comparisons = 0;
          moves = 0;
          // Get array type
          if(types[j] == "Ale") exemplo.shuffle_array();
          else if(types[j] == "OrdD") exemplo.desc_array();

          // Get quickSort
          if (quickSorts[i] == "QC"){
            start = std::chrono::high_resolution_clock::now();
            exemplo.get_qc();
            end = std::chrono::high_resolution_clock::now();
          }else if (quickSorts[i] == "QM3"){
            start = std::chrono::high_resolution_clock::now();
            exemplo.get_qm3();
            end = std::chrono::high_resolution_clock::now();
          }else if (quickSorts[i] == "QPE"){
            start = std::chrono::high_resolution_clock::now();
            exemplo.get_qpe();
            end = std::chrono::high_resolution_clock::now();
          }else if (quickSorts[i] == "QI1"){
            start = std::chrono::high_resolution_clock::now();
            exemplo.get_qi(1);
            end = std::chrono::high_resolution_clock::now();
          }else if (quickSorts[i] == "QI5"){
            start = std::chrono::high_resolution_clock::now();
            exemplo.get_qi(5);
            end = std::chrono::high_resolution_clock::now();
          }else if (quickSorts[i] == "QI10"){
            start = std::chrono::high_resolution_clock::now();
            exemplo.get_qi(10);
            end = std::chrono::high_resolution_clock::now();
          }else{
            break;
          }

          elapsed_time = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
          median_time[t] = elapsed_time.count();
          comparisons = exemplo.get_comparisons();
          moves = exemplo.get_moves();
          // std::cout << median_time[t] << " - ";
          // std::cout << median_time[t]*1000 << std::endl;
        }
        // median_time.print_array();
        // median_time.get_qc();
        // median_time.print_array();
        std::cout << quickSorts[i] << " ";
        std::cout << types[j] << " ";
        std::cout << tamanhos[k] << " ";
        std::cout << comparisons << " ";
        std::cout << moves << " ";
        std::cout << median_time[0] << std::endl;
      }
    }
  }

  return 0;
}
