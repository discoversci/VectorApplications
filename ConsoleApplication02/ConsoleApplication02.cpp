#include <vector>
#include <iostream>
#include <algorithm>



class A {
	int m_id = 0;
	static inline size_t generator = 505;
public:
	A(int id) : m_id(id) {
		std::cout << "Normal constructor with ID: " << m_id << ".\n";
	}

	A() : m_id(generator++) {
		std::cout << "Default constructor " << m_id << ".\n";
	}

	A(const A& source) {
		m_id = source.m_id;
		std::cout << "Copy constructor " << m_id << ".\n";
	}

	A& operator=(const A& source) {
		m_id = source.m_id;
		std::cout << "Assignment operator for source value " << source.m_id << ".\n";
		return *this;
	}
	~A() {
		std::cout << "Destructor of class " << m_id << ".\n";
	};
};

int main() {

	//Code:
	//rezerviramo 2 elementa, kar pomeni, da se pokliceta dva default constructorja z id-ji ki se generirajo s strani generator static variable
	//Na koncu se unicita obe instanci v vectorju, skupaj s samim vectorjem.
	//->std::vector <A> v1(2); 
	//Output:
	//Default constructor 505.
	//Default constructor 506.
	//--------------Separator------------------
	//Destructor of class 505.
	//Destructor of class 506.

	//Code:
	//rezerviramo 2 elementa ki jih napolnimo z inicialno vrednostjo instance class-a A, z ID-jem 1001
	//Kreirata se dve mesti v vektorju s pomocjo copy constructorja. Na koncu se unici zacasni element, nato pa se obe mesti v vectorju,
	//skupaj s samim vectorjem.
	//->std::vector <A> v2(2, A{ 1001 });	
	//Output:
	//Normal constructor with ID : 1001
	//Copy constructor 1001.
	//Copy constructor 1001.
	//Destructor of class 1001.
	//--------------Separator------------------
	//Destructor of class 1001.
	//Destructor of class 1001.

	//Code:
	//Rezerviraj dve mesti z default vrednostmi ID-jev, nato pa dodaj na konec vektorja instanco (ki se kreira implicitno z id-jem 202)
	//Kreira se nov zacasni element z ID 202, ki se ga uporabi za inicializacijo zadnjega elementa v novem vectorju.
	//Nato se skopirata se iz starega vectorja dva elementa v nov vector. Nato se brisejo tako yacasni element, kot tudi dva stara iz starega vectorja.
	//Na koncu se pobrisejo se vsi elementi novega vectorja, skupaj s samim vectorjem.
	//->std::vector <A> v1(2); 
	//->v1.push_back(202); 
	//Output:
	//Default constructor 505.
	//Default constructor 506.
	//Normal constructor with ID : 202.
	//Copy constructor 202.
	//Copy constructor 505.
	//Copy constructor 506.
	//Destructor of class 505.
	//Destructor of class 506.
	//Destructor of class 202.
	//--------------Separator------------------
	//Destructor of class 505.
	//Destructor of class 506.
	//Destructor of class 202.

	//Code:
	//Najprej se rezervirata dva prostora z uporabo default constructorja in generatorskimi ID-ji. Potem se z uporabo implicitnega
	//prirejanja kreira zacasna instanca, nato se priredi zacasna instanca s pomocjo assignment operatorja instanci na prvem mestu.
	//Nato se zacasna instanca unici in na koncu se oba elementa vectorja skupaj s samim vectorjem.
	std::vector <A> v1(2);
	v1[0] = 2002;
	//Output:
	//Default constructor 505.
	//Default constructor 506.
	//Normal constructor with ID : 2002.
	//Assignment operator for source value 2002.
	//Destructor of class 2002.
	//--------------Separator------------------
	//Destructor of class 2002.
	//Destructor of class 506.


	std::cout << "--------------Separator------------------\n";
	return 0;
}