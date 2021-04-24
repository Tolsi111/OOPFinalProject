#pragma once
#include "Animal.h"
#include <iostream>

enum class Personality{///note: friend ostream& operator <<
    FRIENDLY,
    ENERGETIC,
    SHY,
    CLUMSY,
    AGGRESSIVE
};

class Dolphin :
    public Animal
{
private:
    bool m_trained;
    int m_experience;//as in number of training sessions
    Personality m_personality;
    int m_shows;//as in number of shows it has performed

public:
    Dolphin(int id, string name, int age, float size, float weight, float upkeep, Personality personality);

    bool isTrained();//GETTERS
    int getExperience();
    Personality getPersonality();
    int getShows();

    void setTrained(bool);//SETTERS
    void setExperience(int);
    void setPersonality(Personality);
    void setShows(int);

    bool train();

    bool fitForShow();

    void display(ostream& os)const override;
};

