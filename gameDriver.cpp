//This is the main game file that contains all of the functions and brings together all of the classes
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <random>
#include "store.h"
#include "Person.h"
#include "calendar.h"
#include "inventory.h"
#include "distance.h"
void storeDriver (int campNumber){
Store store(campNumber);
Inventory items;
int input = 0;
cout << "Welcome to the shop." << endl;
cout << "Make your selection using the numbers then press enter" << endl;
while(input != 5){
cout << "You have $" << fixed << setprecision(2) << items.getMoney() << " to spend" << endl;
cout << "1. Oxen - You should have between 3 and 5 yokes of oxen. A yoke costs $40." << endl << "There are 2 oxen per yoke and you will gain an increase in travel speed if you have more oxen." << endl;
cout << "2. Food - You should have at least 200 lbs. of food. Food costs $0.5/lb" << endl;
cout << "3. Bullets - You can use bullets to hunt along the way for food. A box costs $2 and has 20 bullets" << endl;
cout << "4. Miscellaneous Supplies" << endl;
cout << "5. Exit" << endl;
cin >> input;
cin.ignore();
if (input < 1 && input > 5){
    cout << "Invalid Input." << endl;
}
    switch(input){
        case 1:{
            cout << "How many yokes do you want to buy?" << endl;
            int amount;
            cin >> amount;
            if (amount == 0){
                cout << "You have not purchased anything." << endl;
                break;
            }
            if (amount < 0){
                cout << "Invalid Input." << endl;
                break;
            }
            if (amount * 2 + items.getOxen() > 10 && amount < 6){
                cout << "You can't buy anymore oxen" << endl;
                break;
            }
            if (amount > 5){
                cout << "You can own a maximum of 5 yokes of oxen (10 oxen)" << endl;
                cout << "You currently have " << items.getOxen() << endl;
                int i = 0;
                for (int j = items.getOxen(); j < 10; j++){
                    i++;
                }
                i = i / 2;
                cout << "Do you want to purchase " << i << " yokes of oxen for $" << store.getOxen() * i  << " ?" << endl;
                cout << "Y/N" << endl;
                char select;
                cin >> select;
                cin.ignore();
                if(select == 'y' || select == 'Y'){
                    if(store.getOxen() > items.getMoney()){
                        cout << "You do not have emough money." << endl;
                        break;
                    }
                    cout << "You have purchased " << i << " yokes of oxen" << endl;
                    items.buyOxen(i);
                    items.spendMoney(store.getOxen() * i);
                    break;
                }
                if(select == 'n' || select == 'N'){
                    cout << "You have not purchased anything." << endl; 
                    break;
                }
            }
            else{
                if(store.getOxen() > items.getMoney()){
                        cout << "You do not have emough money." << endl;
                        break;
                    }
                cout << "Do you want to purchase " << amount << " yokes of oxen for $" << store.getOxen() * amount  << " ?" << endl;
                cout << "Y/N" << endl;
                char select;
                cin >> select;
                cin.ignore();
                if(select == 'y' || select == 'Y'){
                    if(store.getOxen() > items.getMoney()){
                        cout << "You do not have emough money." << endl;
                        break;
                    }
                    cout << "You have purchased " << amount << " yokes of oxen" << endl;
                    items.buyOxen(amount);
                    items.spendMoney(store.getOxen() * amount);
                    break;
                }
                if (select == 'n' || select == 'N'){
                    cout << "You have not purchased anything." << endl;
                    break;
                }
                

            }
            break;
        }
        case 2:{
            cout << "How many lbs. of food do you want to purchase?" << endl;
            int amount;
            cin >> amount;
            cin.ignore();
            if (amount < 0){
                cout << "Invalid input" << endl;
                break;
            }
            if(amount == 0){
                cout << "You have not purchased anything." << endl;
                break;
            }
            if(store.getFood()*amount > items.getMoney()){
                cout << "You do not have enough money" << endl;
                break;
            }
            if(items.getFood() + amount > 1000){
                cout << "You cannot have more than 1000 lbs. of food" << endl;
                break;
            }
            cout << "Do you want to purchase " << amount << " lbs. of food for $" << store.getFood()*amount << " ?" << endl;
            cout << "Y/N" << endl;
            char select;
            cin >> select;
            cin.ignore();
            if(select == 'y' || select == 'Y'){
                items.buyFood(amount);
                items.spendMoney(store.getFood()*amount);
                break;
            }
            if(select == 'n' || select == 'N'){
                break;
            }
            break;
            }
        case 3:{
            cout << "How many boxes of bullets would you like to buy? (20 bullets in a box with each box costing $2)" << endl;
            int amount;
            cin >> amount;
            cin.ignore();
            if (amount < 0){
                cout << "Invalid input" << endl;
                break;
            }
            if(amount == 0){
                cout << "You have not purchased anything." << endl;
                break;
            }
            if(store.getBullet()*amount > items.getMoney()){
                cout << "You do not have enough money" << endl;
                break;
            }
            cout << "Do you want to purchase " << amount << " boxes of bullets for $" << store.getBullet()*amount << " ?" << endl;
            cout << "Y/N" << endl;
            char select;
            cin >> select;
            cin.ignore();
            if(select == 'y' || select == 'Y'){
                items.buyBullets(amount);
                items.spendMoney(store.getBullet()*amount);
                break;
            }
            if(select == 'n' || select == 'N'){
                cout << "You have not purchased anything." << endl;
                break;
            }
            break;    
            
        }
        case 4:{
            int input2 = 0;
            while (input2 != 3){
                cout << "1. Wagon parts at $20 per part. If your wagon breaks and you have no parts you will be stranded." << endl;
                cout << "2. Medical kit at $25 per part. If someone gets sick, you can use a medical kit to reduce the chance of death." << endl;
                cout << "3. Back" << endl;
                cin >> input2;
                cin.ignore();
                switch(input2){
                    case 1:{
                        cout << "How many wagon part(s) would you like to buy?" << endl;
                        int amount;
                        cin >> amount;
                        cin.ignore();
                        if (amount < 0){
                            cout << "Invalid input" << endl;
                            break;
                        }
                        if(amount == 0){
                            cout << "You have not purchased anything." << endl;
                            break;
                        }
                        cout << "Do you want to buy " << amount << " wagon part(s) for $" << store.getWagon()*amount << "?" << endl;
                        cout << "Y/N" << endl;
                        char select;
                        cin >> select;
                        cin.ignore();
                        if(select == 'y' || select == 'Y'){
                            items.buyParts(amount);
                            items.spendMoney(store.getWagon()*amount);
                            break;
                        }
                        if(select == 'n' || select == 'N'){
                            cout << "You have not purchased anything." << endl;
                            break;
                        }
                        break;
                    }
                    case 2:{
                        cout << "How many medical kits(s) would you like to buy?" << endl;
                        int amount;
                        cin >> amount;
                        cin.ignore();
                        if (amount < 0){
                            cout << "Invalid input" << endl;
                            break;
                        }
                        if(amount == 0){
                            cout << "You have not purchased anything." << endl;
                            break;
                        }
                        cout << "Do you want to buy " << amount << " medical kits(s) for $" << store.getMedkit()*amount << "?" << endl;
                        cout << "Y/N" << endl;
                        char select;
                        cin >> select;
                        cin.ignore();
                        if(select == 'y' || select == 'Y'){
                            items.buyMedicine(amount);
                            items.spendMoney(store.getMedkit()*amount);
                            break;
                        }
                        if(select == 'n' || select == 'N'){
                            cout << "You have not purchased anything." << endl;
                            break;
                        }
                        break;
                    }
                    case 3:{break;}
                        
                }   

            }
        
    } 
    }
}
}
void printStats(string date, Person *traveler){
    Inventory items;
    Distance game;
    cout << "===================================================================" << endl;
    cout << "The current date is " << date << endl;
    cout << "Money: $" << fixed << setprecision(2) << items.getMoney() << setprecision(0) << "     Food: " << items.getFood() << " lbs.     Oxen: " << items.getOxen() << endl;
    cout << "Bullets: " << items.getBullets() << "      Wagon Parts: " << items.getParts() << "     Medicine: " << items.getMedicine() << endl;
    cout << "You have traveled " << game.distanceTraveled() << " miles." << endl;
    game.printNextMilestone();
    cout << "===================================================================" << endl;
    cout << traveler[0].getName(); if(traveler[0].sick()){cout << " is sick" << endl;}if(traveler[0].dead()){cout << " is dead" << endl;}if(!traveler[0].sick()&&!traveler[0].dead()){cout << " is healthy" << endl;}
    cout << traveler[1].getName(); if(traveler[1].sick()){cout << " is sick" << endl;}if(traveler[1].dead()){cout << " is dead" << endl;}if(!traveler[1].sick()&&!traveler[1].dead()){cout << " is healthy" << endl;}
    cout << traveler[2].getName(); if(traveler[2].sick()){cout << " is sick" << endl;}if(traveler[2].dead()){cout << " is dead" << endl;}if(!traveler[2].sick()&&!traveler[2].dead()){cout << " is healthy" << endl;}
    cout << traveler[3].getName(); if(traveler[3].sick()){cout << " is sick" << endl;}if(traveler[3].dead()){cout << " is dead" << endl;}if(!traveler[3].sick()&&!traveler[3].dead()){cout << " is healthy" << endl;}
    cout << traveler[4].getName(); if(traveler[4].sick()){cout << " is sick" << endl;}if(traveler[4].dead()){cout << " is dead" << endl;}if(!traveler[4].sick()&&!traveler[4].dead()){cout << " is healthy" << endl;}
    cout << "===================================================================" << endl;
}
void welcomeBanner(){
    cout << "   ____                               _______        _ _ " << endl;
    cout << "  / __ \\                             |__   __|      (_| |" << endl;
    cout << " | |  | |_ __ ___  __ _  ___  _ __      | |_ __ __ _ _| |" << endl;
    cout << " | |  | | '__/ _ \\/ _` |/ _ \\| '_ \\     | | '__/ _` | | |" << endl;
    cout << " | |__| | | |  __| (_| | (_) | | | |    | | | | (_| | | |" << endl;
    cout << "  \\____/|_|  \\___|\\__, |\\___/|_| |_|    |_|_|  \\__,_|_|_|" << endl;
    cout << "                   __/ |                                 " << endl;
    cout << "                  |___/                                  " << endl;
}
void raiderAttack(){
    Inventory items;
    Distance game;
    double probability;
    double distance = game.distanceTraveled();
    random_device gen;
    probability = ((pow(distance/100-4,2)+72)/(pow(distance/100-4,2)+12));
    probability = probability - 1;
    probability = probability / 0.10;
    bool attack = (gen() % 45) < probability;
    if (attack){
        int input = 0;
        while(input != 1 && input != 2 && input != 3){
            cout << "Raiders ahead. They look Hostile" << endl;
            cout << "1. Run" << endl;
            cout << "2. Attack" << endl;
            cout << "3. Surrender" << endl;
            cin >> input;
            cin.ignore();
            switch(input){
                case 1:{
                    items.loseOxen(1);
                    items.loseFood(10);
                    items.loseParts(1);
                    cout << "You were able to get away from the raiders, but in the process you lost 1 oxen, 10 lbs of food, 1 wagon part." << endl;
                    break;
                    
                }
                case 2:{
                    int num = gen() % 10 + 1;
                    //cout << num;
                    int input;
                    cout << "To win the battle, try to guess the number from 1 to 10. You have three attemps and the number does not change between attempts." << endl;
                    for (int i = 0; i < 3; i++){
                        cout << "Enter a number" << endl;
                        cin >> input;
                        cin.ignore();
                        if(input == num){
                            cout << "You guessed correct. You gained 50 lbs. of food and 50 bullets." << endl;
                            items.buyFood(50);
                            items.increaseBullets(50);
                            break; 
                        }
                    }
                    if(input != num){
                        cout << "The raiders took a quarter of your money and 50 bullets" << endl;
                        items.loseBullets(50);
                        items.spendMoney(items.getMoney()*0.25);
                    }
                    break;
                }
                case 3:{
                    cout << "The raiders took a quarter of your money" << endl;
                    items.spendMoney(items.getMoney()*0.25);
                    break;
                }
            }
            
        }
    }
}
void hunt(){
    cout << "You will go on a hunting trip today." << endl;
    Inventory items;
    random_device gen;
    bool rabbit = (gen() % 100) < 50;
    bool fox = (gen() % 100) < 25;
    bool deer = (gen() % 100) < 15;
    bool bear = (gen() % 100) < 7;
    bool moose = (gen() % 100) < 5;
    if(rabbit){
        int select = 0;
        cout << "You got lucky! You encountered a rabbit! Do you want to hunt?" << endl;
        while (select != 1 && select != 2){
            cout << "1. Yes,  2. No" << endl;
            cin >> select;
            cin.ignore();
            if(select == 1 && items.getBullets()< 10){
                cout << "You do not have enough bullets for this hunt" << endl;
            }
            if(select == 1 && items.getBullets() >= 10){
                int num = gen() % 10 + 1;
                int input;
                cout << "To successfully hunt, guess the number from 1 to 10. You have 3 guesses and the number remains the same between guesses." << endl;
                for (int i = 0; i < 3; i++){
                    cout << "Enter a number" << endl;
                    cin >> input;
                    cin.ignore();
                    if(input == num){
                        cout << "You guessed correct. You gained 5 lbs of food and used 10 bullets" << endl;
                        items.buyFood(5);
                        items.loseBullets(10);
                        
                    }
                }
                if(input != num){
                    cout << "The rabbit got away" << endl;
                }
            }
        }
        
    }
    if(fox){
        int select = 0;
        cout << "You got lucky! You encountered a fox! Do you want to hunt?" << endl;
        while (select != 1 && select != 2){
            cout << "1. Yes,  2. No" << endl;
            cin >> select;
            cin.ignore();
            if(select == 1 && items.getBullets()< 8){
                cout << "You do not have enough bullets for this hunt" << endl;
            }
            if(select == 1 && items.getBullets() >= 8){
                int num = gen() % 10 + 1;
                int input;
                cout << "To successfully hunt, guess the number from 1 to 10. You have 3 guesses and the number remains the same between guesses." << endl;
                for (int i = 0; i < 3; i++){
                    cout << "Enter a number" << endl;
                    cin >> input;
                    cin.ignore();
                    if(input == num){
                        cout << "You guessed correct. You gained 10 lbs of food and used 8 bullets" << endl;
                        items.buyFood(10);
                        items.loseBullets(8);
                        
                    }
                }
                if(input != num){
                    cout << "The fox got away" << endl;
                }
            }
        }
    }
    if(deer){
        int select = 0;
        cout << "You got lucky! You encountered a deer! Do you want to hunt?" << endl;
        while (select != 1 && select != 2){
            cout << "1. Yes,  2. No" << endl;
            cin >> select;
            cin.ignore();
            if(select == 1 && items.getBullets()< 10){
                cout << "You do not have enough bullets for this hunt" << endl;
            }
            if(select == 1 && items.getBullets() >= 10){
                int num = gen() % 10 + 1;
                int input;
                cout << "To successfully hunt, guess the number from 1 to 10. You have 3 guesses and the number remains the same between guesses." << endl;
                for (int i = 0; i < 3; i++){
                    cout << "Enter a number" << endl;
                    cin >> input;
                    cin.ignore();
                    if(input == num){
                        cout << "You guessed correct. You gained 5 lbs of food and used 10 bullets" << endl;
                        items.buyFood(5);
                        items.loseBullets(10);
                        
                    }
                }
                if(input != num){
                    cout << "The deer got away" << endl;
                }
            }
        }
    }
    if(bear){
        int select = 0;
        cout << "You got lucky! You encountered a bear! Do you want to hunt?" << endl;
        while (select != 1 && select != 2){
            cout << "1. Yes,  2. No" << endl;
            cin >> select;
            cin.ignore();
            if(select == 1 && items.getBullets()< 10){
                cout << "You do not have enough bullets for this hunt" << endl;
            }
            if(select == 1 && items.getBullets() >= 10){
                int num = gen() % 10 + 1;
                int input;
                cout << "To successfully hunt, guess the number from 1 to 10. You have 3 guesses and the number remains the same between guesses." << endl;
                for (int i = 0; i < 3; i++){
                    cout << "Enter a number" << endl;
                    cin >> input;
                    cin.ignore();
                    if(input == num){
                        cout << "You guessed correct. You gained 200 lbs of food and used 10 bullets" << endl;
                        items.buyFood(200);
                        items.loseBullets(10);
                        
                    }
                }
                if(input != num){
                    cout << "The bear got away" << endl;
                }
            }
        }
    }
    if(moose){
        int select = 0;
        cout << "You got lucky! You encountered a mosose! Do you want to hunt?" << endl;
        while (select != 1 && select != 2){
            cout << "1. Yes,  2. No" << endl;
            cin >> select;
            cin.ignore();
            if(select == 1 && items.getBullets()< 12){
                cout << "You do not have enough bullets for this hunt" << endl;
            }
            if(select == 1 && items.getBullets() >= 12){
                int num = gen() % 10 + 1;
                int input;
                cout << "To successfully hunt, guess the number from 1 to 10. You have 3 guesses and the number remains the same between guesses." << endl;
                for (int i = 0; i < 3; i++){
                    cout << "Enter a number" << endl;
                    cin >> input;
                    cin.ignore();
                    if(input == num){
                        cout << "You guessed correct. You gained 500 lbs of food and used 12 bullets" << endl;
                        items.buyFood(500);
                        items.loseBullets(12);
                        
                    }
                }
                if(input != num){
                    cout << "The moose got away" << endl;
                }
            }
        }
    }
    cout << "You have returned from your hunting trip." << endl;
    if(rabbit == 0 && fox == 0 && deer == 0 && bear == 0 && moose == 0){
        cout << "You have not encountered any animals on today's trip." << endl;
    }

}
bool misfortune(Person *traveler, Calendar game){
    Inventory items;
    random_device gen;
    bool misfortune = (gen() % 100) < 40;
    if(misfortune){
        int type = (gen() % 3);
        switch(type){
            case 0:{
                int person = (gen() % 5);
                if(!traveler[person].sick()&&!traveler[person].dead()){
                    traveler[person].setSick();
                    cout << traveler[person].getName() << " ate a pangolin and got coronavirus! :P" << endl;
                    bool death = (gen() % 2);
                    if(items.getMedicine() > 0){
                        bool death = (gen() % 2);
                        if(death){
                            cout << traveler[person].getName() << " wasn't in a great shape and died with corona" << endl;
                            traveler[person].setDeath();
                        }
                        if(!death){
                            cout << traveler[person].getName() << " managed to get better" << endl;
                            traveler[person].setHealed();
                        }
                    }
                    if(items.getMedicine() == 0){
                        cout << "You do not have any medicine. Do you want to rest or keep going?" << endl;
                        cout << "1. Rest" << endl;
                        cout << "2. Keep going" << endl;
                        string input;
                        while(input != "1" && input != "2"){
                            cin >> input;
                            if (input == "1"){
                                game.increaseDays(3);
                                bool death = (gen() % 100) < 30;
                                if(death){
                                    cout << traveler[person].getName() << " wasn't in a great shape and died with corona" << endl;
                                    traveler[person].setDeath();
                                }
                                if(!death){
                                    cout << traveler[person].getName() << " managed to get better" << endl;
                                    traveler[person].setHealed();
                                }
                            }
                            if (input == "2"){
                                break;
                            }
                        }
                    }
                }
                
                break;
            }
            case 1:{
                cout << "Your wagon broke" << endl;
                if(items.getParts() > 0){
                    cout << "You used one of your parts to fix the wagon." << endl;
                    items.loseParts(1);
                    break;
                }
                if(items.getParts() == 0){
                    cout << "You are out of parts and cannot continue on your journey" << endl;
                    return 1;
                }
                break;
            }
            case 2:{
                items.loseOxen(1);
                cout << "One of your oxen died. You have " << items.getOxen() << " oxen left." << endl;
                if(items.getOxen() == 0){
                    cout << "You don't have anymore oxen left and you can't continue on your journey." << endl;
                    return 1;
                }
                break;
            }
        }
    }
    return 0;
}

