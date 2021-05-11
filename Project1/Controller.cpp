#include "Controller.h"
//#include "logic.cpp"

Controller::Controller(AnimalRepo& repo)
{
	this->m_repo = repo;
}

void Controller::addAnimal(Animal* newAnimal)
{
	m_repo.addAnimal(newAnimal);
	m_undoStack.push(std::make_pair(Action::ADD, newAnimal));
}

void Controller::removeById(int id)
{
	Animal* A = m_repo.removeAnimal(id);
	if(A)
		m_undoStack.push(std::make_pair(Action::REMOVE,A));
}

void Controller::displayByCheaper(float value)
{	/*
	Displays all the animals that have the upkeep cost lower than a given 'value'
	*/
	m_repo.displayCheaper(std::cout, value, [](Animal* A, float val)->bool {
		if (A->getUpkeep() <= val)
			return true;
	else
			return false; });
}

void Controller::displayNewBorn()
{	/*
	Displays all the new born animals. An animal is new born if it is just 1 year old
	*/
	m_repo.display(std::cout, [](Animal* A)->bool {
		if (A->getAge() == 1)
			return true;
		return false;
	});
}

void Controller::displayAll()
{	/*
	Displays all the animals
	*/
	m_repo.display(std::cout, [](Animal* A)->bool {return true; });
}

void Controller::loadData()
{
	m_repo.loadData();
}

void Controller::saveData()
{
	m_repo.saveData();
}
