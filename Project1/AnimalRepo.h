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
	ostream& displayCheaper(ostream& os, float value, bool(*filterFunction2)(Animal*,float));

};

//class Filter
//{
//private:
//	virtual bool filter(Animal*);
//};
//
//class FilterByLowerCost : public Filter
//{
//public:
//	FilterByLowerCost();
//	void setPrice(float);
//	bool filter(Animal*) override;
//
//private:
//	float price;
//};

