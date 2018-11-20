#ifndef REI_H
#define REI_H

#include "peca.h"

class Rei : public Peca{

  public:
    Rei(int x, int y, Tabuleiro* t);
    virtual bool pode_mover(int x, int y);
};

#endif