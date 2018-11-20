#include "excecoes.h"
#include "peao.h"

Peao::Peao(int x, int y) : Peca(x, y){}

bool Peao::pode_mover(int x, int y){
	if(y > 7 || y < 0 || x > 7 || x < 0){
		return false;
	} else if(this->get_x() == x && this->get_y() == y){
		return false;
	} else if( x != this->get_x()){
		return false;
	} else if(y-this->get_y() <= 0){
		return false;
	} else if(y-this->get_y() >= 3){
		return false;
	}
	return true;
}

void Peao::move(int x, int y){
    if(y > 7 || y < 0 || x > 7 || x < 0){
		throw PosicaoInexistente(); 
	} else if(this->get_x() == x && this->get_y() == y){
		throw MovimentoInvalidoException(); 
	} else if( x != this->get_x()){
		throw MovimentoInvalidoException();
	} else if(y-this->get_y() <= 0){
		throw MovimentoInvalidoException(); 
	} else if(y-this->get_y() >= 3){
		throw MovimentoInvalidoException(); 
	} 
	this->set_y(y);
}

string Peao::getPeca(){
    return "♟";
}

Peao::~Peao(){} 