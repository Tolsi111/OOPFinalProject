#include "Ui.h"
#include <iostream>
#include <string>
#include "Animal.h"
using namespace std;

Ui::Ui(Controller& C) : m_controller{ C }
{

}

int Ui::intValidation()
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
		cout << "Invalid input, please insert a positive integer" << endl;
		cin >> x;
	}
	return x;
}

float Ui::floatValidation()
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
		cout << "Invalid input, please insert a positive float" << endl;
		cin >> x;
	}
	return x;
}

void Ui::add()///note: data validation
{
	int id, age;
	float size, weight, upkeep;
	string name;
	cout << "id: " << endl;
	id = intValidation();
	cout << "name: " << endl;
	cin >> name;
	cout << "age: " << endl;
	age = intValidation();
	cout << "size: " << endl;
	size = floatValidation();
	cout << "weight: " << endl;
	weight = floatValidation();;
	cout << "upkeep: " << endl;
	upkeep = floatValidation();

	Animal* newAnimal = new Animal(id, name, age, size, weight, upkeep);
	m_controller.addAnimal(newAnimal);
}

void Ui::remove()
{
	int id;
	cout << "Id of the animal to be removed: ";
	cin >> id;
	m_controller.removeById(id);
}

void Ui::Menu()
{
	int op;
	while (true)
	{
		cout << "Please insert your option: " << endl;
		cout << "\t 1 - add" << endl << "\t 2 - remove" << endl << "\t 0 - exit";
		cin >> op;///note: data validation
		if (op == 1)
			add();
		else if (op == 2)
			remove();
		else if (op == 0)
			break;
		else
			cout << "Invalid option  >:[" << endl;

	}
}
