#include <stdio.h>
#include <stdlib.h>
#include <gmp.h> 

//g = MDC(a,b), a*x + b*y = g
void mdc_estendido(mpz_t g, mpz_t x, mpz_t y, const mpz_t a, const mpz_t b){
	//calculate x and y
	if (mpz_cmp_ui(a, 0) == 0){
		mpz_set_ui(x, 0);
		mpz_set_ui(y, 1);
		return;
	}

	mpz_t(x1); mpz_init(x1);
	mpz_t(y1); mpz_init(y1);
	mpz_t(r); mpz_init(r);
	mpz_t(q); mpz_init (q);
	mpz_t(rop); mpz_init (rop);
	mpz_t(rop2); mpz_init (rop2);

	mpz_mod(r, b, a); // r = b%a

	mdc_estendido(g, x1, y1, r, a); // recursive

	mpz_fdiv_q(q, b, a);
	mpz_mul(rop, q, x1);

	//*x = y1 - (b/a) * x1;
	mpz_sub(x, y1, rop);
	//*y = x1;
	mpz_set(y, x1);

	mpz_mul(rop, a, x);
	mpz_mul(rop2, b, y);

	mpz_add(g, rop, rop2);

	mpz_clear (q);
	mpz_clear (r);
	mpz_clear (rop);
	mpz_clear (rop2);
	mpz_clear (x1);
	mpz_clear (y1);

	return;
}

// a*r is congruent to 1 (mod n)
int inverso_modular(mpz_t r, const mpz_t a, const mpz_t n){
    mpz_t(x);mpz_init(x);
    mpz_t(y);mpz_init(y);

    mdc_estendido(r,x,y,a,n);

    //if inverso modular is true (x is number that makes a*x = 1 (mod n))
    if(mpz_cmp_ui(r,1) == 0){
        //x = modular inverse of a mod n
        mpz_set(r,x); // r = x;
        if(mpz_sgn(r) == -1)
        	mpz_add(r, n, r);

        mpz_clear(x);
        mpz_clear(y);
        return 1;
    }
    else{
        mpz_clear(x);
        mpz_clear(y);
        return 0;
    }
}

//b^e is conguent to r (mond n)
void exp_binaria(mpz_t r, const mpz_t b, const mpz_t e, const mpz_t n){ 
    if(mpz_cmp_ui(e,1) == 0){
        mpz_mod(r,r,n);
    }
    else{
        mpz_mod(r,b,n);
        mpz_t mod; mpz_init(mod);
        mpz_t q; mpz_init(q);
        mpz_mod_ui(mod,e,2);
        if(mpz_cmp_ui(mod,0) == 0){
            mpz_fdiv_q_ui(q,e,2);
            exp_binaria(r,b,q,n);
            mpz_mul(r,r,r);
            mpz_mod(r,r,n);
            
        }
        else{
            mpz_fdiv_q_ui(q,e,2);
            exp_binaria(r,b,q,n);
            mpz_mul(r,r,r);
            mpz_mul(r,b,r);
            mpz_mod(r,r,n);
        }
        mpz_clear(mod);
        mpz_clear(q);
    }
}

//a^(n-1)=(2^t*q) is congruent to 1 (mod n)?? if it is -> inconclusive
int talvez_primo(const mpz_t a, const mpz_t n, const mpz_t n1, unsigned int t, const mpz_t q){
	
	if(mpz_cmp_si(n, 2) == -1){ // n < 2 
		return 0;
	}
	else if(mpz_cmp_si(n, 2) == 0){ // n == 2 
		return 1;
	}

	mpz_t(r); mpz_init(r);
	mpz_t(i); mpz_init(i);
	mpz_t(n1_var); mpz_init(n1_var);
	mpz_t(n1_mod_2); mpz_init(n1_mod_2);
	mpz_t(base); mpz_init(base);
	mpz_t (d); mpz_init(d);
    

    mpz_set_ui(d,2); // d = 2
	mpz_set(n1_var, n1); // n1_var = n1;
	mpz_mod_ui(n1_mod_2, n1_var, 2); // n1_mod_2 = n1_var%2
	mpz_mod(base, a, n); // base = a%n;
	
	if(mpz_cmp_si(n1_mod_2, 1) == 0){ // n == 2 
		return 0;
	}
	if (mpz_cmp(base, n) == 0 || mpz_cmp_ui(base, 0) == 0){
		mpz_set_ui(base, 2);
	}
	while(mpz_cmp_si(n1_mod_2, 0) == 0){ // n1_var % 2 == 0 (n1_var is even)
		t++;
		mpz_fdiv_q_ui(n1_var, n1_var, 2);
		mpz_mod_ui(n1_mod_2, n1_var, 2);
	}

	exp_binaria(r, base, n1_var, n); // r = (base)^(n1_var) (mod n)

	while(1){
		if((mpz_cmp_ui(i, 0) == 0 && mpz_cmp_ui(r, 1) == 0) || (mpz_cmp_ui(i, 0) >= 0 && mpz_cmp(r, n1) == 0)){
			mpz_clear(r);
			mpz_clear(i);
			mpz_clear(n1_var);
			mpz_clear(n1_mod_2);
			mpz_clear(base);
			mpz_clear(d);
			return 1;
		}
		
		mpz_add_ui(i, i, 1);
		exp_binaria(r, r, d, n);
		
		if (mpz_cmp_ui(i, t) >= 0){
			mpz_clear(r);
			mpz_clear(i);
			mpz_clear(n1_var);
			mpz_clear(n1_mod_2);
			mpz_clear(base);
			mpz_clear(d);
			return 0;
		}
	}
} 

