#include <iostream>
#include <cstdlib>

#include "excecoes.h"
#include "posicao.h"
#include "tabuleiro.h"

using namespace std;

class Peca{
    protected:
        string _name;
        Posicao _p;
        Tabuleiro* _tabuleiro;
    
    private:
        Peca(string nome, int x, int y, Tabuleiro* t);
        void mover(int x, int y);
        bool valida_movimento(int x, int y);
        int get_x();
        int get_y();
        string get_nome();
        string get_posicao();
    
        virtual bool pode_mover(int x, int y) = 0;
};