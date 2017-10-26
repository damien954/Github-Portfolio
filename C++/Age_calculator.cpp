#include <ctime>
#include <iostream>
using namespace std;
int main(){
    struct tm date = {0};
    int day, month, year;
    cout<<"Year: ";
    cin>>year;
    cout<<"Month: ";
    cin>>month;
    cout<<"Day: ";
    cin>>day;
    date.tm_year = year-1900;
    date.tm_mon  = month-1;
    date.tm_mday = day;
    time_t normal = mktime(&date);
    time_t current;
    time(&current);
    long d = (difftime(current, normal) + 86400L/2) / 86400L;
    cout<<"You are~: "<<d/365<<" years.\n";
    return (0);
}
