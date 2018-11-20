#ifndef TORRE_H
#define TORRE_H

#include "peca.h"

class Torre : public Peca{

  public:
    Torre(int x, int y, Tabuleiro* t);
    virtual bool pode_mover(int x, int y);
};

#endif
