#include "stack.h"
#include <iostream>


Stack::Stack(int stack_max) {       // Constructor
  this->top = 0;
  this->stack_max = stack_max;
  this->data = new edges[this->stack_max];
}
void Stack::push(edges d) {
  data[top].left = d.left;
  data[top].right = d.right;
  this->top++;
}
edges Stack::pop() {
  top--;
  return this->data[this->top];
}
bool Stack::is_empty(){
  return (this->top == 0);
}
Stack::~Stack() {             // Destructor
  delete [] data;
}
