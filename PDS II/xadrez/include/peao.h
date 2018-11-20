#ifndef PEAO_H
#define PEAO_H

#include "peca.h"

class Peao: public Peca{
  public:
    Peao(int x, int y);
    bool pode_mover(int x, int y) override;
    void move(int x, int y) override;
    string getPeca() override;
    
    ~Peao();
};

#endif