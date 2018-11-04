#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function return MDC between a and b
int MDC(int a, int b){
	if (b == 0)
		return a;
	else
		return MDC(b, a%b);
}
//Function return aux that b^e is congruent to aux (mod n)
int exp_binaria(int b, int e, int n){ 
    int aux = 1;

    b = b%n;

    while(e>0){
    	//e = odd
    	if (e%2 == 1){
    		aux = (aux*b)%n;
    	}

    	//e = even
    	e /= 2;
    	b = (b*b)%n;
    }

    return aux;
}
//a^n-1 is congruent to 1 (mod n)??
int talvez_primo(const int a, const int n, const int n1, unsigned int t, const int q){
		if (n < 2){
			return 0;
		}
		if (n == 2){
			return 1;
		}
		int aux1 = a;
		if (a > n){
			aux1 = 2;
		}

		int aux2 = 0;
		srand(time(NULL));
		
		for (int i = 0; i < 50; ++i){
			if (MDC(aux1,n) != 1)
				return 0;
			if(exp_binaria(aux1, n1, n) != 1)
				return 0;
			aux1 = 2 + rand()%(n-4); 
		}

		return 1;
	}

int main(int argc, char const *argv[]){
	
	int a, n, n1, q;
	unsigned int t;
	int aux;

	printf("Type the number a: ");
	scanf("%i", &a);
	printf("Type the number n: ");
	scanf("%i", &n);
	
	n1 = n-1;
	t = 1;
	q = 1;	



	aux = talvez_primo(a, n, n1, t, q);
	if (aux == 1){
		printf("It's highly probable that %i is prime.\n", n);
	}
	else{
		printf("%i is definetely NOT prime.\n", n);
	}
	
	return 0;
}