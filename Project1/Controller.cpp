#include "Controller.h"

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

void Controller::displayAll()
{
	m_repo.display(std::cout, [](Animal* A)->bool {return true; });
}
