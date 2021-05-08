#include "Ui.h"
#include <iostream>
#include <string>
#include "Animal.h"
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
	cin >> id;
	cout << "name: " << endl;
	cin >> name;
	cout << "age: " << endl;
	cin >> age;
	cout << "size: " << endl;
	cin >> size;
	cout << "weight: " << endl;
	cin >> weight;
	cout << "upkeep: " << endl;
	cin >> upkeep;

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
