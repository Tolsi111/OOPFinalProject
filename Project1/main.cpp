#include <iostream>
#include <string>
#include "Animal.h"
#include "Dolphin.h"
#include "Seal.h"
#include "Shark.h"

using namespace std;

int main() {
	//Shark A(1, "Burrito", 10, 2.3, 60.1, 300,"hammer head",210);

	/*A.assignKeeper("Maricica");
	A.train();
	cout << A.fitForShow() << endl;
	A.train();
	cout << A.fitForShow() << endl;
	A.train();
	A.train();*/
	//cout << A << endl;
	//A.assignKeeper("Maricica");
	//cout << A;

	int x;
	cin >> x;
	while (x <= 0 || 100 <= x) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "invalid" << endl;
		cin >> x;
	}

}