#include <stdio.h>
#include <stdlib.h>

//Question 1
int MDC(int a, int b){
	if (b == 0)
		return a;
	else
		return MDC(b, a%b);
}
int mdc_estendido(int g, int *x, int *y, const int a, const int b){
	//calculate x and y
	if (a == 0){
		*x = 0;
		*y = 1;
		return b;
	}

	int x1, y1;
	int mdc = mdc_estendido(g, &x1, &y1, b%a, a);

	*x = y1 - (b/a) * x1;
	*y = x1;

	return mdc;
}
int mpz_gcd(int g, int a, int b){
	//check if mdc of a and b is = g
	if (MDC(a,b) == g)
		return 1;
	else
		0;
}
void mpz_gcdext(int g, int x, int y, const int a, const int b){

}

//Question 2
int inverso_modular(int *r, const int a, const int n){
	for (int i = 0; i < n; ++i){
		if((a*i)%n == 1){
			*r = i;
			return 1;
		}
	}
	return 0;
}

//Question 3
int exp_binaria(int r, const int b, const int e, const int n){
    if(e == 0)
        return 1;
    else if(e == 1)
        return b%n;
    else if(e%2 == 0)
        return exp_binaria(r,b*b, e/2, n);
    else
        return (b*exp_binaria(r, b*b, ((e-1)/2), n));
}



int main(int argc, char const *argv[]){
	int a, b, e, g, n, r, x, y;

	printf("Digite o numero a: ");
	scanf("%i", &a);
	printf("Digite o numero b: ");
	scanf("%i", &b);
	printf("Digite o numero e: ");
	scanf("%i", &e);
	printf("Digite o numero n: ");
	scanf("%i", &n);

	r = a % b;

// Question 1
	g = MDC(a,b);

	printf("The equation that we're looking for is: \n");
	g = mdc_estendido(g, &x, &y, a, b);
    printf("%i*%i + %i*%i = %i", a, x, b, y, g);

//Question 2
    printf("\n\nExiste inverso modular: %i\n", inverso_modular(&r, a, n));
    printf("r = %i\n\n", r);

//Question 3
    r = exp_binaria(r, b, e, n);
    printf("O numero r que procuramos: %i", r);
	return 0;
}
