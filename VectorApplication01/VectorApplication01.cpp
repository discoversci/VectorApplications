#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class A {
	int number = 0;
	int number2 = 0;
public:
	A(int _number) : number(_number), number2(0) {
		cout << "Normal constructor " << number << "\n";
	}

	A() :number(1) {
		cout << "Default constructor " << number << "\n";
	}

	A(const A& source) {
		number = source.number;
		number2 = source.number2;
		cout << "Copy constructor " << number << "\n";
	}

	A& operator=(const A& source) {
		number = source.number;
		number2 = source.number2;
		cout << "Assignment operator\n";
		return *this;
	}
	~A() {
		cout << "Destructor classa " << number << "\n";
	};
};

int main() {

	//	//vector <A> v1(2); //rezerviramo 2 elementa, kar pomeni, da se pokliceta dva default construcotrja
	//
	//	vector <A> v1(1); //rezerviramo 1 element, kar pomeni, da se poklice en default constructor
	//		
	//	//vector <A> v2(2, A{ 1 });	//s tadrugo vrednostjo povemo s katerim elementom naj se vectorjevi elementi inicializirajo
	//								//ker je definiran copy constructor, se uporabi na vsakem elementu vectorja z navedenim zacetnim A{1}
	//								//najprej se kreira A{1}, nato se kopira v elementa vektorja -> za to ap se uporabi copy construcotr
	//
	//	v1.push_back(2); //tu se pa naredi ze realokacija na nova pomnilniska mesta, da se naredi prostor za nov element, ki se ga doda s push_back
	//
	///*
	//	Default constructor 1	- Kreira se en element v vektorju na zaèetku
	//	Normal constructor 2	- Ker delamo push s parametrom, se kreira objekt z uporabo implicitnega constructorja (ni na voljo explicit)
	//	Copy constructor 2		- Potem se skopira na novo mesto kjer se nahaja nov vektor. Copy construcotr je od ustvaritve novega elementa v novem vectorju. 
	//							  Pazi kopira, ne assigna. Assignat se ne more, ker se nic ni notri v bucketu ustvarjeno. Najprej se mora ustvarit, potem se lahko assign-a.
	//	Copy constructor 1		- ravno tako prvi element, se mora skopirat, ne assignat. V bucketu bo lezal nov element, s cim ga inicializiramo ? 
	//							  Z objektom iz starega vektorja... s tem bomo novega inicializirali. Niè se ne obstaja notri.
	//	Destructor classa 1		- stari prvi element se unici	
	//	Destructor classa 2		- Novi zaèasni element se unièi
	//	--------------Separator------------------
	//	Destructor classa 1		- Konec programa, treba poèistit elemente v vektorju
	//	Destructor classa 2		- Konec programa, treba poèistit elemente v vektorju
	//*/
	//
	//	v1[0] = 10;
	//
	//	/*
	//	Default constructor 1	- Kreira se en element v vektorju na zaèetku
	//	Normal constructor 2	- Ker delamo push s parametrom, se kreira implicitni constructor (ni na voljo explicit)
	//	Copy constructor 2		- Potem se skopira na novo mesto kjer se nahaja vektor
	//	Copy constructor 1		- ravno tako prvi element
	//	Destructor classa 1		- stari prvi element se unici
	//	Destructor classa 2		- Novi zaèasni element se unièi
	//	Normal constructor 10	- Kreira se zaèasni element z vrednostjo 10
	//	Assignment operator		- Se assigna na prvo mesto in s tem izrine prvi element. Tule bi morala instanca poskrbeti da 
	//							odstrani prejsnjo vsebino kamor je kazal nek pointer in pointerju priredi novo vrednost pomnilniske lokacije, 
	//							na desni strani operatorja
	//	Destructor classa 10	- Zaèasna instanca se briše
	//	--------------Separator------------------
	//	Destructor classa 1		- Konec programa, treba poèistit elemente v vektorju
	//	Destructor classa 2		- Konec programa, treba poèistit elemente v vektorju
	//	*/
	//	   
	//

	cout << "--------------Separator------------------\n";

	std::vector<A> vec(5);
	std::cout << "Size: " << vec.size() << std::endl;
	std::cout << "Capacity: " << vec.capacity() << std::endl;

	vec.resize(10, A(2));
	std::cout << "Size: " << vec.size() << std::endl;
	std::cout << "Capacity: " << vec.capacity() << std::endl;

	vec.resize(3, A(2));
	std::cout << "Size: " << vec.size() << std::endl;
	std::cout << "Capacity: " << vec.capacity() << std::endl;




	return 0;
}