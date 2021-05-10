#include <iostream>
//#include "Animal.h"

using namespace std;

inline int intValidation()
{	/*
	* Forces the user to give a positive int as the input
	* Returnes the value
	*/
	int x;
	cin >> x;
	while (x <= 0) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "Invalid input, please insert a valid integer" << endl;
		cin >> x;
	}
	return x;
}

inline float floatValidation()
{	/*
	* Forces the user to give a positive float as the input
	* Returnes the value
	*/
	float x;
	cin >> x;
	while (x <= 0) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "Invalid input, please insert a valid float" << endl;
		cin >> x;
	}
	return x;
}

//bool filterCheaper(Animal* A) {
//	/*
//	* Returnes true if the animal upkeep is lower then the 'maxPrice'
//	*/
//	//float maxPrice = floatValidation();
//	//float maxPrice = floatValidation();
//	if (A->getUpkeep() <= maxPrice)
//		return true;
//	return false;
//}