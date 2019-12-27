#include <vector>
#include <iostream>
#include <algorithm>
#include "A.h"

int main() {

	//Code:
	//Kreira se vektor brez elementov. Pri tem se ne klice noben constructor.
	//Potem se kreira zacasni element in sicer implicitno iz numerike v instanco classa A. To je normal constructor. Potem se rezervira en prostor 
	//v vectorju in se ga napolni z elementom, klicoè copy-construcotor. Unièi se zaèasni element, nato pa še element znotraj vectorja.
	std::vector <A> v1;
	v1.push_back(5005);
	std::cout << "One finished!\n";
	//Output:
	//Normal constructor with ID : 5005.
	//Copy constructor 5005.
	//Destructor of class 5005.
	//One finished!
	//Destructor of class 5005.

	//Dodano k zgornjemu: ker je v v1 samo en element, se klice samo en copy constructor, ko se kopira elemente v drug vector. Vector ima definiran copy constructor,
	//ki poskrbi da se klicejo copy constructorji od posameznih instanc classa A. Se morajo, ker se kopirajo notri. Na koncu se iz obeh vectorjev
	//klice destructor.
	std::vector <A> v2(v1);
	std::cout << "Two finished!\n";
	//Copy constructor 5005.
	//Two finished!
	//Destructor of class 5005.
	//Destructor of class 5005.

	//Dodano k zgornjemu: tu je vector v3 prazen in to je tisto kar je pomembno. V bistvu se mora še kreirat in se zato ne more prirejat.
	//Zato se tudi ne uporabi assignment, ampak copy construcotr. Najprej se mora kreirat element v v3, nato se mu lahko kaj prireja. Èe ni
	//kreiranega elementa, se ne more niè primerjat. TO SI JE ZA ZAPOMNIT. Na koncu se vsi trije elementi v vectorjih unièijo, zato tri krat 
	//klic destructorja.
	//Code:
	std::vector <A> v3;
	v3 = v2;
	std::cout << "Three finished!\n";
	//Copy constructor 5005.
	//Three finished!
	//Destructor of class 5005.
	//Destructor of class 5005.
	//Destructor of class 5005.

	//Tule pa najprej kreiramo vector z default dvema elementoma, zato se najprej kliceta default constructorja (za implicitno pretvorbo),
	//ki sama dva napolnita svoje ID-je s pomocjo generatorja. Nato se copy constructorja za kreiranje dveh elementov v vectorju v4.
	//Nato se, ker je v v2 le ene element, ta priredi elementu v v4. Iz prvega elementa v2, v prvi element v4. Èe bi bilo veè elementov v v2,
	//bi se vsi priredili v v4. Element za elementom. Prirejanje se pa lahko uporabi, ker sta v obeh vectorjih elementi že prisotni. Èe jih ne 
	//bi bilo, bi se uporabil copy constructor. To je podobno kot assignment initialization. 
	//Code:
	std::vector <A> v4(2);
	v4 = v2;
	//Output:
	//Default constructor 505.
	//Default constructor 506.
	//Assignment operator for source value 5005.
	//Destructor of class 506.
	//Destructor of class 5005.
	//Destructor of class 5005.
	//Destructor of class 5005.
	//Destructor of class 5005.

	//tole je primer ya resize
	//resiye, ki poreze zadnje vrednosti klice samo destructor, brez da se da notri v vector kaksne vrednosti nove
	std::vector <A> v5 = { A(101), A(102), A(103), A(104), A(105), A(106), A(107), A(108), A(109), A(110) };

	std::for_each(v5.begin(), v5.end(), [](const A& a) {std::cout << "id: " << a.id() << " "; });
	std::cout << "\n";

	v5.resize(5);

	std::for_each(v5.begin(), v5.end(), [](const A& a) {std::cout << "id: " << a.id() << " "; });
	std::cout << "\n";

	return 0;
}