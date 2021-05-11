#include "Shark.h"

Shark::Shark(int id, string name, int age, float size, float weight, float upkeep, string bread, int teeth) :
	Animal(id, name, age, size, weight, upkeep), m_bread{ bread }, m_teeth{ teeth }
{
	this->m_bread = bread;
	this->m_threat = 10;
	this->m_teeth = teeth;
}

//GETTERS
string Shark::getBread()
{
	return this->m_bread	;
}
int Shark::getThreat()
{
	return this->m_threat;
}
int Shark::getTeeth()
{
	return this->m_teeth;
}

//SETTERS
void Shark::setBread(string newBreed)
{
	this->m_bread = newBreed;
}
void Shark::setThreat(int newThreat)
{
	this->m_threat = newThreat;
}
void Shark::setTeeth(int newTeeth)
{
	this->m_teeth = newTeeth;
}

bool Shark::tame()
{	/*
	Tames the shark. The shark must have a tamer. Returns the 'true' if the taming was successful
	*/
	if (this->m_keeper == "") {
		cout << "This animal has no keeper, assign a keeper first!";///note: could maybe throw an exception here
		return false;
	}
	else
	{
		if (this->m_threat > 0)
			this->m_threat--;
	}
}

bool Shark::safeDiving()
{	/*
	A shark is safe for diving with if its level of aggressiveness is <= 3;
	*/
	if (this->m_threat <= 3)
		return true;
	return false;
}

void Shark::display(ostream& os) const
{	/*
	Builds the stream for displaying
	*/
	os << this->m_bread << " shark ";
	Animal::display(os);
	if (this->m_threat == 0)
	{
		os << " no threat";
	}
	else if (this->m_threat <= 3)
	{
		os << " low threat";
	}
	else if(this->m_threat <= 6)
	{
		os << " medium threat";
	}
	else
	{
		os << " high threat";
	}
}
