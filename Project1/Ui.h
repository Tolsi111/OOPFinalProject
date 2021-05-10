#pragma once
#include "Controller.h"
class Ui
{
private:
	Controller m_controller;

public:
	Ui(Controller&);

	void add();
	void remove();

	void Menu();

	
};

