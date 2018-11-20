#ifndef EXCECOES_H
#define EXCECOES_H

#include <stdexcept>

using namespace std;

class InvalidMovimentException : public exception{};
class InvalidPositionException: public exception{};
class MovimentoInvalidoException: public exception{};
class PosicaoSemPecaException: public exception{};
class PosicaoInexistente: public exception{};

#endif