#ifndef TORRE_H
#define TORRE_H

#include "peca.h"

class Torre: public Peca{
  public:
    Torre(int x, int y);
    bool pode_mover(int x, int y) override;
    void move(int x, int y) override;
    string getPeca() override;
    
    ~Torre();
};

#endif