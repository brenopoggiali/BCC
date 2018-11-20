#include "../include/rei.h"
#include"doctest.h"

TEST_CASE("Testando o Construtor")
{
	CHECK_THROWS(Rei r(-2, -4));
	CHECK_THROWS(Rei r(8, 8));
	CHECK_NOTHROW(Rei r(0, 0));
	CHECK_NOTHROW(Rei r(3, 4));
}

TEST_CASE("Testando getters")
{
	Rei r(3, 4);
	CHECK(r.get_x() == 3);
	CHECK(r.get_y() == 4);
}

TEST_CASE("Testando pode mover")
{
	Rei r(3, 4);
	CHECK_EQ(r.pode_mover(-1, 5), false);
	CHECK_EQ(r.pode_mover(3, 4), false);
	CHECK_EQ(r.pode_mover(6, 4), false);
	CHECK_EQ(r.pode_mover(4, 5), true);
}

TEST_CASE("Testando o movimento")
{
	Rei r(3, 4);
	CHECK_THROWS(r.move(3, 4));
	CHECK_THROWS(r.move(-1, 4));
	CHECK_THROWS(r.move(5, 4));
	CHECK_NOTHROW(r.move(4, 5));
}
TEST_CASE("Testando nome")
{
	Rei r(3, 4);
	CHECK(r.getPeca() == "♔");
}