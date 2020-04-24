all:
	g++ -std=c++14 *.cpp -o tp3

tests:
	for i in $$(seq 1 20); do ./tp3 ./testes/input/$$i.in > ./testes/file$$i.out; done
	for i in $$(seq 1 20); do diff ./testes/output/$$i.out ./testes/file$$i.out; done
	for i in $$(seq 1 20); do rm ./testes/file$$i.out; done
