#include <iostream>
#include <cassert>
#include "Term.h"
#include "Polynomial.h"

//ctor
Polynomial::Polynomial(){
	size = 0;
	first = NULL;
}

//copy ctor
Polynomial::Polynomial(const Polynomial& p){
	*this = p;
}

Polynomial::~Polynomial(){

}

//add terms to the polynomial
/*traverse the polynomial to check if any terms have 
the same variable exponent and if so, add the terms*/
void Polynomial::pushTerm(int coef, int expt){
	Term* t = new Term(coef, expt);
	Term* prev = first;			//store previous term
	//if coefficient is 0, exit, do not make new term
	if (coef == 0){
		return;
	}
	//if empty polynomial, t is first term
	if (isEmpty()){
		first = t;
	}
	else{	
		//if like terms were combined
		//don't make new term
		if (likeTerms(coef, expt) == 1){
			return;
		}
		else{
			//traverse polynomial to add new term
			while (prev->next != NULL){
				prev = prev->next;
			}
			t->next = NULL;
			prev->next = t;
		}
	}
	size++;
}

int Polynomial::likeTerms(int coef, int expt){
	Term* trav = first;

	//traverse through polynomial and compare exponents
	while (trav != NULL){
		if (expt == trav->exponent){
			//add coefficients if exponents are the same
			trav->coefficient = coef + trav->coefficient;
			//if by calculation, coefficient is 0, delete term
			if (trav->coefficient == 0){
				popTerm(0);
			}
			//'true'
			return 1;
		}
		else{
			trav = trav->next;
		}	
	}
	//if no sames are found, return 'false'
	return 0;
}

//term is popped/removed if the coefficient is 0
void Polynomial::popTerm(int coef){
	Term* t;
	Term* prev = NULL;
	
	//traverse polynomial with prev as previous node
	for (t = first; t != NULL; prev = t, t = t->next){
		if (t->coefficient == coef){
			if (prev == NULL){
				//fix first pointer
				t = t->next;
			}
			else{
				//skip removed node t
				prev->next = t->next;
			}
			delete t;
			size--;
			return;
		}	
	}	
}

//assignment operator
//Polynomial Polynomial::operator = (const Polynomial& p){
//	this->first = p.first;
//	return* this;
//}

//add two polynomials
/*traverse both polynomials and push all terms
into result polynomial*/
Polynomial Polynomial::operator + (const Polynomial& p){
	Polynomial* result = new Polynomial;
	Term* f = this->first;			//initial polynomial in storage
	Term* g = p.first;				//second polynomial as input

	while (f != NULL){
		//push initial polynomial terms into result polynomial
		result->pushTerm(f->coefficient, f->exponent);
		f = f->next;
	}

	while (g != NULL){	
		//push second polynomial terms into result
		result->pushTerm(g->coefficient, g->exponent);
		g = g->next;
	}

	return* result;		
}

//subtract the second polynomial from the first
/*negate all coeffecients of the second polynomial
then push them into the first*/
Polynomial Polynomial::operator - (const Polynomial& p){
	Polynomial* result = new Polynomial;
	Term* f = this->first;
	Term* g = p.first;

	while (f != NULL){
		//push initial polynomial terms into result polynomial
		result->pushTerm(f->coefficient, f->exponent);
		f = f->next;
	}

	while (g != NULL){
		//push second polynomial terms into result (negative coefficient)
		result->pushTerm(g->coefficient * (-1), g->exponent);
		g = g->next;
	}

	return* result;
}

//get user input
void Polynomial::getData(){
	int coefficient;
	int exponent;
	Polynomial f;
	bool quit = false;

	while (!quit){
		std::cout << "enter integer value of the first exponent (highest degree): ";
		std::cin >> exponent;

		std::cout << "enter integer value of its coefficient: ";
		std::cin >> coefficient;

		f.pushTerm(coefficient, exponent);

		std::cout << "enter to continue, q to quit: ";
		std::cin >> quit;
	}
}
