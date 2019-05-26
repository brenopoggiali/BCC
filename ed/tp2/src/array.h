#ifndef ARRAY_H_
#define ARRAY_H_
#include <string>

using namespace std;

class Array{
  public:
    int* array;
    int size;

    Array(int size);
    int* get_array();
    int get_size();
    void desc_array();
    void shuffle_array();
    void print_array();
    ~Array();
};
#endif /* ARRAY_H_ */
