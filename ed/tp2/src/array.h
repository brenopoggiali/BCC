#ifndef ARRAY_H_
#define ARRAY_H_
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

class Array{
  public:
    int* array;
    int size;
    unsigned int moves;
    unsigned int comparisons;

    Array(int size);

    void desc_array();
    void shuffle_array();


    int* get_array();
    int get_size();
    unsigned int get_moves();
    unsigned int get_comparisons();

    int which_pivot(int* A, int i, int j, int type);
    void quick_sort(int* A, int esq, int dir, int type, int k);

    void get_qc();
    void get_qm3();
    void get_qpe();
    void get_qi(int k);
    void get_nr();

    void print_array();
    ~Array();
};
#endif /* ARRAY_H_ */
