#include <stdio.h>
#include <time.h>       /* time */
#include "array.h"

using namespace std;


  Array::Array(int size){
    this->size = size;
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
    srand (time(NULL));
    for (int i = 0; i < this->size; ++i){
      /* generate secret number between 1 and 10: */
      this->array[i] = rand() % this->size;
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
  void Array::quick_sort(int* A, int esq, int dir, int type){
    int pivot, aux, i, j;
    i = esq;
    j = dir;
    pivot = which_pivot(A, i, j, type);  
    do{
      while (A[i] < pivot) i = i + 1;
      while (A[j] > pivot) j = j - 1;
      if(i <= j){
         aux = A[i];
         A[i] = A[j];
         A[j] = aux;
         i = i + 1;
         j = j - 1;
      }
    }while(j > i);
    if(esq < j) quick_sort(A, esq, j, type);
    if(i < dir) quick_sort(A, i, dir, type);   
  }
  void Array::get_qc(){
    quick_sort(this->array, 0, this->size-1, 1);
  }
  void Array::get_qm3(){
    quick_sort(this->array, 0, this->size-1, 2);
  }
  void Array::get_qpe(){
    quick_sort(this->array, 0, this->size-1, 3);
  }
  void Array::get_qi(int k){
    
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
  Array::~Array(){
    delete this->array;
  }
