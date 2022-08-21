#ifndef INVENTORY_H
#define INVENTORY_h
#include <iostream>
using namespace std;
class Inventory{
    private:
        static double money;
        static int oxen;
        static int food;
        static int bullets;
        static int medicine;
        static int parts;
    public:
        Inventory();
        //setters
        void spendMoney(double amount);
        void buyOxen(int amount);
        void buyFood(int amount);
        void buyBullets(int amount);
        void buyMedicine(int amount);
        void buyParts(int amount);
        void loseOxen(int amount);
        void loseFood(int amount);
        void loseBullets(int amount);
        void loseMedicine(int amount);
        void loseParts(int amount);
        void increaseBullets(int amount);
        //getters
        double getMoney();
        int getOxen();
        int getFood();
        int getBullets();
        int getMedicine();
        int getParts();
};
#endif
