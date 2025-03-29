#include <iostream>
#include "complex.hpp"

using namespace std;


int main(void) 
{
	using comp = complex_number<double>;
	
	comp r1(3.2,-7.5);
	cout << "Stampa numero: \n" << r1 << "\n" << endl;
	
	comp r2=coniugato(r1);
	cout << "Stampa coniugato: \n" << r2 << "\n" << endl;
	
	
	comp r3(1.6,1.3);
	cout<< "Somme: \n" << r2+r1 << endl;
	cout<< r2 + r3 <<endl;
	r1 += r3;
	cout<< r1 <<endl;
	cout<< r1 + 2.3 <<endl;
	cout<< 2.3 + r1 << "\n" << endl;
	cout<< "Prodotti; \n" << r1*r3<<endl;
	r1 *= r3;
	cout<<r1<<endl;
	r2 = r1 * 2.5;
	cout<< r2 * 2.5 <<endl;
	cout<< 2.5 *r2 << endl;
	;

	return 0;
}