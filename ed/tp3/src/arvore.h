#include <string>

#ifndef AlphabetMorseTree_H_
#define AlphabetMorseTree_H_

/*

CreateAlphabetTree():       Construtor da Árvore-dicionário para código morse
insert(char, std::string):  insere um elemento na árvore de acordo com o seu código
search(std::string):        procura um elemento na árvore a partir de um código
print_tree():               chama a função que imprime a árvore usando o caminhamento pré ordem e passando a raíz
print_preorder(node*):      imprime o caminhamento pré ordem do nó que ela recebe recursivamente
tree_destroyer(node*):      destroi o nó que ela recebe recursivamente
~AlphabetMorseTree():       chama a função que destroi a árvore passando a raíz.

*/

struct node {
  node* left;
  node* right;
  char value;
  std::string code;
};

class AlphabetMorseTree {
  private:
    node *root;
    void print_preorder(node*);
    void tree_destroyer(node*);
  public:
    AlphabetMorseTree();     // Constructor

    void CreateAlphabetTree();
    void insert(char, std::string);
    void search(std::string);
    void print_tree();

    ~AlphabetMorseTree();    // Destructor
};

#endif /* AlphabetMorseTree_H_ */
