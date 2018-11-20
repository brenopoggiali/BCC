#include "excecoes.h"
#include "torre.h"

Torre::Torre(int x, int y) : Peca(x, y){}

bool Torre::pode_mover(int x, int y){
    return ((x-_x == 0 || y-_y == 0) && (y <= 7 && y >= 0 && x <= 7 && x >= 0) && (x-_x != 0 || y-_y != 0));
}

void Torre::move(int x, int y){
    if(y > 7 || y < 0 || x > 7 || x < 0){
		throw PosicaoInexistente(); 
	} else if((this->get_x() == x) && (this->get_y() != y)){
		this->set_y(y);
	} else if((this->get_x() != x) && (this->get_y() == y)){
		this->set_x(x);
	} else {
		throw MovimentoInvalidoException();
	}
}

string Torre::getPeca(){
    return "♜";
}

Torre::~Torre(){} 