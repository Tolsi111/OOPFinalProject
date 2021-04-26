#pragma once
#include "Animal.h"
#include <iostream>
#include <string>

class Shark :
    public Animal
{
private:
    string m_bread;
    int m_threat;//to divers and other animals on a scale of 1 to 10
    int m_teeth;//the number of teeth this shark has

public:
    Shark(int id, string name, int age, float size, float weight, float upkeep, string bread, int teeth);

    string getBread();//GETTERS
    int getThreat();
    int getTeeth();

    void setBread(string);//SETTERS
    void setThreat(int);
    void setTeeth(int);

    bool tame();

    bool safeDiving();

    void display(ostream& os)const override;

};

