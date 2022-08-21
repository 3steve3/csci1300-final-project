#include "inventory.h"
Inventory::Inventory(){
    
}
int Inventory::bullets = 0;
int Inventory::food = 0;
int Inventory::medicine = 0;
int Inventory::oxen = 0;
int Inventory::parts = 0;
double Inventory::money = 1600;
void Inventory::loseBullets(int amount){
    bullets = bullets - amount;
    if(bullets < 0){
        bullets = 0;
    }
}
void Inventory::loseFood(int amount){
    food = food - amount;
    if(food < 0){
        food = 0;
    }
}
void Inventory::loseOxen(int amount){
    oxen = oxen - amount;
    if(oxen < 0){
        oxen = 0;
    }
}
void Inventory::loseMedicine(int amount){
    medicine = medicine - amount;
    if(medicine < 0){
        medicine = 0;
    }
}
void Inventory::loseParts(int amount){
    parts = parts - amount;
    if(parts < 0){
        parts = 0;
    }
}
double Inventory::getMoney(){
    return money;
}
int Inventory:: getBullets(){
    return bullets;
}
int Inventory::getFood(){
    return food;
}
int Inventory::getMedicine(){
    return medicine;
}
int Inventory::getOxen(){
    return oxen;
}
int Inventory::getParts(){
    return parts;
}
void Inventory::buyOxen(int amount){
    oxen = oxen + amount * 2;
}
void Inventory::spendMoney(double amount){
    money = money - amount;
}
void Inventory::buyFood(int amount){
    food = food + amount;
    if (food > 1000){
        food = 1000;
        cout << "You can only carry 1000 lbs. of food. You have left the extra food behind." << endl;
    }
}
void Inventory::buyBullets(int amount){
    bullets = bullets + amount * 20;
}
void Inventory::buyParts(int amount){
    parts = parts + amount;
}
void Inventory::buyMedicine(int amount){
    medicine = medicine + amount;
}
void Inventory::increaseBullets(int amount){
    bullets = bullets + amount;
}