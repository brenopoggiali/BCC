#ifndef REI_H
#define REI_H

#include "peca.h"

class Rei: public Peca{
  public:
    Rei(int x, int y);
    bool pode_mover(int x, int y) override;
    void move(int x, int y) override;
    string getPeca() override;
    
    ~Rei();
};

#endif