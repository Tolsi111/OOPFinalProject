#pragma once
#include <istream>
#include "Animal.h"
#include <vector>

using namespace std;

class AnimalRepo
{
private:
	vector<Animal*> m_data;

public:
	void addAnimal(Animal*);
	Animal* removeAnimal(int);

	//vector<string> tokenize(string, char);
	//friend istream& operator >> (istream&,Animal&);
	string animalToCsv(Animal*);

	ostream& display(ostream& os, bool (*filterFunction)(Animal*));
	ostream& displayCheaper(ostream& os, float value, bool(*filterFunction2)(Animal*,float));

	void loadData();
	void saveData();

};

