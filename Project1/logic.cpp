#include <iostream>

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