#pragma once
#include "AnimalRepo.h"
#include <stack>
using namespace std;

enum class Action {
	ADD,
	REMOVE
};
class Controller
{
private:
	AnimalRepo m_repo;
	std::stack<pair<Action, Animal*>> m_undoStack;
	std::stack<pair<Action, Animal*>> m_redoStack;
public:
	Controller(AnimalRepo&);

	void addAnimal(Animal*);

	void removeById(int);
	void displayAll();
};

