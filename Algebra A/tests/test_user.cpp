#include "user.h"
#include "doctest.h"

TEST_CASE("Test User Constructor"){
	CHECK_NOTHROW(User u());
} 