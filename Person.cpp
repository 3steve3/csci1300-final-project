#include "Person.h"
//creates person object
Person::Person(){
    name = "";
    isDead = 0;
    isSick = 0;
}
//returns true if person is dead
bool Person::dead(){
    return isDead;
}
//returns true if person is sick
bool Person::sick(){
    return isSick;
}
void Person::setDeath(){
    isDead = 1;
}
void Person::setSick(){
    isSick = 1;
}
void Person::setHealed(){
    isSick = 0;
}
void Person::setName(string input){
    name = input;
}
string Person::getName(){
    return name;
}