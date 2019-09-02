#include <iostream>
#include <string>
#include "arvore.h"

int main(int argc, char const *argv[]){
  std::string first_argument;
  AlphabetMorseTree dict;

  if (argc == 2){
    first_argument = argv[1];
    if (first_argument != "-a") {
      std::cout << "ERROR! First parementer must be '-a' or empty." << std::endl;
      exit(3);
    }
  }

  if(argc > 2){
    std::cout << "ERROR! Incorrect number of params." << std::endl;
    exit(2);
  } else{
    /* Insere entrada manualmente e visualiza no próprio terminal (finalizada com 'fim' ou 'Ctrl+D')
        OU
       Recebe entrada e a decodifica imprimindo no terminal ou fora.
    */
    char bip;
    bool first_line = true;
    std::string line;
    std::string letter_in_morse= "";
    while (getline(std::cin, line)) {
      if (line == "fim")
        break;

      if(first_line) first_line = false;
      else std::cout << std::endl;

      for (int i = 0; i < line.length(); ++i) {
        bip = line[i];
        if (letter_in_morse == "/") {
          std::cout << " ";
          letter_in_morse = "";
        } else if (bip == ' ') {
          dict.search(letter_in_morse);
          letter_in_morse = "";
        } else {
          letter_in_morse += bip;
        }
      }
      dict.search(letter_in_morse);
      letter_in_morse = "";
    }

    if (first_argument == "-a"){
      /* Adição do caminhamento em pré-ordem da árvore de pesquisa */
      dict.print_tree();
    }
  }

  return 0;
}
