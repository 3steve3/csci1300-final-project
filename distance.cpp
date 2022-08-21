#include "distance.h"
Distance::Distance(){
    int count = 0;
    ifstream file;
    file.open("milestones.txt");
    if(file.is_open()){
        string line;
        while(getline(file,line)){
            if((!line.empty())){
                fileInput[count] = line;
                count++;
            }
        }
    }
    if(!(file.is_open())){
        cout << "Milestone file could not be opened. Exiting Program." << endl;
        abort();
    }
    file.close();
    int j = 0;
    for(int i = 0; i < 16; i++){
        milestoneName[i] = fileInput[j];
        j++;
        milestoneDistance[i] = fileInput[j];
        j++;
    }
}
int Distance::distance = 0;
int Distance::nextMilestone = 0;
//this will return true if the player arrived at a milestone
bool Distance::travel(int amount){
    distance = distance + amount;
    if(distance >= 2040){
        distance = 2040;
        return 1;
    }
    if(distance > distances[nextMilestone]){
        distance = distances[nextMilestone];
        nextMilestone++;
        return 1;
    }
    return 0;
}
void Distance::printNextMilestone(){
    cout << "The next milestone is " << milestoneName[nextMilestone] << " in " << distances[nextMilestone] - distance << " miles." << endl;
}
string Distance::returnNextMilestone(){
    string output = "The next milestone is " + milestoneName[nextMilestone] + " in " + to_string(distances[nextMilestone] - distance) + " miles.";
    return output;
}
int Distance::distanceTraveled(){
    return distance;
}
bool Distance::isatCamp(){
    if (distance == 0 || distance == 304 || distance == 640 || distance == 989 || distance == 1395 || distance == 1648 || distance == 1863){
        return 1;
    }
    return 0;
}
int Distance::getCampNumber(){
    if (distance == 304){
        return 1;
    }
    if (distance == 640){
        return 2;
    }
    if (distance == 989){
        return 3;
    }
    if (distance == 1395){
        return 4;
    }
    if (distance == 1648){
        return 5;
    }
    if (distance == 1863){
        return 6;
    }
    else{return 1;}
}