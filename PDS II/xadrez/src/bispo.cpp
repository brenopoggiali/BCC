#include "excecoes.h"
#include "bispo.h"

Bispo::Bispo(int x, int y) : Peca(x, y){}

bool Bispo::pode_mover(int x, int y){
    return (((abs(x) - _x) == (abs(y) - _y)) && (y <= 7 && y >= 0 && x <= 7 && x >= 0) && x-_x != 0);
}

void Bispo::move(int x, int y){
    if(this->get_x() == x && this->get_y() == y){
		throw MovimentoInvalidoException(); 
	} else if(y > 7 || y < 0 || x > 7 || x < 0){
		throw new PosicaoInexistente(); 
	} else if((this->get_x() - x) != (this->get_y() - y) && (this->get_x() - x) != ((this->get_y() - y))*(-1)){
		throw MovimentoInvalidoException();
	}
	this->set_x(x);
	this->set_y(y);
}

string Bispo::getPeca(){
    return "♝";
}

Bispo::~Bispo(){} 