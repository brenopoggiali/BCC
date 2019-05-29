#ifndef ALUNO_H_
#define ALUNO_H_
#include <string>

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

class Aluno{
  public:
    string nome;
    float nota;
    int opcao0;
    int opcao1;
    int classificacao;

    Aluno();
    Aluno(string nome, float nota, int opcao0, int opcao1);
    string get_nome();
    float get_nota();
    int get_opcao0();
    int get_opcao1();
    int get_classificacao_opcao0();
    void dif_classificacao_opcao0(int dif);
    void set_classificacao_opcao0(int classificacao);
    ~Aluno();
};
#endif /* ALUNO_H_ */
