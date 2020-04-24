all:
	g++ *.cpp -o tp1

tests:
	for i in $$(seq 1 11); do ./tp1 ./testes/input/inp$$i.txt > ./testes/file$$i.out; done
	for i in $$(seq 1 11); do diff ./testes/output/out$$i.txt ./testes/file$$i.out; done
	for i in $$(seq 1 11); do rm ./testes/file$$i.out; done
