#include "../include/cavalo.h"
#include"doctest.h"

TEST_CASE("Testando o Construtor")
{
	CHECK_THROWS(Cavalo r(-2, -4));
	CHECK_THROWS(Cavalo r(8, 8));
	CHECK_NOTHROW(Cavalo r(0, 0));
	CHECK_NOTHROW(Cavalo r(3, 4));
}
TEST_CASE("Testando getters")
{
	Cavalo r(3, 4);
	CHECK(r.get_x() == 3);
	CHECK(r.get_y() == 4);
}

TEST_CASE("Testando pode mover")
{
	Cavalo r(3, 4);
	CHECK_EQ(r.pode_mover(4, 6), true);
	CHECK_EQ(r.pode_mover(5, 5), true);
	CHECK_EQ(r.pode_mover(-1, 5), false);
	CHECK_EQ(r.pode_mover(3, 4), false);
	//CHECK(r.pode_mover(5, 3));
	// CHECK(r.pode_mover(2, 6));
	// CHECK(r.pode_mover(4, 6));
}

TEST_CASE("Testando falhas no movimento")
{
	Cavalo r(3, 4);
	CHECK_THROWS(r.move(3, 4));
	CHECK_THROWS(r.move(-1, 5));
	CHECK_NOTHROW(r.move(5, 5));
	CHECK_NOTHROW(r.move(4, 3));
	CHECK_THROWS(r.move(6, 6));
	//CHECK(r.pode_mover(5, 3));
	// CHECK(r.pode_mover(2, 6));
	// CHECK(r.pode_mover(4, 6));
}


TEST_CASE("Testando nome")
{
	Cavalo r(3, 4);
	CHECK(r.getPeca() == "♞");
}