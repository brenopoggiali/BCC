#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

//check if p is prime
long long isPrime(long long p){

	long long i;
	double j;
	
	j = sqrt(p);


	for(i = 2; i <= j; i++){
		//if the number isn't prime
		if(p%i == 0)
			return 0;
	}

	//if is prime
	return 1;
}

//smallest number different than p and q that divides phi
long long chooseE(long long phi, long long p, long long q, long long n){

	long long i, e;
	for(i = 65537; i < phi; i++){

		if(phi%i != 0 && isPrime(i) && i != p && i != q){
			e = i;
			break;
		}
	}

	return e;
}

//calculate the quotient and rest of a division
void division(long long *rest, long long *quotient, long long a, long long b){

	if(a >= 0){

		*quotient = 0;
		*rest = a;

		while(*rest >= b){

			*rest -= b;
			*quotient = *quotient + 1;
		}
	}

}

//Calculate MDC and return the beta -> e^-1 (mod phi) = d
long long extendedMDC(long long a, long long b){
	
	long long rest, quotient, xB = 1, yB = 0, x = 0, y = 1, alpha, beta, phi;
	phi = a;

	rest = a;
	while(rest != 0){
		division(&rest, &quotient, a, b);
		a = b;
		b = rest;
		if(rest > 0){
			alpha = xB - quotient *x;
			beta = yB - quotient * y;

			xB = x;
			yB = y;
			x = alpha;
			y = beta;
		}
	}

	if(beta < 0)
		beta = phi + beta;

	return beta;

}

//Calculate the reduced form of a^e (mod n) 
long power(long long a, long long e, long long n){
	
	long long A = a, P = 1, E = e;
	
	while(1){

		//end of expansion -> return P
		if(E == 0)
			return P;

		//if E is odd 
		else if(E%2 != 0){
			//doing the expansion (mod n) of each one of the multiplications
			P = (A * P)%n;
			E = (E-1)/2;
		}

		//if E is even
		else{
			E = E/2;
		}
		
		A = (A*A)%n;
	}
	
}

//codify a string of char using the rest of a division a^e(mod n) for each character using ASCII table
int *codifica(char *message, long long e, long long n){
	
	long long i;
	int *messageC;

	messageC = malloc(500 * sizeof(long long));
	for(i = 0; i < 500; i++){
		messageC[i] = power(message[i], e, n);
	}

	return messageC;
}

//decodify a vector of int in a string of char using the rest of a division a^e(mod n) for each int
char *decodifica(int *messageC, long long d, long long n){
	
	long long i;
	char *message;

	message = malloc(500 * sizeof(char));
	
	for(i = 0; i < 500; i++){
		message[i] = power(messageC[i], d, n);
	}

	return message;
}

void gera_chaves(long long *n, long long *e, long long *d){
	// need to asign random number
	long long p = 773;
	while(isPrime(p) != 1){
		p = rand();
	}
	//need to asign random number
	long long q = 929;
	while(isPrime(q) != 1 || q == p){
		q = rand();
	}

	//Calculate n 
	*n = p * q;
	
	//calculate euler coficient
	long long phi = (p - 1)*(q - 1);

	//choose e for private key
	*e = chooseE(phi, p, q, *n);
	
	//choose d for public key
	*d = extendedMDC(phi, *e);	
}

int main(void){

	long long i;
	long long p, q, n, phi, e, d;

	//max number of char at message
	char message[500];
	int *messageC;


	//read message to be encrypted
	printf("\nType a message\n");
	
	//Limpa o buffer
	scanf("\n");
	fgets(message, 500, stdin);

	gera_chaves(&n, &e, &d);
	
	printf("\nPrivate key: (%llu, %llu)\n", e, n);
	printf("\nPublic key: (%llu, %llu)\n", d, n);

	//codify message
	messageC = codifica(message, e, n);
	
	//prints encrypted message
	printf("\nEncrypted message: ");

	for(i = 0; i < strlen(message); i++){
		printf("%c", messageC[i]);
	}
	printf("\n");	

	//decodify a message
	char *messageD;
	messageD = decodifica(messageC, d, n);

	printf("\nDecrypted message: %s\n\n", messageD);

	//free allocated memory
	free(messageC);
	free(messageD);
	return 0;

}