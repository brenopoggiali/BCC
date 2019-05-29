#include "message.h"
#include "client.h"
#include "doctest.h"

TEST_CASE("Test Message Methods"){
	TCPserver(5555);
	Client c("127.0.0.1", 5555, "client1", "channel_name");
	CHECK_NOTHROW(Message(c.send_msg('Teste_Nothrow')));
}