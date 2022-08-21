#include "store.h"
#include "inventory.h"

Store::Store(){
        OxenPrice = 40;
        foodPrice = 0.5;
        bulletPrice = 2;
        wagonPartPrice = 20;
        medkitPrice = 25;
}
Store::Store(int location){
        //This will create prices based on which camp the player has stopped at
        double percentIncrease = location * 25;
        percentIncrease = percentIncrease / 100;
        OxenPrice = 40 * (percentIncrease + 1);
        foodPrice = 0.5 * (percentIncrease + 1);
        bulletPrice = 2 * (percentIncrease + 1);
        wagonPartPrice = 20 * (percentIncrease + 1);
        medkitPrice = 25 * (percentIncrease + 1);
}
double Store::getBullet(){
        return bulletPrice;
}
double Store::getFood(){
        return foodPrice;
}
double Store::getMedkit(){
        return medkitPrice;
}
double Store::getOxen(){
        return OxenPrice;
}
double Store::getWagon(){
        return wagonPartPrice;
}
