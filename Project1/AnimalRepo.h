#pragma once
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
	ostream& display(ostream& os, bool (*filterFunction)(Animal*));

};

