#include "server.h"
#include "client.h"
#include "user.h"
#include "exception.h"
#include "doctest.h"

TEST_CASE("Test Exceptions in TCPserver"){
	CHECK_NOTHROW(TCPserver s(5555));
	try{
		TCPserver s2(5555);
	}
	catch(std::exception &e){
		CHECK_EQ(e.what() == "Port already in use");
	}
}
TEST_CASE("Test Exceptions in Client"){
	TCPserver s(5555);
	CHECK_NOTHROW(Client c("127.0.0.1", 5555, "client1", "channel_name"));
	try{
	 Client c1("127.0.0.1", 5555, "client1", "channel_name");
	}
	catch(std::exception &e){
		CHECK_EQ(e.what() == "Nickname already in use");
	}
}