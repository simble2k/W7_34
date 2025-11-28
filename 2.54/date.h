#pragma once
#include <string>
using namespace std;
struct date{
    int day;
    int month;
    int year;
};
void inputDateFromConsole(date &Date);
void outputDateToConsole(const date &Date);
void inputDateFromTextFile(date &Date,const char filename[]);
void outputDateToTextFile(const date &Date,const char filename[]);
void outputDateWithFormat(const date &d, const string &format);
int compareTwoDate(const date &d1, const date &d2);
void findTomorrow(date &d1);
void findYesterday(date &d1);
void increaseDay(date &d1,int k);
void decreaseDay(date &d1,int k);
int daySinceStartOfYear(const date &d1);
int daySinceStartOf1970(const date &d1);
int dayBetweenDates(const date &d1, const date &d2);
string dateOfWeek(const date &d1);