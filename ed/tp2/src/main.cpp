#include "array.h"
#include <chrono>
#include <string>
#include <stdio.h>
#include <iostream>
#include<cmath>

bool is_number(const std::string& str){
    std::string::const_iterator it = str.begin();
    while (it != str.end() && std::isdigit(*it)) ++it;
    return !str.empty() && it == str.end();
}

int main(int argc, char const *argv[]){
  int n;
  long long microseconds;
  unsigned long long int moves, comparisons;
  std::chrono::high_resolution_clock::time_point start;
  std::chrono::high_resolution_clock::time_point end;
  std::chrono::duration<double, std::micro> elapsed_time;

  Array *exemplo;
  Array *median_time;
  unsigned int **all_examples;
  unsigned int *vector;

  if(argc > 1 && (argc < 4 || argc > 5)){
    std::cout << "ERROR! Incorrect number of params." << std::endl;
    exit(1);
  }else if(argc == 1) {

    string types[3] = {"Ale", "OrdC", "OrdD"};
    string quickSorts[7] = {"QC", "QM3", "QPE", "QI1", "QI5",
                            "QI10", "QNR"};
    int tamanhos[10] = {50000, 100000, 150000, 200000, 250000,
                        300000, 350000, 400000, 450000, 500000};

    for (int i = 0; i < 7; ++i){
      for (int j = 0; j < 3; ++j){
        for (int k = 0; k < 10; ++k){
          median_time = new Array(20);
          comparisons = 0;
          moves       = 0;
          for (int t = 0; t < 20; ++t){
            exemplo = new Array(tamanhos[k]);
            // Get array type
            if(types[j] == "Ale") exemplo->shuffle_array();
            else if(types[j] == "OrdD") exemplo->desc_array();

            // Get quickSort
            if (quickSorts[i] == "QC"){
              start = std::chrono::high_resolution_clock::now();
              exemplo->get_qc();
              end = std::chrono::high_resolution_clock::now();
            }else if (quickSorts[i] == "QM3"){
              start = std::chrono::high_resolution_clock::now();
              exemplo->get_qm3();
              end = std::chrono::high_resolution_clock::now();
            }else if (quickSorts[i] == "QPE"){
              start = std::chrono::high_resolution_clock::now();
              exemplo->get_qpe();
              end = std::chrono::high_resolution_clock::now();
            }else if (quickSorts[i] == "QI1"){
              start = std::chrono::high_resolution_clock::now();
              exemplo->get_qi(1);
              end = std::chrono::high_resolution_clock::now();
            }else if (quickSorts[i] == "QI5"){
              start = std::chrono::high_resolution_clock::now();
              exemplo->get_qi(5);
              end = std::chrono::high_resolution_clock::now();
            }else if (quickSorts[i] == "QI10"){
              start = std::chrono::high_resolution_clock::now();
              exemplo->get_qi(10);
              end = std::chrono::high_resolution_clock::now();
            }else if (quickSorts[i] == "QNR") {
              start = std::chrono::high_resolution_clock::now();
              exemplo->get_qnr();
              end = std::chrono::high_resolution_clock::now();
            } else {
              break;
            }


            elapsed_time = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
            median_time->set_element(t, static_cast<unsigned int>(elapsed_time.count()));
            comparisons += exemplo->get_comparisons();
            moves += exemplo->get_moves();
            delete exemplo;
          }
          std::cout << quickSorts[i] << " ";
          std::cout << types[j] << " ";
          std::cout << tamanhos[k] << " ";
          std::cout << comparisons/20 << " ";
          std::cout << moves/20 << " ";
          std::cout << median_time->get_median() << std::endl;
          delete median_time;
        }
      }
    }
  }else{
    std::string quickSort = argv[1];
    std::string type = argv[2];
    int size;
    bool print = false;
    if (!is_number(argv[3])) {
      std::cout << "ERROR! 3rd argument must be an integer" << std::endl;
      exit(1);
    } else {
      size = atoi(argv[3]);
    }
    if (size < 0) {
      std::cout << "ERROR! 3rd argument must be >= 0";
      exit(1);
    }
    if(argc == 5) {
      std::string last_argument = argv[4];
      if((last_argument == "-p")){
          print = true;;
      } else {
          std::cout << "ERROR: 4th argument must be empty or equal '-p'" << std::endl;
          exit(1);
      }
    }
    all_examples = new unsigned int*[20];
    vector       = new unsigned int[size];
    median_time  = new Array(20);
    comparisons  = 0;
    moves        = 0;
    for (int k = 0; k < 20; ++k){
      exemplo = new Array(size);
      all_examples[k] = new unsigned int[size];
      // Get array type
      if(type == "OrdC");
      else if (type == "OrdD") exemplo->desc_array();
      else if (type == "Ale") exemplo->shuffle_array();
      else {
        std::cout << "ERROR! 2nd argument must be in ['OrdC', 'OrdD', 'Ale']";
        exit(1);
      }
      for (int i = 0; i < size; ++i){
        all_examples[k][i] = exemplo->get_array()[i];
      }
      // Get quickSort
      if (quickSort == "QC"){
        start = std::chrono::high_resolution_clock::now();
        exemplo->get_qc();
        end = std::chrono::high_resolution_clock::now();
      }else if (quickSort == "QM3"){
        start = std::chrono::high_resolution_clock::now();
        exemplo->get_qm3();
        end = std::chrono::high_resolution_clock::now();
      }else if (quickSort == "QPE"){
        start = std::chrono::high_resolution_clock::now();
        exemplo->get_qpe();
        end = std::chrono::high_resolution_clock::now();
      }else if (quickSort == "QI1"){
        start = std::chrono::high_resolution_clock::now();
        exemplo->get_qi(1);
        end = std::chrono::high_resolution_clock::now();
      }else if (quickSort == "QI5"){
        start = std::chrono::high_resolution_clock::now();
        exemplo->get_qi(5);
        end = std::chrono::high_resolution_clock::now();
      }else if (quickSort == "QI10"){
        start = std::chrono::high_resolution_clock::now();
        exemplo->get_qi(10);
        end = std::chrono::high_resolution_clock::now();
      }else if (quickSort == "QNR") {
        start = std::chrono::high_resolution_clock::now();
        exemplo->get_qnr();
        end = std::chrono::high_resolution_clock::now();
      } else {
        std::cout << "ERROR! 1st argument must be in ['QC', 'QMC', 'QPE', 'QI1', 'QI5', 'QI10', 'QNR']";
        exit(1);
      }

      elapsed_time = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
      median_time->set_element(k, static_cast<unsigned int>(elapsed_time.count()));
      comparisons += exemplo->get_comparisons();
      moves += exemplo->get_moves();
      delete exemplo;
    }
    std::cout << quickSort << " ";
    std::cout << type << " ";
    std::cout << size << " ";
    std::cout << comparisons/20 << " ";
    std::cout << moves/20 << " ";
    std::cout << median_time->get_median() << std::endl;
    delete median_time;
    if(print){
      for (int i = 0; i < 20; ++i){
        for (int j = 0; j < size; ++j){
          std::cout << all_examples[i][j] << " ";
        }
        std::cout << std::endl;
      }
    }
    delete [] all_examples;
    delete [] vector;
  }
  return 0;
}
