#ifndef PEAO_H
#define PEAO_H

#include "peca.h"

class Peao : public Peca{

  public:
    Peao(int x, int y, Tabuleiro* t);
    virtual bool pode_mover(int x, int y);
};

#endif
