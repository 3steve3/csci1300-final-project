#ifndef DISTANCE_H
#define DISTANCE_h
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Distance{
    private:
        static int nextMilestone;
        static int distance;
        string fileInput[100];
        string milestoneDistance[16];
        string milestoneName[16];
        int distances[16] = {102, 185, 304, 554, 640, 830, 932, 989, 1151, 1295, 1395, 1534, 1648, 1808, 1863, 2040};
    public:
        //constructor
        Distance();
        //setter
        bool travel(int amount);
        //getter
        int distanceTraveled();
        void printNextMilestone();
        bool isatMilestone();
        bool isatCamp();
        int getCampNumber();
        string returnNextMilestone();


};
#endif