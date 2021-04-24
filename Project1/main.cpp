#include <iostream>
#include <string>
#include "Animal.h"
#include "Dolphin.h"
#include "Seal.h"

using namespace std;

int main() {
	Dolphin A(1, "Burrito", 10, 2.3, 60.1, 300,Personality::AGGRESSIVE);

	A.train();
	/*A.assignKeeper("Maricica");
	A.train();
	cout << A.fitForShow() << endl;
	A.train();
	cout << A.fitForShow() << endl;
	A.train();
	A.train();*/
	cout << A.fitForShow() << endl;
	cout << A << endl;
	//A.assignKeeper("Maricica");
	//cout << A;




}