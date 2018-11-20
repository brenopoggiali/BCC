#ifndef RAINHA_H
#define RAINHA_H

#include "peca.h"

class Rainha: public Peca{
  public:
    Rainha(int x, int y);
    bool pode_mover(int x, int y) override;
    void move(int x, int y) override;
    string getPeca() override;
    
    ~Rainha();
};

#endif