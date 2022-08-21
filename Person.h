#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Person{
    private:
        bool isSick;
        bool isDead;
        string name;
    public:
        Person();
        bool sick();
        bool dead();
        void setSick();
        void setDeath();
        void setHealed();
        string getName();
        void setName(string input);
};
#endif