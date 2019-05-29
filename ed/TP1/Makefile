all:
	g++ *.cpp -o main

tests:
	for i in $$(seq 1 6); do ./main < ./testes/$$i.in > ./testes/file$$i.out; done
	for i in $$(seq 1 6); do diff ./testes/$$i.out ./testes/file$$i.out; done
