#include "posicao.h"
#include "excecoes.h"

    Posicao::Posicao(int x, int y):_x(x),_y(y){
    	_vazio = true;
    }

    bool Posicao::vazio(){
        return _vazio;
        
    }
	void Posicao::porPeca(){
	    _vazio = false;
	    
	}
	void Posicao::retirarPeca(){
	    _vazio = true;
	    
	}
	int Posicao::get_x(){
	    return _x;
	    
	}
	int Posicao::get_y(){
	    return _y;
	    
	}