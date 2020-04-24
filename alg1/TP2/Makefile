all:
	g++ -std=c++14 *.cpp -o tp2

tests:
	for i in $$(seq 1 4); do ./tp2 ./testes/input/exemplo$$i.txt > ./testes/file$$i.out; done
	for i in $$(seq 1 4); do diff ./testes/output/saida_exemplo$$i.txt ./testes/file$$i.out; done
	for i in $$(seq 1 4); do rm ./testes/file$$i.out; done
