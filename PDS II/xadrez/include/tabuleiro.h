#ifndef TABULEIRO_H
#define TABULEIRO_H

#include <vector>
#include <map>

#include "posicao.h"

using namespace std;


class Tabuleiro{
    private:
        map<Posicao*, Peca *> _pecas;
        vector<Posicao*> tabuleiro;

    public:
        Tabuleiro();
        void move(Posicao a, Posicao b);
        /*void inicializa_pecas();
        
        ~Tabuleiro();*/
};

#endif