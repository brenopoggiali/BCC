#include "excecoes.h"
#include "cavalo.h"

Cavalo::Cavalo(int x, int y) : Peca(x, y){}

bool Cavalo::pode_mover(int x, int y){
    return ((abs(x) - _x == 2 && abs(y) - _y == 1) || (abs(x) - _x == 1 && abs(y) - _y == 2)) && (y <= 7 && y >= 0 && x <= 7 && x >= 0);
}

void Cavalo::move(int x, int y){
    if(this->get_x() == x && this->get_y() == y){
		throw MovimentoInvalidoException();
	} else if(y > 7 || y < 0 || x > 7 || x < 0){
		throw PosicaoInexistente(); 
	} else if((abs(this->get_x() - x) == 1) && (abs(this->get_y() - y) == 2)){
		this->set_x(x);
		this->set_y(y);
	} else if((abs(this->get_x() - x) == 2) && (abs(this->get_y() - y) == 1)){
		this->set_x(x);
		this->set_y(y);
	} else {
		throw MovimentoInvalidoException(); 
	}
}

string Cavalo::getPeca(){
    return "♞";
}

Cavalo::~Cavalo(){} 