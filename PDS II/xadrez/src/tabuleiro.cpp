#include "tabuleiro.h"
#include "rei.h"
#include "rainha.h"
#include "bispo.h"
#include "peao.h"
#include "torre.h"
#include "cavalo.h"
#include"excecoes.h"

#include <iostream>

Tabuleiro::Tabuleiro(){
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            tabuleiro.emplace_back(new Posicao(j,i));
        }
    }
    
    /*WHITE*/
        //peoes brancos
        int i=0; 
        while(i<8){
            _pecas[tabuleiro[i+8]] = new Peao(i,1);
            ++i;
        }
        //white towers
        i=0;
        while(i<8){
            _pecas[tabuleiro[i]] = new Torre(i,0);
            i+=7;
        }
         //white horses
        i=1;
        while(i<8){
            _pecas[tabuleiro[i]] = new Cavalo(i,0);
            i+=5;
        }
        //white bishop
        i=2;
        while(i<8){
            _pecas[tabuleiro[i]] = new Bispo(i,0);
            i += 3;
        }
        //white queen and king
        i = 0;
        while(i < 1){
            _pecas[tabuleiro[3]] = new Rainha(3,0); 
            _pecas[tabuleiro[4]] = new Rei(4,0);
            i++;
        }
        for(int t=0; t<16; t++) {
            tabuleiro[t]->porPeca();
        }
    /*BLACK*/    
        //peoes pretos
        i=0; 
        while(i<8){
            _pecas[tabuleiro[i+48]] = new Peao(i,6);
            ++i;
        }
        //black tower
        i=0;
        while(i<8){
            _pecas[tabuleiro[i+56]] = new Torre(i,7);
            i+=7;
        }
        //black horses
        i=1;
        while(i<8){
            _pecas[tabuleiro[i+56]] = new Cavalo(i,7);
            i+=5;
        }
        //black bishops
        i=2;
        while(i<8){
            _pecas[tabuleiro[i+56]] = new Bispo(i,7);
            i += 3;
        }
        //black queen and king
        i = 0;
        while(i < 1){
            _pecas[tabuleiro[60]] = new Rainha(4,7);
            _pecas[tabuleiro[59]] = new Rei(3,7);
            i++;
        }
        for(int t=48; t<64; t++) {
            tabuleiro[t]->porPeca();
        }
}   


void Tabuleiro::move(Posicao a, Posicao b) {
    Posicao *aux;
    for(int i = 0; i < 64; i++){
        aux = tabuleiro[i];
        if(a.get_x()== aux->get_x() && a.get_y()== aux->get_y())
            break;
    }

    if(!(aux->vazio())) {
        if((_pecas[aux]->pode_mover(b.get_x(),b.get_y())) && (b.vazio())) {
            _pecas[aux]->move(b.get_x(),b.get_y());
            a.retirarPeca();
            b.porPeca();
        }else {
            throw MovimentoInvalidoException();
        }
    } else {
        throw PosicaoSemPecaException();
    }
}
