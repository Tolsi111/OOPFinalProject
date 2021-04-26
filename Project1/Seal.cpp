#include "Seal.h"

Seal::Seal(int id, string name, int age, float size, float weight, float upkeep, float whiskerLength) :
	Animal(id, name, age, size, weight, upkeep), m_whiskerLength{ whiskerLength }
{
	this->m_trained = false;
	this->m_experience = 0;
	this->m_shows = 0;
	this->m_whiskerLength = whiskerLength;
}

//GETTERS
bool Seal::isTrained()
{
	return this->m_trained;
}
int Seal::getExperience()
{
	return this->m_experience;
}
float Seal::getWhiskerLength()
{
	return this->m_whiskerLength;
}
int Seal::getShows()
{
	return this->m_shows;
}

//SETTERS
void Seal::setTrained(bool newTrained)
{
	this->m_trained = newTrained;
}
void Seal::setExperience(int newExperience)
{
	this->m_experience = newExperience;
}
void Seal::setWhiskerLength(float newWhiskerLength)
{
	this->m_whiskerLength = newWhiskerLength;
}
void Seal::setShows(int newShows)
{
	this->m_shows = newShows;
}

bool Seal::train()
{/*
	Trains the seal. The seal must have a trainer. Returns the 'true' if the training was successful
	*/
	if (this->m_keeper != "") {
		if (!isTrained())
			this->m_trained = true;
		this->m_experience++;
		return true;
	}
	else
	{
		cout << "This animal has no keeper, assign a keeper first!";///note: could maybe throw an exception here
		return false;
	}
}

bool Seal::fitForShow()
{/*
	A seal is fit for performing in a show if it has been trained at least 5 times
	*/
	if (isTrained())
		if (this->m_experience >= 5)
			return true;
	return false;
}

void Seal::display(ostream& os) const
{
	os << "Seal ";
	Animal::display(os);
	if (this->m_trained)
	{
		os << " training experience: " << this->m_experience;
	}
	else
	{
		os << " untrained";
	}
}
