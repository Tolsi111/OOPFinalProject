#include "AnimalRepo.h"
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

void AnimalRepo::addAnimal(Animal* newAnimal)
{	/*
	Adds an animal to the repository
	*/
	m_data.push_back(newAnimal);
}

Animal* AnimalRepo::removeAnimal(int id)
{	/*
	Removes the animal with the given 'id' from the repository. Nothing happens if the animal does not exist. Returns the removed animal for the undo/redo
	*/
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

//vector<string> AnimalRepo::tokenize(string str, char delim)
//{	/*
//	Returnes a vector of tokens from the string 'str' using the delimiter 'delim'
//	*/
//	vector<string> result;
//	stringstream ss(str);
//	string token;
//	while (getline(ss, token, delim))
//		result.push_back(token);
//
//	return result;
//}

//istream& operator>>(istream& is,Animal& A)
//{	/*
//	Reads
//	*/
//
//	string line;
//	getline(is, line);///reads a line
//
//	vector<string> tokens;///list of the CSVs
//	stringstream ss(line);
//	string token;
//	while (getline(ss,token,','))
//		tokens.push_back(token);
//
//	A.setId(stoi(tokens[0]));///stoi(string) --> returns the int representation of the string
//	A.setName(tokens[1]);
//	A.setAge(stof(tokens[2]));///stof(string) --> returns the float representation of the string
//	A.setSize(stof(tokens[3]));
//	A.setWeight(stof(tokens[4]));
//	A.setUpkeep(stof(tokens[5]));
//	
//
//	return is;
//}


string AnimalRepo::animalToCsv(Animal* A)
{
	string result;
	result = to_string(A->getId()) + ',' + A->getName() + ',' + to_string(A->getAge());
	result += ',' + to_string(A->getSize()) + ',' + to_string(A->getWeight()) + ',' + to_string(A->getUpkeep());
	return result;
}

ostream& AnimalRepo::display(ostream& os, bool(*filterFunction)(Animal*))
{	/*
	Displays all the animals that satisfy a given property 'filterFunction'
	*/
	for (auto i = 0; i < m_data.size(); i++)
		if (filterFunction(m_data[i]) == true)
			os << *m_data[i] << endl;
	return os;
}

ostream& AnimalRepo::displayCheaper(ostream& os,float value,bool(*filterFunction2)(Animal*,float))
{	/*
	Displays all the animals that satisfy a given property 'filterFunction2'. This property depends on a second float variable
	*/
	for (auto i = 0; i < m_data.size(); i++)
		if (filterFunction2(m_data[i],value) == true)
			os << *m_data[i] << endl;
	return os;
}

void AnimalRepo::loadData()
{	/*
	Reads tha data from 'Input.csv' and loads it into the repository
	*/
	fstream inputFile;
	inputFile.open("Input.csv",ios::in);
	string line;

	while (getline(inputFile, line))
	{
		vector<string> tokens;///list of the CSVs 
		stringstream ss(line);
		string token;
		while (getline(ss, token, ','))///split and place each 'token' into the list of tokens 'tokens'
			tokens.push_back(token);


		///store the data from 'tokens' to variables
		int id = (stoi(tokens[0]));///stoi(string) --> returns the int representation of the string
		string name = (tokens[1]);
		int age = (stof(tokens[2]));///stof(string) --> returns the float representation of the string
		float size = (stof(tokens[3]));
		float weight = (stof(tokens[4]));
		float upkeep = (stof(tokens[5]));

		///Create and add the animal
		Animal* newAnimal = new Animal(id, name, age, size, weight, upkeep);
		addAnimal(newAnimal);
	}
	inputFile.close();
}

void AnimalRepo::saveData()/////////////////INCOMPLETE
{	/*
	Writes and saves the data from the repository to 'Result.csv'
	*/
	fstream fout;
	fout.open("Result.csv", ios::out);
	for (auto i = 0; i < m_data.size(); i++)
		fout << animalToCsv(m_data[i]) << endl;
	fout.close();
}


