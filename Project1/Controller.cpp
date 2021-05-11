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

void Controller::undo()
{	/*
	Undo last operation
	*/
	if (!m_undoStack.empty())
	{
		pair<Action, Animal*> lastOperation = m_undoStack.top();
		m_redoStack.push(lastOperation);///add the last operation to the redo stack

		if (lastOperation.first == Action::ADD)///if last operation was 'ADD' then remove the added element
			m_repo.removeAnimal(lastOperation.second->getId());
		else
			m_repo.addAnimal(lastOperation.second);///if last operation was 'REMOVE' then add the removed element

		m_undoStack.pop();
	}
}

void Controller::redo()
{	/*
	Undo last operation
	*/
	if (!m_redoStack.empty())
	{
		pair<Action, Animal*> lastOperation = m_redoStack.top();
		m_undoStack.push(lastOperation);///add the last operation back to the undo stack

		if (lastOperation.first == Action::ADD)///if last operation was 'ADD' then add back the animal 
			m_repo.addAnimal(lastOperation.second);
		else
			m_repo.removeAnimal(lastOperation.second->getId());///if last operation was 'REMOVE' then remove back the animal

		m_redoStack.pop();
	}
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
{	/*
	Loads the data from a csv file
	*/
	m_repo.loadData();
}

void Controller::saveData()
{	/*
	Saves the data from a csv file
	*/
	m_repo.saveData();
}
