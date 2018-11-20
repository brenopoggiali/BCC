#include "excecoes.h"
#include "rei.h"

Rei::Rei(int x, int y) : Peca(x, y){}

bool Rei::pode_mover(int x, int y){
    return ((abs(x)-_x < 2 && abs(y)-_y < 2) && (y <= 7 && y >= 0 && x <= 7 && x >= 0) && (abs(x)-_x != 0 || abs(y)-_y != 0));
}

void Rei::move(int x, int y){
    if((this->get_x() == x) && (this->get_y() == y)){
		throw MovimentoInvalidoException(); 
	} else if(y > 7 || y < 0 || x > 7 || x < 0){
		throw PosicaoInexistente(); 
	} else if(( (abs(this->get_x() - x)) == 1 ) || ((abs(this->get_y() - y)) == 1)){
		this->set_y(y);
		this->set_x(x);
	} else {
		throw MovimentoInvalidoException(); 
	}
}

string Rei::getPeca(){
    return "♔";
}

Rei::~Rei(){} 