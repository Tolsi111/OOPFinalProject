#include "Animal.h"

Animal::Animal(int id, string name, int age, float size, float weight, float upkeep)
{
    this->m_id = id;
    this->m_name = name;
    this->m_keeper = "";
    this->m_age = age;
    this->m_size = size;
    this->m_weight = weight;
    this->m_upkeep = upkeep;
}

//GETTERS
int Animal::getId()
{
    return this->m_id;
}
string Animal::getName()
{
    return this->m_name;
}
string Animal::getKeeper()
{
    return this->m_keeper;
}
int Animal::getAge()
{
    return this->m_age;
}
float Animal::getSize()
{
    return this->m_size;
}
float Animal::getWeight()
{
    return this->m_weight;
}
float Animal::getUpkeep()
{
    return this->m_upkeep;
}

//SETTERS
void Animal::setId(int newID)
{
    this->m_id = newID;
}
void Animal::setName(string newName)
{
    this->m_name = newName;
}
void Animal::assignKeeper(string keeperName)
{
    this->m_keeper = keeperName;
}
void Animal::setAge(int newAge)
{
    this->m_age = newAge;
}
void Animal::setSize(float newSize)
{
    this->m_size = newSize;
}
void Animal::setWeight(float newWeight)
{
    this->m_weight = newWeight;
}
void Animal::setUpkeep(float newUpkeep)
{
    this->m_upkeep = newUpkeep;
}


void Animal::display(ostream& os) const
{
    os << "#" << m_id << " " << m_name << " " << m_age << " years old, " << m_size << " meters, " << m_weight << " kg, " << m_upkeep << "$";
    if (m_keeper != "")
        os << " trained by " << m_keeper;
}

ostream& operator<<(ostream& os, const Animal& a)
{
    a.display(os);
    return os;
}
