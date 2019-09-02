all:
	g++ *.cpp -o main

tests:
	for i in $$(seq 1 5); do ./main < ./testes/$$i.in > ./testes/file$$i.out; done
	for i in $$(seq 1 5); do diff ./testes/$$i.out ./testes/file$$i.out; done
	for i in $$(seq 1 5); do rm ./testes/file$$i.out; done
