#include <stdio.h>
#include "lista_cursos.h"

using namespace std;

/*
   append(int)                 . Insere um elemento no fim da lista.
   get_iesimo(int)             . Retorna um elemento na posição i.
   set_iesimo(int, Aluno, dif) . Altera um elemento na posicao i e sua classificacao.
   get_nota_de_corte()         . Retorna nota de corte do curso.
   get_vagas()                 . Retorna vagas do curso.
   size()                      . Retorna o tamanho da lista.
*/

  ListaCursos::ListaCursos(){
    _inicio = nullptr;
    _fim    = nullptr;
    _num_elementos_inseridos = 0;
  }
  ListaCursos::ListaCursos(string nome, int vagas){
    _inicio = nullptr;
    _fim    = nullptr;
    _num_elementos_inseridos = 0;
    nome = this->nome;
    vagas = this->vagas;
    nota_de_corte = 0.00;
  }

  void ListaCursos::append(Aluno elemento){
    node_t *atual   = new node_t;
    atual->elemento = elemento;
    atual->proximo  = nullptr;
    atual->anterior = nullptr;
    if(_inicio == nullptr){
        _inicio = atual;
        _fim    = atual;
    }
    else{
        _fim->proximo   = atual;
        atual->anterior = _fim;
        _fim            = atual;
    }
    _num_elementos_inseridos++;
    if(this->size() >= this->vagas)
      nota_de_corte = this->get_iesimo(vagas-1).get_nota();
    else
      nota_de_corte = 0.00;
  }
  
  Aluno ListaCursos::get_iesimo(int i){
    node_t *atual;
    atual = _inicio;
    for(int j=0; j < i || atual == nullptr; ++j){
        atual = atual->proximo;
    }
    if (atual == nullptr){
        return Aluno("", 0.0, 0, 0);
    }
    return atual->elemento;
  }
  void ListaCursos::set_iesimo(int i, Aluno aluno, int dif){
    node_t *atual;
    atual = _inicio;
    for(int j=0; j < i || atual == nullptr; ++j){
        atual = atual->proximo;
    }
    aluno.dif_classificacao_opcao0(dif);
    atual->elemento = aluno;
  }
  float ListaCursos::get_nota_de_corte(){
    return nota_de_corte;
  }
  int ListaCursos::get_vagas(){
    return vagas;
  }
  int ListaCursos::size(){
    return _num_elementos_inseridos;
  }
  
  ListaCursos::~ListaCursos(){
      node_t *anterior = nullptr;
      node_t *proximo  = _inicio;
      while(proximo != nullptr){
          anterior = proximo;
          proximo  = proximo->proximo;
          delete anterior;
      }
  }
