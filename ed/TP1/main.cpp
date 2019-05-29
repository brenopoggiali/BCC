#include "lista_cursos.h"
#include "aluno.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void bubbleSort(Aluno *alunos, int n) { 
  Aluno temp;// = Aluno("", 0.0, 0, 0);
  for (int i = 0; i < n-1; i++){
    for (int j = 0; j < n-i-1; j++){
      if (alunos[j].get_nota() < alunos[j+1].get_nota()){
        temp = alunos[j];
        alunos[j] = alunos[j+1];
        alunos[j+1] = temp;
      }
    }
  }
}

int main(){

// BEGIN SET VARIABLES
  int quant_cursos, quant_alunos, quant_vagas;
  int opcao0, opcao1;
  float nota;
  string curso, nome;

// BEGIN SCAN FIRST LINE
  scanf("%i %i", &quant_cursos, &quant_alunos);
  string cursos[quant_cursos];
  int vagas[quant_cursos];
  
// BEGIN SET COURSES AND VAGAS ARRAYS
  for (int i = 0; i < quant_cursos; i++){ 
    cin.get();
    getline(cin, curso);
    cin >> quant_vagas;
    cursos[i] = curso;
    vagas[i] = quant_vagas;
  }

// BEGIN CREATE LIST ALL STUDENTS
  Aluno *alunos = new Aluno[quant_alunos];
  for (int i = 0; i < quant_alunos; ++i){
    cin.get();
    getline(cin, nome);
    cin >> nota;
    cin >> opcao0;
    cin >> opcao1;    
    alunos[i] = Aluno(nome, nota, opcao0, opcao1);
  }

  bubbleSort(alunos, quant_alunos);

// BEGIN LISTA CURSOS
  ListaCursos *lista_cursos = new ListaCursos[quant_cursos];
  for (int i = 0; i < quant_cursos; ++i){
    lista_cursos[i] = ListaCursos(cursos[i], vagas[i]);

  }

// BEGIN DISTRIBUICAO 1a opcao ALUNOS
  for (int i = 0; i < quant_alunos; ++i){
    int posicao = lista_cursos[alunos[i].get_opcao0()].size();
    lista_cursos[alunos[i].get_opcao0()].append(alunos[i]);
    alunos[i].set_classificacao_opcao0(posicao);
  }

// BEGIN DISTRIBUICAO 2a opcao ALUNOS
  for (int i = 0; i < quant_alunos; ++i){
    if(alunos[i].get_classificacao_opcao0() >= vagas[alunos[i].get_opcao0()]){
      lista_cursos[alunos[i].get_opcao1()].append(alunos[i]);
      int tamanho = lista_cursos[alunos[i].get_opcao1()].size();

      for (int j = tamanho-1; j >= 0; --j){
        if(lista_cursos[alunos[i].get_opcao1()].get_iesimo(j).get_nota() > lista_cursos[alunos[i].get_opcao1()].get_iesimo(j-1).get_nota()){
          Aluno j0 = lista_cursos[alunos[i].get_opcao1()].get_iesimo(j);

          Aluno temp = lista_cursos[alunos[i].get_opcao1()].get_iesimo(j-1);
          lista_cursos[alunos[i].get_opcao1()].set_iesimo(j-1, j0, -1);
          lista_cursos[alunos[i].get_opcao1()].set_iesimo(j, temp, 1);
        }
      }
    }
  }

// BEGIN IMPRIME LISTA FINAL
  for (int i = 0; i < quant_cursos; ++i){
    float nota_de_corte = 0.00;
    if(lista_cursos[i].size() >= vagas[i] )
      nota_de_corte = (lista_cursos[i].get_iesimo(vagas[i]-1)).get_nota();

    cout << cursos[i] << " " << setprecision(2) << fixed << nota_de_corte << endl;
    cout << "Classificados" << endl;
    for (int j = 0; j < lista_cursos[i].size(); ++j){
      if(j == vagas[i])
        cout << "Lista de espera" << endl;
      cout << (lista_cursos[i].get_iesimo(j)).get_nome() << " " << setprecision(2) << fixed << (lista_cursos[i].get_iesimo(j)).get_nota() << endl;
    }
    if(lista_cursos[i].size() <= vagas[i])
      cout << "Lista de espera" << endl;
   if (i != quant_cursos-1)
      cout << endl;
  }
  return 0;
}
