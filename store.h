#ifndef STORE_H
#define STORE_H
#include <iostream>
using namespace std;
//this class is for finding out the prices for each fort
class Store{
    private:
        double OxenPrice;
        double foodPrice;
        double bulletPrice;
        double wagonPartPrice;
        double medkitPrice;

    public: 
        //constructors based on the location of the character
        Store();
        Store(int location);
        //there are no setters for the price
        //these getters will get the prices for the items
        double getOxen();
        double getFood();
        double getBullet();
        double getWagon();
        double getMedkit();

};
#endif