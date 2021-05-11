#include <iostream>
#include <string>
#include "Animal.h"
#include "Dolphin.h"
#include "Seal.h"
#include "Shark.h"
#include "AnimalRepo.h"
#include "Controller.h"
#include "Ui.h"

//#include "logic.cpp"

using namespace std;

int main() {
	AnimalRepo repo;
	Controller C(repo);
	Ui ui(C);

	ui.Menu();
}