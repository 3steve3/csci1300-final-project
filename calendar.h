#ifndef CALENDAR_H
#define CALENDAR_H
#include <string>
using namespace std;
class Calendar{
    private:
    //index 0 will be month, index 1 will be day, index 2 will be year
    string processed[3];
    int day;
    int month;
    int year;
    string date;

    public:
    Calendar();
    Calendar(string input);
    void setDate(string input);
    bool increaseDays(int days);
    string getDate();
    static int split(string, char, string[], int);
};
#endif