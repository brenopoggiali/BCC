#ifndef STACK_H_
#define STACK_H_

typedef struct {
  int left;
  int right;
} edges;

class Stack {
  private:
    edges *data;
    int stack_max;
    int top;
  public:
    Stack(int stack_max);     // Constructor

    void push(edges data);    // Push left and right in the top of the stack
    edges pop();              // Return last left and right
    bool is_empty();          // Return if Stack is empty

    ~Stack();                 // Destructor
};

#endif /* STACK_H_ */
