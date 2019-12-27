#include <vector>
#include <iostream>
#include "A.h"

int main() {
	//Kreiramo najprej container v1. Notri damo z implicitnim kreiranjem instanco classa A. Kreira se najprej za�asni objekt, se inicializira z vrednostjo 505,
	//nato se skreira v vektorju element s copy constructorjem, nato se uni�i za�asni element 505. Ko se dodaja 506 instanco, je 
	//treba selit stari vector v novega. Za�asno se naredi 506 instanca, nato se s copy constructorjem preseli prvega iz starega prostora pomnilnika za v1
	//in skopira �e drugega novega v nov prostor v pomnilniku za v1. Stari element v v1 in za�asni novi element se potem uni�ijo.

	//Na koncu se uni�ijo vsi elementi iz vseh treh vektorjev.

	//Code:
	std::vector <A> v1;

	v1.push_back(505);
	std::cout << "First ready!\n";

	v1.push_back(506);
	std::cout << "Second ready!\n";

	v1.push_back(507);
	std::cout << "Third ready!\n";

	//Output:
	//Normal constructor with ID : 505.
	//Copy constructor 505.
	//Destructor of class 505.
	//First ready!
	//Normal constructor with ID : 506.
	//Copy constructor 506.
	//Copy constructor 505.
	//Destructor of class 505.
	//Destructor of class 506.
	//Second ready!
	//Normal constructor with ID : 507.
	//Copy constructor 507.
	//Copy constructor 505.
	//Copy constructor 506.
	//Destructor of class 505.
	//Destructor of class 506.
	//Destructor of class 507.
	//Third ready!
	//Destructor of class 505.
	//Destructor of class 506.
	//Destructor of class 507.


	//DO NOT RUN FOLLOWING CODE
	//Tu je problem, da smo dinami�no alocirali pointerje, ki ka�ejo na dele pomnilnika, ki bi morale biti ro�no potem spro��ene, pa niso bile.
	//Tu je memory leak.

	//int main() {
	//	vector<A*> v1;
	//	v1.push_back(new A(1));
	//	cout << "First ready!\n";
	//	v1.push_back(new A(2));
	//	cout << "Second ready!\n";
	//	v1.push_back(new A(3));
	//	cout << "Third ready!\n";
	//	return 0;
	//}














	return 0;
}