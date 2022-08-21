#include "calendar.h"
#include <string>
int Calendar::split (string input, char sep, string indiv[], int arrSize){

    int arrayLocation = 0;
    int subPos = 0;
    int lengthSubstr = 0;
    for (int i = 0 ; i < input.length() ; i++){
        lengthSubstr++;
        if(input[i] == sep){
            indiv[arrayLocation] = input.substr(subPos, lengthSubstr-1);
            subPos = i + 1;
            lengthSubstr = 0;
            arrayLocation++;
       }
       if (i == input.length()-1){
           indiv[arrayLocation] = input.substr(input.length()-lengthSubstr, lengthSubstr);
           arrayLocation++;
       }
       if (arrayLocation > arrSize){
           return -1;
       }
      
    }
    if (arrayLocation == 0){
        return 1;
    }
    return arrayLocation;
}


Calendar::Calendar(){
    date = "3/28/1847";
}
Calendar::Calendar(string input){
    date = input;
}
bool Calendar::increaseDays(int days){
    Calendar::split(date,'/',processed,3);
    month = stoi(processed[0]);
    day = stoi(processed[1]);
    year = stoi(processed[2]);
    switch (month){
        case 1:{
            day = day + days;
            while(day > 31){
                month++;
                day = day - 31;
            }
            break;
        }
        case 2:{
            day = day + days;
            while(day > 28){
                month++;
                day = day - 28;
            }
            break;
        }
        case 3:{
            day = day + days;
            while(day > 31){
                month++;
                day = day - 31;
            }
            break;
        }
        case 4:{
            day = day + days;
            while(day > 30){
                month++;
                day = day - 30;
            }
            break;
        }
        case 5:{
            day = day + days;
            while(day > 31){
                month++;
                day = day - 31;
            }
            break;
        }
        case 6:{
            day = day + days;
            while(day > 30){
                month++;
                day = day - 30;
            }
            break;
        }
        case 7:{
            day = day + days;
            while(day > 31){
                month++;
                day = day - 31;
            }
            break;
        }
        case 8:{
            day = day + days;
            while(day > 31){
                month++;
                day = day - 31;
            }
            break;
        }
        case 9:{
            day = day + days;
            while(day > 30){
                month++;
                day = day - 30;
            }
            break;
        }
        case 10:{
            day = day + days;
            while(day > 31){
                month++;
                day = day - 31;
            }
            break;
        }
        case 11:{
            day = day + days;
            while(day > 30){
                month++;
                day = day - 30;
            }
            break;
        }
        case 12:{
            return 1;
            break;
        }
    }
    date = to_string(month) + "/" + to_string(day) + "/" + to_string(year);
    return 0;
}
string Calendar::getDate(){
    return date;
}
void Calendar::setDate(string input){
    date = input;
}