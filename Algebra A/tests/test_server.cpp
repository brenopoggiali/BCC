#include "server.h"
#include "user.h"
#include "doctest.h"

TEST_CASE("Test Server Constructor"){
	CHECK_NOTHROW(TCPserver s(5555));
} 