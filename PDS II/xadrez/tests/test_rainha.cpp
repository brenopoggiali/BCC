#include "../include/rainha.h"
#include"doctest.h"


TEST_CASE("Testando o Construtor")
{
	CHECK_THROWS(Rainha r(-2, -4));
	CHECK_THROWS(Rainha r(8, 8));
	CHECK_NOTHROW(Rainha r(0, 0));
	CHECK_NOTHROW(Rainha r(3, 4));
}
TEST_CASE("Testando getters")
{
	Rainha r(3, 4);
	CHECK(r.get_x() == 3);
	CHECK(r.get_y() == 4);
}
TEST_CASE("Testando pode mover")
{
	Rainha r(3, 4);
	CHECK_EQ(r.pode_mover(3, 4), false);
	CHECK_EQ(r.pode_mover(-5, 4), false);
	CHECK_EQ(r.pode_mover(5, 5), false);
	CHECK_EQ(r.pode_mover(4, 4), true);
	CHECK_EQ(r.pode_mover(3, 5), true);
	CHECK_EQ(r.pode_mover(4, 5), true);
}

TEST_CASE("Testando o movimento")
{
	Rainha r(3, 4);
	CHECK_THROWS(r.move(3, 4));
	CHECK_THROWS(r.move(-5, 4));

	CHECK_NOTHROW(r.move(4, 4));
	CHECK_NOTHROW(r.move(4, 6));
	CHECK_NOTHROW(r.move(5, 5));

	CHECK_THROWS(r.move(1, 6));
}
TEST_CASE("Testando nome")
{
	Rainha r(3,4);
	CHECK_EQ(r.getPeca(), "♛");
}