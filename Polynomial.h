#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include "Term.h"

class Polynomial{
private:
	unsigned int size;
	Term* first;
public:
	Polynomial();
	Polynomial(const Polynomial& p);
	~Polynomial();

	void pushTerm(int coef, int expt);
	int likeTerms(int coef, int expt);
	void popTerm(int coef);

	//Polynomial operator = (const Polynomial& p);
	Polynomial operator + (const Polynomial& p);
	Polynomial operator - (const Polynomial& p);

	bool isEmpty(){
		return size == 0 ? true : false;
	}

	unsigned int getSize(){
		return size;
	}

	void getData();
	//overloaded << operator for output
	friend std::ostream& operator << (std::ostream& out, const Polynomial& p){
		Term* t;
		for (t = p.first; t != 0; t = t->next){
			out << t->coefficient << "x^" << t->exponent << " + ";
		}
		return out;
	}
};


#endif