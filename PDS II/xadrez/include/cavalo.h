#ifndef CAVALO_H
#define CAVALO_H

#include "peca.h"

class Cavalo: public Peca{
  public:
    Cavalo(int x, int y);
    bool pode_mover(int x, int y) override;
    void move(int x, int y) override;
    string getPeca() override;
    
    ~Cavalo();
};

#endif