#include "../include/tabuleiro.h"
#include"doctest.h"



TEST_CASE("Testando o Construtor")
{
	CHECK_NOTHROW(Tabuleiro tab());
}

TEST_CASE("Testando move")
{
	Posicao a(0, 1);
	Posicao b(0, 2);
	Tabuleiro tabu;
	CHECK_NOTHROW(tabu.move(a,b));
}

TEST_CASE("Testando move trow") 
{
	Posicao a(0, 0);
	Posicao b(1, 1);
	Tabuleiro tabu;
	CHECK_THROWS(tabu.move(a,b));

}
TEST_CASE("Testando move no trow")
{
	Posicao a(1, 3);
	Posicao b(1, 1);
	Tabuleiro tabu;
	CHECK_THROWS(tabu.move(a,b));

}
