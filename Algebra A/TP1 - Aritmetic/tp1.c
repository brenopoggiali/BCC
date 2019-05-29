#include <stdio.h>
#include <stdlib.h>
#include <gmp.h> 

//Question 1
void mdc_estendido(mpz_t g, mpz_t x, mpz_t y, const mpz_t a, const mpz_t b){
	//calculate x and y
	if (mpz_cmp_ui(a, 0) == 0){
		mpz_set_ui(x, 0);
		mpz_set_ui(y, 1);
		return; // return b in int
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

	return; //return mdc; in int
}



//Question 2
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


//Question 3
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



int main(int argc, char const *argv[]){
	mpz_t(a); mpz_init(a);
	mpz_t(b); mpz_init(b);
	mpz_t(e); mpz_init(e);
	mpz_t(g); mpz_init(g);
	mpz_t(n); mpz_init(n);
	mpz_t(r); mpz_init(r);
	mpz_t(x); mpz_init(x);
	mpz_t(y); mpz_init(y);


	printf("Type the number a: ");
	gmp_scanf("%Zd", a);
	printf("Type the number b: ");
	gmp_scanf("%Zd", b);
	printf("Type the number e: ");
	gmp_scanf("%Zd", e);
	printf("Type the number n: ");
	gmp_scanf("%Zd", n);

	mpz_mod(r, a, b); //r = a % b;

// Question 1
	

	printf("\nQuestion 1: GCD of 'a' and 'b' for is: \n");
	mdc_estendido(g, x, y, a, b);
    gmp_printf("%Zd*%Zd + %Zd*%Zd = %Zd \t where the result is our GCD\n\n", a, x, b, y, g);

//Question 2
	if(inverso_modular(r, a, n) == 1){
		printf("Question 2: \nModular Multiplicative Inverse DOES exists! :D\n");
		gmp_printf("r = %Zd\n\n", r);
	}
	else{
		printf("Question 2: \nModular Multiplicative Inverse DOES NOT exists :(\n\n");
	}

//Question 3
    exp_binaria(r, b, e, n);
    gmp_printf("Question 3: \nThe r number that we're looking that made b^e congruent to r (mod n): %Zd\n\n", r);
  
    mpz_clear(a);
	mpz_clear(b);
	mpz_clear(e);
	mpz_clear(g);
	mpz_clear(n);
	mpz_clear(r);
	mpz_clear(x);
	mpz_clear(y);

	return 0;
}
