#include "torre.h"
#include"doctest.h"


TEST_CASE("Testando o Construtor")
{
	CHECK_THROWS(Torre r(-2, -4));
	CHECK_THROWS(Torre r(8, 8));
	CHECK_NOTHROW(Torre r(0, 0));
	CHECK_NOTHROW(Torre r(3, 4));
}
TEST_CASE("Testando getters")
{
	Torre r(3, 4);
	CHECK(r.get_x() == 3);
	CHECK(r.get_y() == 4);
}
TEST_CASE("Testando pode mover")
{
	Torre r(3, 4);
	CHECK_EQ(r.pode_mover(3, 4), false);
	CHECK_EQ(r.pode_mover(-3, 4), false);
	CHECK_EQ(r.pode_mover(3, 7), true);
	CHECK_EQ(r.pode_mover(5, 4), true);
}

TEST_CASE("Testando o movimento")
{
	Torre r(3, 4);
	CHECK_THROWS(r.move(3, 4));
	CHECK_THROWS(r.move(-3, 4));
	CHECK_NOTHROW(r.move(3, 7));
	CHECK_NOTHROW(r.move(5, 7));
}

TEST_CASE("Testando nome")
{
	Torre r(3, 4);
	CHECK(r.getPeca() == "♜");
}