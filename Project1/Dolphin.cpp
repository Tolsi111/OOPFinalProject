#include "Dolphin.h"

Dolphin::Dolphin(int id, string name, int age, float size, float weight, float upkeep, Personality personality) :
	Animal(id, name, age, size, weight, upkeep), m_personality{ personality }
{
	this->m_trained = false;
	this->m_experience = 0;
	this->m_shows = 0;
	this->m_personality = personality;
}

//GETTERS
bool Dolphin::isTrained()
{
	return this->m_trained;
}
int Dolphin::getExperience()
{
	return this->m_experience;
}
Personality Dolphin::getPersonality()
{
	return this->m_personality;
}
int Dolphin::getShows()
{
	return this->m_shows;
}


//SETTERS
void Dolphin::setTrained(bool newTrained)
{
	this->m_trained = newTrained;
}
void Dolphin::setExperience(int newExperience)
{
	this->m_experience = newExperience;
}
void Dolphin::setPersonality(Personality newPersonality)
{
	this->m_personality = newPersonality;
}
void Dolphin::setShows(int  newShows)
{
	this->m_shows = newShows;
}

bool Dolphin::train()
{	/*
	Trains the dolphin. The dolphin must have a trainer. Returns the 'true' if the training was successful
	*/
	if (this->m_keeper != ""){
		if (!isTrained())
			this->m_trained = true;
		this->m_experience++;
		return true;
	}
	else
	{
		cout << " This dolphin has no trainer. Assign a trainer first!";///note: could maybe throw an exception here
		return false;
	}
}

bool Dolphin::fitForShow()
{	/*
	A dolphin is fit for performing in a show if it has been trained at least 3 times and it must not be aggressive
	*/
	if (isTrained() && int(this->m_personality) != 4)
		if (this->m_experience >= 3)
			return true;
	return false;
}

void Dolphin::display(ostream& os) const
{
	os << "Dolphin ";
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
