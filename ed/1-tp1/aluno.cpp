#include <stdio.h>
#include <math.h>
#include "aluno.h"

using namespace std;

/*
  string get_nome(): Retorna o nome do Aluno.
  float get_nota(): Retorna a nota do Aluno.
  int get_opcao0(): Retorna a opcao0 do Aluno.
  int get_opcao1(): Retorna a opcao1 do Aluno.
  int get_classificacao_opcao0(): Retorna a classificação do Aluno em sua opcao0.
  void dif_classificacao_opcao0(int dif): Altera a classificacao do aluno em sua opção 0.
  void set_classificacao_opcao0(int classificacao): Define a classificacao de um aluno em sua opcao 0.
*/

  Aluno::Aluno(){
    nome = "";
    nota = 0;
    opcao0 = 0;
    opcao1 = 0;
  }
  Aluno::Aluno(string nome, float nota, int opcao0, int opcao1){
    this->nome = nome;
    this->nota = nota;
    this->opcao0 = opcao0;
    this->opcao1 = opcao1;
    this->classificacao = 0;
  };
  string Aluno::get_nome(){
    return nome;
  }
  float Aluno::get_nota(){
    return nota;
  }
  int Aluno::get_opcao0(){
    return opcao0;
  }
  int Aluno::get_opcao1(){
    return opcao1;
  }
  int Aluno::get_classificacao_opcao0(){
    return classificacao;
  }
  void Aluno::dif_classificacao_opcao0(int dif){
    this->classificacao =this->classificacao - dif;
  }
  void Aluno::set_classificacao_opcao0(int classificacao){
    this->classificacao = classificacao;
  }
  Aluno::~Aluno(){}