int main(){
    bool gameOver = 0;
    bool deadlinePass = 0;
    string temp;
    welcomeBanner();
    Person traveler[5];
    Calendar calendar;
    Distance game;
    Inventory items;
    int select = 0;
    int input= 0;
    int input2= 0;
    random_device gen;
    cout << "Enter the team leader's name" << endl;
    cin >> temp;
    traveler[0].setName(temp);
    cout << "Enter the name of traveling partner 1" << endl;
    cin >> temp;
    traveler[1].setName(temp);
    cout << "Enter the name of traveling partner 2" << endl;
    cin >> temp;
    traveler[2].setName(temp);
    cout << "Enter the name of traveling partner 3" << endl;
    cin >> temp;
    traveler[3].setName(temp);
    cout << "Enter the name of traveling partner 4" << endl;
    cin >> temp;
    traveler[4].setName(temp);
    cout << "You need to visit the store to get ready for the journey." << endl;
    storeDriver(0);
    cout << "The default departure date is 3/28/1847. Would you like to select a different date? (between 3/1/1847 and 5/1/1847)" << endl;
    while(select != 1 && select != 2){
        cout << "1. yes  2. no" << endl;
        cin >> select;
        cin.ignore();
        if(select == 1){
            int month;
            int day;
            cout << "Input the date as month/day/year" << endl;
            cin >> temp;
            calendar.setDate(temp);
        }
    }
    input = 0;
        while(input != 5 && !gameOver){
            printStats(calendar.getDate(), traveler);
            cout << "1. Rest" << endl;
            cout << "2. Continue on the trail" << endl;
            cout << "3. Hunt" << endl;
            for(int i = 0; i < 5; i++){
                if(traveler[i].sick() && !traveler[i].dead()){
                    bool death = (gen() % 100) < 70;
                    if(death){
                        cout << traveler[i].getName() << " wasn't in a great shape and died with corona" << endl;
                        traveler[i].setDeath();
                    }
                    if(!death){
                        cout << traveler[i].getName() << " managed to get better" << endl;
                        traveler[i].setHealed();
                    }
                }
            }
            if(game.isatCamp()){
                cout << "4. Store" << endl;
            }
            cout << "5. Quit the game" << endl;
            cin >> input;
            if(input == 1){
                cout << "You will rest for 2 days" << endl;;
                calendar.increaseDays(2);
                items.loseFood(6*(!traveler[0].dead()+!traveler[1].dead()+!traveler[2].dead()+!traveler[3].dead()+!traveler[4].dead()));
            }
            if(input == 2){
                calendar.increaseDays(14);
                items.loseFood(14*3*(!traveler[0].dead()+!traveler[1].dead()+!traveler[2].dead()+!traveler[3].dead()+!traveler[4].dead()));
                game.travel(75+(items.getOxen()*7));
            }
            if(input == 3){
                hunt();
            }
            if(input == 4 && game.isatCamp()){
                storeDriver(game.getCampNumber());
            }
            if(input == 5){
                gameOver = 1;
                break;
            }
            if (items.getFood() == 0){
                cout << "You are out of food" << endl;
                gameOver = 1;
                break;
            }
            misfortune(traveler, calendar);
            if (traveler[0].dead()){
                gameOver = 1;
                break;
            }
            gameOver = game.travel(0);
            raiderAttack();
            
        }
        ofstream file;
        file.open("results.txt");
        if(file.is_open()){
            file << traveler[0].getName() << endl;
            file << "===================================================================" << endl;
            file << "The current date is " << calendar.getDate() << endl;
            file << "Money: $" << fixed << setprecision(2) << items.getMoney() << setprecision(0) << "     Food: " << items.getFood() << " lbs.     Oxen: " << items.getOxen() << endl;
            file << "Bullets: " << items.getBullets() << "      Wagon Parts: " << items.getParts() << "     Medicine: " << items.getMedicine() << endl;
            file << "You have traveled " << game.distanceTraveled() << " miles." << endl;
            file << game.returnNextMilestone() << endl;
            file << "===================================================================" << endl;
            file << traveler[0].getName(); if(traveler[0].sick()){file << " is sick" << endl;}if(traveler[0].dead()){file << " is dead" << endl;}if(!traveler[0].sick()&&!traveler[0].dead()){file << " is healthy" << endl;}
            file << traveler[1].getName(); if(traveler[1].sick()){file << " is sick" << endl;}if(traveler[1].dead()){file << " is dead" << endl;}if(!traveler[1].sick()&&!traveler[1].dead()){file << " is healthy" << endl;}
            file << traveler[2].getName(); if(traveler[2].sick()){file << " is sick" << endl;}if(traveler[2].dead()){file << " is dead" << endl;}if(!traveler[2].sick()&&!traveler[2].dead()){file << " is healthy" << endl;}
            file << traveler[3].getName(); if(traveler[3].sick()){file << " is sick" << endl;}if(traveler[3].dead()){file << " is dead" << endl;}if(!traveler[3].sick()&&!traveler[3].dead()){file << " is healthy" << endl;}
            file << traveler[4].getName(); if(traveler[4].sick()){file << " is sick" << endl;}if(traveler[4].dead()){file << " is dead" << endl;}if(!traveler[4].sick()&&!traveler[4].dead()){file << " is healthy" << endl;}
            file << "===================================================================" << endl;
        }

}