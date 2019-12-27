#include <vector>
#include <iostream>

using namespace std;

class A
{
	int number;
public:
	A(int _number) :number(_number) {}
};


//NEVARNO POCETJE - implicitni prevod - raje uporabimo explicit pri construcotrju

int main() {
	vector<A> v1;
	v1.push_back(1);
	return 0;
}