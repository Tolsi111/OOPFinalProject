#pragma once
#include "Controller.h"
class Ui
{
private:
	Controller m_controller;

public:
	Ui(Controller&);

	int intValidation();
	float floatValidation();

	void add();
	void remove();

	void Menu();

	
};

