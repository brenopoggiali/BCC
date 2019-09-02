#include "arvore.h"
#include <iostream>
#include <string>
#include <fstream>

/*

CreateAlphabetTree():       Construtor da Árvore-dicionário para código morse
insert(char, std::string):  insere um elemento na árvore de acordo com o seu código
search(std::string):        procura um elemento na árvore a partir de um código
print_tree():               chama a função que imprime a árvore usando o caminhamento pré ordem e passando a raíz
print_preorder(node*):      imprime o caminhamento pré ordem do nó que ela recebe recursivamente
tree_destroyer(node*):      destroi o nó que ela recebe recursivamente
~AlphabetMorseTree():       chama a função que destroi a árvore passando a raíz.

*/

AlphabetMorseTree::AlphabetMorseTree() {
  root = new node;
  root->value = '\0';
  root->code = "";
  root->left = NULL;
  root->right = NULL;
  CreateAlphabetTree();
}

void AlphabetMorseTree::CreateAlphabetTree() {
  char value;
  std::ifstream morse("morse.txt");
  std::string str, sequence;
  while(std::getline(morse, str)) {
    value = str[0];
    sequence = "";
    for(int i = 2; i < str.length(); i++) {
      sequence += str[i];
    }
    insert(value, sequence);
  }
}

void AlphabetMorseTree::insert(char value, std::string code) {
  node **side = &root;
  for (int i = 0; i < code.length(); i++) {
    if(code[i] == '.') {
      side = &((*side)->left);
    } else {
      side = &((*side)->right);
    }
    if(*side == NULL) {
      *side = new node;
      (*side)->value = '\0';
      (*side)->code = "";
      (*side)->left = NULL;
      (*side)->right = NULL;
    }
  }
  (*side)->value = value;
  (*side)->code = code;
}

void AlphabetMorseTree::search(std::string code) {
  node **side = &root;
  for (int i = 0; i < code.length(); i++) {
    if(code[i] == '.') {
      side = &((*side)->left);
    } else {
      side = &((*side)->right);
    }
  }
  std::cout << (*side)->value;
  return;
}

void AlphabetMorseTree::print_tree() {
  std::cout << std::endl << std::endl;
  print_preorder(root);
}

void AlphabetMorseTree::print_preorder(node* side) {
    if (side == NULL) return;
    if(side->value)
      std::cout << side->value << " " << side->code << std::endl;
    print_preorder(side->left);
    print_preorder(side->right);
}

void AlphabetMorseTree::tree_destroyer(node* side){
  if (side) {
    tree_destroyer(side->left);
    tree_destroyer(side->right);
    delete side;
  }
}

AlphabetMorseTree::~AlphabetMorseTree() {
  tree_destroyer(root);
}
