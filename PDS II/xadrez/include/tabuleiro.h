#ifndef TABULEIRO_H
#define TABULEIRO_H

#include <vector>
#include <map>

#include "peca.h"
#include "peao.h"
#include "rainha.h"
#include "bispo.h"
#include "cavalo.h"
#include "torre.h"
#include "rei.h"
#include "posicao.h"

class Tabuleiro{
  map<string, map<Posicao, Peca*>> _pecas;

  public:
    Tabuleiro();
    bool pode_mover(Posicao& p);

    ~Tabuleiro();
};

#endif