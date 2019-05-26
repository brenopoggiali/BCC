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
