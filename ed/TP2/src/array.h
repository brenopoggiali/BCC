#ifndef ARRAY_H_
#define ARRAY_H_
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

class Array{
  public:
    unsigned int* array;
    unsigned int size;
    unsigned long long int moves;
    unsigned long long int comparisons;

    Array(int size);

    void desc_array();
    void shuffle_array();


    unsigned int* get_array();
    unsigned int get_size();
    unsigned long long int get_moves();
    unsigned long long int get_comparisons();

    int which_pivot(unsigned int* A, int i, int j, int type);
    void quick_sort(unsigned int* A, int esq, int dir, int type, int k);
    void quick_sort_non_recursive(unsigned int* A, int esq, int dir);

    void get_qc();
    void get_qm3();
    void get_qpe();
    void get_qi(int k);
    void get_qnr();

    void set_element(int i, unsigned int element);
    int get_median();

    void print_array();
    ~Array();
};
#endif /* ARRAY_H_ */
