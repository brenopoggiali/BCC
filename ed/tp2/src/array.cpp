#include <stdio.h>
#include "array.h"

using namespace std;


  Array::Array(int size){
    this->size = size;
    this->moves = 0;
    this->comparisons = 0;
    this->array = new int[this->size];

    for (int i = 0; i < this->size; ++i){
      this->array[i] = i;
    }
  }
  int* Array::get_array(){
    return this->array;
  }
  int Array::get_size(){
    return this->size;
  }
  void Array::desc_array(){
    int size = this->size;
    for (int i = 0; i < size; ++i){
      int posicao = size - i -1;
      this->array[posicao] = i;
    }
  }
  void Array::shuffle_array(){
  /* initialize random seed: */
    auto now = std::chrono::system_clock::now();
    auto now_ms = std::chrono::time_point_cast<std::chrono::microseconds>(now);
    auto value = now_ms.time_since_epoch();
    long duration = value.count();
    srand (duration);
    for (int i = 0; i < this->size; ++i){
      /* generate secret number between 1 and 10: */
      this->array[i] = rand() % this->size;
    }
  }
  void Array::quick_sort(int* A, int esq, int dir, int type, int k){
    int pivot, aux, i, j;
    i = esq;
    j = dir;
    if (k==0 || dir-esq+1 < this->size*k*0.01){
      pivot = which_pivot(A, esq, dir, type);
      do{
        while (A[i] < pivot){ i++; this->comparisons++;}
        this->comparisons++;
        while (A[j] > pivot){ j--; this->comparisons++;}
        this->comparisons++;
        if(i <= j){
           aux = A[i];
           A[i] = A[j];
           A[j] = aux;
           i++; j--;
           this->moves++;
        }
      }while(j > i);
      if(esq < j) quick_sort(A, esq, j, type, k);
      if(i < dir) quick_sort(A, i, dir, type, k);
    }else{
      for (j = 1; j < this->size; j++){
          i = j-1;
          pivot = which_pivot(A, i, j, 2);
          while ((i >= 0) && (A[i] > pivot)){
              A[i+1] = A[i];
              i--;
              this->moves++;
              this->comparisons++;
          }
          if(i>=0){
            this->comparisons++;
          }
          A[i+1] = pivot;
          this->moves++;
      }
    }
  }
  int Array::which_pivot(int* A, int i, int j, int type){
    /*
      1 = QC
      2 = QM3
      3 = QPE
    */
    switch(type){
      case 1:
        return(A[(i+j)/2]);
      case 2:
        int esq, meio, dir;
        esq = A[i]; meio = A[(i+j)/2]; dir = A[j];
        if( (esq>dir && esq<meio) || (esq<dir && esq>meio) ){
          return(esq);
        }
        else if( (meio<esq && meio>dir) || (meio>esq && meio<dir) ){
          return(meio);
        }
        else{
          return(dir);
        }
      case 3:
        return(A[i]);
    }
  }
  void Array::get_qc(){
    quick_sort(this->array, 0, this->size-1, 1, 0);
  }
  void Array::get_qm3(){
    quick_sort(this->array, 0, this->size-1, 2, 0);
  }
  void Array::get_qpe(){
    quick_sort(this->array, 0, this->size-1, 3, 0);
  }
  void Array::get_qi(int k){
    quick_sort(this->array, 0, this->size-1, 2, k);
  }
  void Array::get_nr(){
  }
  void Array::print_array(){
    for (int i = 0; i < this->size; ++i){
      if (i != this->size-1){
        printf("%i, ", this->array[i]);
      }
      else{
        printf("%i\n", this->array[i]);
      }
    }
  }
  unsigned int Array::get_moves(){
    return this->moves;
  }
  unsigned int Array::get_comparisons(){
    return this->comparisons;
  }
  Array::~Array(){
    delete this->array;
  }
