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





	/*ifstream fin("Input.csv");

	string s1, s2, s3;
	int nb;
	fin >> s1;
	cout << s1;*/
}