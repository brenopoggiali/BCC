#ifndef PDS2_PECA_H
#define PDS2_PECA_H

#include <iostream>
#include <cstdlib>

#include "excecoes.h"
#include "posicao.h"

using namespace std;

class Tabuleiro;

class Peca{
    protected:
        int _x;
        int _y;
    
    public:
        Peca(int x, int y);
        virtual void move(int x, int y) = 0;
        virtual string getPeca() = 0;
        virtual bool pode_mover(int x, int y) = 0;
        int get_x();
        int get_y();
        void set_x(int x);
        void set_y(int y);
        
        
        
        virtual ~Peca();
};

#endif