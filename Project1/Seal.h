#pragma once
#include "Animal.h"
class Seal :
    public Animal
{
private:
    bool m_trained;
    int m_experience;//as in number of training sessions
    float m_whiskerLength;// in cm
    int m_shows;//as in number of shows it has performed

public:
    Seal(int id, string name, int age, float size, float weight, float upkeep, float whiskerLength);

    bool isTrained();//GETTERS
    int getExperience();
    float getWhiskerLength();
    int getShows();

    void setTrained(bool);//SETTERS
    void setExperience(int);
    void setWhiskerLength(float);
    void setShows(int);

    bool train();

    bool fitForShow();

    void display(ostream& os)const override;

};

