#include "../include/bispo.h"
#include"doctest.h"



TEST_CASE("Testando o Construtor"){
	CHECK_THROWS(Bispo r(-2, -4));
	CHECK_THROWS(Bispo r(8, 8));
	CHECK_NOTHROW(Bispo r(0, 0));
	CHECK_NOTHROW(Bispo r(3, 4));
}

TEST_CASE("Testando getters"){
	Bispo r(3, 4);
	CHECK(r.get_x() == 3);
	CHECK(r.get_y() == 4);
}

TEST_CASE("Testando pode mover"){
	Bispo r(3, 4);
	CHECK_EQ(r.pode_mover(3, 4),false);
	CHECK_EQ(r.pode_mover(-1, -1),false);
	CHECK_EQ(r.pode_mover(5, 3),false);
	CHECK_EQ(r.pode_mover(4, 5), true);
}

TEST_CASE("Testando falhas no movimento"){
	Bispo r(3, 4);
	CHECK_THROWS(r.move(3, 4));
	CHECK_THROWS(r.move(-1, -1));
	CHECK_THROWS(r.move(5, 3));
	CHECK_NOTHROW(r.move(4, 5));
}

TEST_CASE("Testando nome"){
	Bispo r(3, 4);
	CHECK_EQ(r.getPeca(), "♝");
}