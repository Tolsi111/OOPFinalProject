#include "AnimalRepo.h"
#include <algorithm>
//#include "logic.cpp"

using namespace std;
void AnimalRepo::addAnimal(Animal* newAnimal)
{
	m_data.push_back(newAnimal);
}

Animal* AnimalRepo::removeAnimal(int id)
{
	Animal* result = nullptr;
	auto index = find_if(m_data.begin(), m_data.end(), [id](Animal* result)->bool {
		return result->getId() == id;
		});
	if (index != m_data.end()) {
		result = *index;
		m_data.erase(index);
	}
	return result;
}

ostream& AnimalRepo::display(ostream& os, bool(*filterFunction)(Animal*))
{
	for (auto i = 0; i < m_data.size(); i++)
		if (filterFunction(m_data[i]) == true)
			os << *m_data[i] << endl;
	return os;
}

ostream& AnimalRepo::displayCheaper(ostream& os,float value,bool(*filterFunction2)(Animal*,float))
{
	for (auto i = 0; i < m_data.size(); i++)
		if (filterFunction2(m_data[i],value) == true)
			os << *m_data[i] << endl;
	return os;
}