void numero_aleatorio(mpz_t r, const mpz_t n, gmp_randstate_t rnd) {
	mp_bitcnt_t num_bits = mpz_sizeinbase(n, 2);
	do{
		mpz_urandomb(r, rnd, num_bits);
	}while (!(mpz_cmp_ui(r, 1) >= 0 && mpz_cmp(r, n) <= 0));
}

int provavelmente_primo(const mpz_t n, unsigned int iter, gmp_randstate_t rnd){
	mpz_t(n1); mpz_init(n1);
	mpz_t(base); mpz_init(base);
	mpz_t(q_aux); mpz_init(q_aux);

	mpz_sub_ui(n1, n, 1); // n1 = n-1;

	for (int i = 0; i < iter; ++i){
		numero_aleatorio(base, n, rnd);
		if(talvez_primo(base, n, n1, 0, q_aux) == 0){
			mpz_clear(n1);
			mpz_clear(base);
			mpz_clear(q_aux);
			return 0;
		}
	}
	mpz_clear(n1);
	mpz_clear(base);
	mpz_clear(q_aux);
	return 1;
}

void primo_aleatorio(mpz_t r, unsigned int b, gmp_randstate_t rnd){
	do{
		mpz_urandomb(r, rnd, b);
	}while(provavelmente_primo(r, 20, rnd) == 0);

	return;
}

int main(int argc, char const *argv[]){
	mpz_t(a); mpz_init(a);
	mpz_t(n); mpz_init(n);
	mpz_t(n1); mpz_init(n1);
	mpz_t(q); mpz_init(q);
	mpz_t(r); mpz_init(r);
	mpz_t(aux); mpz_init(aux);

	unsigned int t = 0;
	unsigned int iter, b;
	int maybe_primo;

	gmp_randstate_t (rnd);
	gmp_randinit_default(rnd);
	gmp_randseed_ui(rnd, 19416511);

	printf("Type the number a: ");
	gmp_scanf("%Zd", a);
	printf("Type the number n: ");
	gmp_scanf("%Zd", n);
	printf("Type the number iter: ");
	scanf("%i", &iter);
	printf("Type the number b: ");
	scanf("%i", &b);
	
	mpz_sub_ui(n1, n, 1); // n1 = n-1;
	mpz_set_ui(q, 1); // q = 1;	
	
	maybe_primo = talvez_primo(a, n, n1, t, q);
	
	printf("\n\nQuestion 1:\n");
	if (maybe_primo == 1){
		gmp_printf("The test with %Zd is inconclusive.\n", n);
	}
	else{
		gmp_printf("%Zd is definetly NOT prime.\n", n);
	}

	maybe_primo = provavelmente_primo(n, iter, rnd);
	printf("\n\nQuestion 2:\n");
	if (maybe_primo == 1){
		gmp_printf("The number %Zd is probably prime.\n", n);
	}
	else{
		gmp_printf("%Zd is definetly NOT prime.\n", n);
	}

	printf("\n\nQuestion 3:\n");
	if(b >= 2){
		primo_aleatorio(r, b, rnd);
		gmp_printf("The random prime number generated between 2 and 2^%i:  %Zd\n", b, r);
	}
	else if(b == 1){
		printf("The random prime number generated between 2 and 2^1: 2\n");
	}
	else{
		printf("'b' must be >= 2.\n");
	}


	mpz_clear(a);
	mpz_clear(n);
	mpz_clear(n1);
	mpz_clear(q);
	mpz_clear(r);
	mpz_clear(aux);
	return 0;
}
