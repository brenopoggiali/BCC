.PHONY: clean

main:
	# Building server
	cd server; \
	mkdir -p build;
	cd server/src; \
	g++ -std=c++11 -I ../include *.cpp -o ../build/server -lpthread -fprofile-arcs -ftest-coverage -g -O0
	
	# Building client
	cd client; \
	mkdir -p build;
	cd client/src; \
	g++ -std=c++11 -I ../include *.cpp -o ../build/client -lpthread -fprofile-arcs -ftest-coverage -g -O0

all: main

run: main

test:
	cd build; \
	g++ -std=c++11 -I ../client/include -I ../server/include -I ../third_party/ ../program/tester.cpp ../tests/test_client.cpp -o  -lpthread --coverage -g -Wall -O3