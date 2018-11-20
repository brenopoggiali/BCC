#include "excecoes.h"
#include "rainha.h"

Rainha::Rainha(int x, int y) : Peca(x, y){}

bool Rainha::pode_mover(int x, int y){
    return ((abs(x)-_x == abs(y)-_y || (abs(x)-_x == 0 || abs(y)-_y == 0)) && (y <= 7 && y >= 0 && x <= 7 && x >= 0) && (abs(x)-_x != 0 || abs(y)-_y != 0));
}

void Rainha::move(int x, int y){
    if(this->get_x() == x && this->get_y() == y){
		throw MovimentoInvalidoException(); 
	} else if(y > 7 || y < 0 || x > 7 || x < 0){
		throw PosicaoInexistente(); 
	} else if(abs(this->get_x() - x) == abs(this->get_y() - y)){
		this->set_x(x);
		this->set_y(y);
	} else if((this->get_x() == x) && (this->get_y() != y)){
		this->set_y(y);
	} else if((this->get_y() == y) && (this->get_x() != x)){
		this->set_x(x);
	} else throw MovimentoInvalidoException(); 
}

string Rainha::getPeca(){
    return "♛";
}

Rainha::~Rainha(){} 