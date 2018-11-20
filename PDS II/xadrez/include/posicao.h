#ifndef POSICAO_H
#define POSICAO_H

#include"peca.h"

class Posicao{
    private:
        int _x;
        int _y;
        bool _vazio;
    public:
        Posicao(int x, int y);
        bool vazio();
        void porPeca();
        void retirarPeca();
        int get_x();
        int get_y();
};

#endif