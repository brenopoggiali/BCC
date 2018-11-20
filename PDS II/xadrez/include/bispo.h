#ifndef BISPO_H
#define BISPO_H

#include "peca.h"

class Bispo: public Peca{
  public:
    Bispo(int x, int y);
    bool pode_mover(int x, int y) override;
    void move(int x, int y) override;
    string getPeca() override;
    
    ~Bispo();
};

#endif