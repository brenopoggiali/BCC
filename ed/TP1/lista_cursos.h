#ifndef LISTA_CURSOS_H_
#define LISTA_CURSOS_H_
#include <string>
#include "aluno.h"

using namespace std;

/*
   append(int)                 . Insere um elemento no fim da lista.
   get_iesimo(int)             . Retorna um elemento na posição i.
   set_iesimo(int, Aluno, dif) . Altera um elemento na posicao i e sua classificacao.
   get_nota_de_corte()         . Retorna nota de corte do curso.
   get_vagas()                 . Retorna vagas do curso.
   size()                      . Retorna o tamanho da lista.
*/

// template <class T> 
struct node_t {
  Aluno elemento;
  node_t *proximo;
  node_t *anterior;
};

// template <class T>
class ListaCursos{
private:
  // node_t<T> *_inicio;
  node_t *_inicio;
  node_t *_fim;
  string nome;
  int vagas;
  int _num_elementos_inseridos;
  float nota_de_corte;
public:
  ListaCursos();
  ListaCursos(string nome, int vagas);
  void append(Aluno elemento);
  Aluno get_iesimo(int i);
  void set_iesimo(int i, Aluno aluno, int dif_classificacao);
  float get_nota_de_corte();
  int get_vagas();
  int size();
  ~ListaCursos();
};
#endif /* LISTA_CURSOS_H_ */
