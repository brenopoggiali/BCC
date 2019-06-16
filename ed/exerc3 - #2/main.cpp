#include <iostream>

using namespace std;


void print_array(int *matricula, int n){
  for (int i = 0; i < n; ++i){
    cout << matricula[i] << " ";
  }
  cout << endl;
}

void bolha(int *v, int n) {
  int i, j, aux;
  for (int i = 0; i < n-1; ++i){
    for (int j = 1; j < n-i; ++j){
      if (v[j] < v[j-1]) {
        aux = v[j];
        v[j] = v[j-1];
        v[j-1] = aux;
      }
    }
    cout << "[i = " << i << "] ";
    print_array(v, n);
  }
}

void selecao(int *v, int n) {
  int i, j, min, aux;
  for (i = 0; i < n - 1; i++) {
    min = i;
    for (j = i + 1 ; j < n; j++) {
      if (v[j] < v[min]) min = j;
    }
    aux = v[min];
    v[min] = v[i];
    v[i] = aux;
    cout << "[i = " << i << "] ";
    print_array(v, n);
  }
}

void insercao(int *v, int n) {
  int i,j, aux;
  for (i = 1; i < n; i++) {
    aux = v[i];
    j = i - 1;
    while (( j >= 0 ) && (aux < v[j])) {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = aux;
    cout << "[i = " << i << "] ";
    print_array(v, n);
  }
}

void Particao(int Esq, int Dir, int *i, int *j, int *A){
  int x, w;
  *i = Esq; *j = Dir;
  x = A[(*i + *j)/2]; /* obtem o pivo x */
  cout << "pivot = " << x << "; ";
  do{
    while (x > A[*i]) (*i)++;
    while (x < A[*j]) (*j)--;
    if (*i <= *j) {
      w = A[*i]; A[*i] = A[*j]; A[*j] = w;
      (*i)++; (*j)--;
    }
  } while (*i <= *j);
}

void Ordena(int Esq, int Dir, int *A){
  int i, j;
  Particao(Esq, Dir, &i, &j, A);
  cout << "subvector = ";
  for (int k = Esq; k < Dir; ++k){
    cout << A[k] << " ";
  }
  cout << endl;
  if (Esq < j) Ordena(Esq, j, A);
  if (i < Dir) Ordena(i, Dir, A);
}
void QuickSort(int *A, int n){
  Ordena(0, n-1, A);
}

void MAX_HEAPIFY(int a[], int i, int n) {
  int l,r,largest,loc;
  l=2*i;
  r=(2*i+1);
  if((l<=n)&&a[l]>a[i])
    largest=l;
  else
    largest=i;
  if((r<=n)&&(a[r]>a[largest]))
    largest=r;
  if(largest!=i) {
    loc=a[i];
    a[i]=a[largest];
    a[largest]=loc;
    MAX_HEAPIFY(a, largest,n);
  }
}
void BUILD_MAX_HEAP(int a[], int n) {
  for(int k = n/2; k >= 1; k--) {
    MAX_HEAPIFY(a, k, n);
  }
}
void Heapsort(int a[], int n) {

  BUILD_MAX_HEAP(a,n);
  int i, temp;
  for (i = n; i >= 2; i--) {
    temp = a[i];
    a[i] = a[1];
    a[1] = temp;
    MAX_HEAPIFY(a, 1, i - 1);
    cout << "[iteration " << n-i << "] ";
    print_array(a, n);
  }
}
int main(int argc, char const *argv[]){

  int n = 10;

  int A[10] = { 2, 0, 1, 8, 0, 5, 4, 8, 0, 0 };
  cout << "Bubble sort: " << endl;
  bolha(A, n);

  int B[10] = { 2, 0, 1, 8, 0, 5, 4, 8, 0, 0 };
  cout << "\nSelection sort: " << endl;
  selecao(B, n);

  int C[10] = { 2, 0, 1, 8, 0, 5, 4, 8, 0, 0 };
  cout << "\nInsertion sort: " << endl;
  insercao(C, n);

  int D[10] = { 2, 0, 1, 8, 0, 5, 4, 8, 0, 0 };
  cout << "\nQuick sort: " << endl;
  QuickSort(D, n);

  int E[11] = { 0, 2, 0, 1, 8, 0, 5, 4, 8, 0, 0 };
  cout << "\nHeap sort: " << endl;
  Heapsort(E, n);

  return 0;
}
