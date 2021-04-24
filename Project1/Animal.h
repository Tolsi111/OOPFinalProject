#pragma once
#include <string>
#include <iostream>

using namespace std;

class Animal
{
private:
	int m_id;

protected:
	string m_name;
	string m_keeper;//the name of the zookeeper
	int m_age;
	float m_size;
	float m_weight;
	float m_upkeep;//upkeep cost of the animal in $ per month

public:
	Animal(int id, string name,int age, float size, float weight, float upkeep);

	int getId();//GETTERS
	string getName();
	string getKeeper();
	int getAge();
	float getSize();
	float getWeight();
	float getUpkeep();

	void setId(int);//SETTERS
	void setName(string);
	void assignKeeper(string keeperName);
	void setAge(int);
	void setSize(float);
	void setWeight(float);
	void setUpkeep(float);

	virtual void display(ostream& os) const;
	friend ostream& operator <<(ostream& os, const Animal& a);


};

