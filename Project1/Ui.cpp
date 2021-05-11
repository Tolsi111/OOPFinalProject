#include "Ui.h"
#include <iostream>
#include <string>
#include "Animal.h"
#include "logic.cpp"

using namespace std;

Ui::Ui(Controller& C) : m_controller{ C }
{

}

void Ui::add()
{	/*
	Asks the user for input. Creates an Animal object with that input. Adds it to the repo
	*/
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
	/*
	Asks the user for input. Removes the Animal with the given id;
	*/
	int id;
	cout << "Id of the animal to be removed: ";
	id = intValidation();
	m_controller.removeById(id);
}

void Ui::Menu()
{	/*
	Starts the Menu
	*/
	m_controller.loadData();///Loads the data from the csv file 'Input.csv'

	char op;
	while (true)
	{
		cout << "Please insert your option: " << endl;
		cout << "\t 1 - add" << endl << "\t 2 - remove" << endl << "\t 3 - display all" << endl;
		cout << "\t 4 - display all animals with an upkeep cost lower than a value" << endl << "\t 5 - display all the new born animals" << endl;
		cout << "\t 6 - undo" << endl << "\t 7 - redo" << endl;
		cout << "\t 0 - exit" << endl;
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
		else if (op == '5')
			m_controller.displayNewBorn();
		else if (op == '6')
			m_controller.undo();
		else if (op == '7')
			m_controller.redo();
		else if (op == '0')
			break;
		else
			cout << "Invalid option  >:[" << endl;

	}

	m_controller.saveData();///Saves the data from the repository to the csv file 'Result.csv'
}
