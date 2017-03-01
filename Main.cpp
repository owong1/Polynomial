#include <iostream>
#include "Polynomial.h"

using namespace std;

int main(){
	Polynomial f;
	Polynomial g;
	f.pushTerm(11, 2);
	f.pushTerm(6, 1);
	f.pushTerm(0, 1);		//should be ignored
	f.pushTerm(8, 3);
	
	g.pushTerm(2, 2);
	g.pushTerm(8, 3);

	cout << "f(x) = " << f << endl;
	cout << "g(x) = " << g << endl;

	cout << "f(x) + g(x) = " << f + g << endl;
	cout << "f(x) - g(x) = " << f - g << endl;
	
	//keep .exe window open
	getchar();
	return 0;
}