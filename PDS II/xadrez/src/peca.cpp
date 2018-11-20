#include "peca.h"
#include "excecoes.h"

Peca::Peca(int x, int y){
    if((x < 0) || (x > 7) || (y < 0) || (y > 7)){
        throw PosicaoInexistente();
    }
    this->_x = x;
    this->_y = y;
}

int Peca::get_x(){
    return this->_x;
}

int Peca::get_y(){
    return this->_y;
}

void Peca::set_x(int x){
    this->_x = x;
}
void Peca::set_y(int y){
    this->_y = y;
}

Peca::~Peca() {}