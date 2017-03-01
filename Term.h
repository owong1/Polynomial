#ifndef TERM_H
#define TERM_H

class Term{
public:
	Term(int coef, int expt){
		coefficient = coef;
		exponent = expt;
		next = NULL;
	}
	int coefficient;
	int exponent;

	Term* next;
};

#endif