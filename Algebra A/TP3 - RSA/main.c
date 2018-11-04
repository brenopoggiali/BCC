#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

int geranerate_random_prime1(){
	srand(time(NULL));
	int p = rand()%32740;

	while(talvez_primo(2, p, p-1, 1, 1) != 1){
		p = rand()%32740;
	}

	return p;
}

int geranerate_random_prime2(){
	srand(time(NULL));
	int q = 11 + rand()%32730;

	while(talvez_primo(2, q, q-1, 1, 1) != 1){
		q = 11 + rand()%32730;
	}

	return q;
}

void gera_chaves(double *n, double *e, double *d){
	//2 random primes between [2, 32740)	
	int p = geranerate_random_prime1();
	int q = geranerate_random_prime2();


	//public key
	*n = p*q;
	int phi = (p-1)*(q-1);
	while(*e < phi){
		if(MDC(*e, phi) == 1){
			break;
		}
		else
			*e += 1 ;
	}

	//private key
	//k -> arbitrary
	int k = 2;
	//d -> d*e = 1 + k*phi
	*d = (1 + (k*phi))/ *e;
}

int main(int argc, char const *argv[]){
	double n=2, e=65537, d=2;

	gera_chaves(&n, &e, &d);

	printf("n = p*q = %.0lf\n", n);
	printf("e = public key = %.0lf\n", e);
	printf("d = private key = %.0lf\n", d);

	return 0;
}