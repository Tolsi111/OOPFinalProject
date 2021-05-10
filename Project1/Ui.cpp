#include "Ui.h"
#include <iostream>
#include <string>
#include "Animal.h"
#include "logic.cpp"

using namespace std;

Ui::Ui(Controller& C) : m_controller{ C }
{

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
	id = intValidation();
	m_controller.removeById(id);
}

void Ui::Menu()
{
	char op;
	while (true)
	{
		cout << "Please insert your option: " << endl;
		cout << "\t 1 - add" << endl << "\t 2 - remove" << endl << "\t 3 - display all" << endl << "\t 4 - display all animals with an upkeep cost lower than a value" << endl << "\t 0 - exit" << endl;
		cin >> op;
		if (op == '1')
			add();
		else if (op == '2')
			remove();
		else if (op == '3')
			m_controller.displayAll();
		else if (op == '4') {
			float value = floatValidation();
			m_controller.displayByCheaper(value);
		}
		else if (op == '0')
			break;
		else
			cout << "Invalid option  >:[" << endl;

	}
}
