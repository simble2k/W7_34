#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include "date.h"
using namespace std;

void inputDateFromConsole(date &Date){
    cout << "Enter day: ";
    cin >> Date.day;
    cout << "Enter month: ";
    cin >> Date.month;
    cout << "Enter year: ";
    cin >> Date.year;
}
void outputDateToConsole(const date &Date){
    cout << Date.day << '/' << Date.month << '/' << Date.year;
}
void inputDateFromTextFile(date &Date,const char filename[]){
    ifstream fin;
    fin.open(filename);
    fin >> Date.day >> Date.month >> Date.year;
    fin.close();
}
void outputDateToTextFile(const date &Date,const char filename[]){
    ofstream fout;
    fout.open(filename);
    fout << Date.year << '/' << Date.month << '/' << Date.day;
    fout.close();
}
void outputDateWithFormat(const date &d, const string &format) {
    static string months[12] = {
        "Jan","Feb","Mar","Apr","May","Jun",
        "Jul","Aug","Sep","Oct","Nov","Dec"
    };

    string result;
    for (size_t i = 0; i < format.size(); ) {

        if (format.compare(i, 4, "yyyy") == 0) {
            result += to_string(d.year);
            i += 4;
        }
        else if (format.compare(i, 2, "yy") == 0) {
            int yy = d.year % 100;
            if (yy < 10) result += "0";
            result += to_string(yy);
            i += 2;
        }
        else if (format.compare(i, 3, "MMM") == 0) {
            result += months[d.month - 1];
            i += 3;
        }
        else if (format.compare(i, 2, "MM") == 0) {
            if (d.month < 10) result += "0";
            result += to_string(d.month);
            i += 2;
        }
        else if (format.compare(i, 1, "M") == 0) {
            result += to_string(d.month);
            i += 1;
        }
        else if (format.compare(i, 2, "dd") == 0) {
            if (d.day < 10) result += "0";
            result += to_string(d.day);
            i += 2;
        }
        else if (format.compare(i, 1, "d") == 0) {
            result += to_string(d.day);
            i += 1;
        }
        else {
            result += format[i];
            i++;
        }
    }

    cout << result;
}
int compareTwoDate(const date &d1, const date &d2) {
    if (d1.year < d2.year) return -1;
    if (d1.year > d2.year) return 1;

    if (d1.month < d2.month) return -1;
    if (d1.month > d2.month) return 1;

    if (d1.day < d2.day) return -1;
    if (d1.day > d2.day) return 1;

    return 0;
}
void findTomorrow(date &d1) {
    int m[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    
    bool leap = (d1.year % 400 == 0 || (d1.year % 100 != 0 && d1.year % 4 == 0));
    if (leap) m[1] = 29;

    if (d1.day < m[d1.month - 1]) {
        d1.day++;
    } else {
        d1.day = 1;
        if (d1.month == 12) {
            d1.month = 1;
            d1.year++;
        } else {
            d1.month++;
        }
    }
}
void findYesterday(date &d1) {
    int m[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    
    bool leap = (d1.year % 400 == 0 || (d1.year % 100 != 0 && d1.year % 4 == 0));
    if (leap) m[1] = 29;

    if (d1.day > 1) {
        d1.day--;
    } else {
        if (d1.month == 1) {
            d1.month = 12;
            d1.year--;
        } else {
            d1.month--;
        }

        leap = (d1.year % 400 == 0 || (d1.year % 100 != 0 && d1.year % 4 == 0));
        if (leap) m[1] = 29;
        else m[1] = 28;

        d1.day = m[d1.month - 1];
    }
}
void increaseDay(date &d1, int k) {
    int m[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    while (k > 0) {
        bool leap = (d1.year % 400 == 0 || (d1.year % 100 != 0 && d1.year % 4 == 0));
        m[1] = leap ? 29 : 28;

        int daysInMonth = m[d1.month - 1];
        int remaining = daysInMonth - d1.day;

        if (k <= remaining) {
            d1.day += k;
            k = 0;
        } else {
            k -= (remaining + 1);
            d1.day = 1;
            if (d1.month == 12) {
                d1.month = 1;
                d1.year++;
            } else {
                d1.month++;
            }
        }
    }
}
void decreaseDay(date &d1, int k) {
    int m[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    while (k > 0) {
        bool leap = (d1.year % 400 == 0 || (d1.year % 100 != 0 && d1.year % 4 == 0));
        m[1] = leap ? 29 : 28;

        if (k < d1.day) {
            d1.day -= k;
            k = 0;
        } else {
            k -= d1.day;
            if (d1.month == 1) {
                d1.month = 12;
                d1.year--;
            } else {
                d1.month--;
            }

            leap = (d1.year % 400 == 0 || (d1.year % 100 != 0 && d1.year % 4 == 0));
            m[1] = leap ? 29 : 28;

            d1.day = m[d1.month - 1];
        }
    }
}
int daySinceStartOfYear(const date &d1){
    int m[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    bool leap = (d1.year % 400 == 0 || (d1.year % 100 != 0 && d1.year % 4 == 0));
    if (leap) m[1] = 29;
    int sum = d1.day;
    for(int i = 0; i < d1.month - 1; i++){
        sum += m[i];
    }
    return sum;
}
static bool isLeap(int y) {
    return (y % 400 == 0) || (y % 100 != 0 && y % 4 == 0);
}

int daySinceStartOf1970(const date &d) {
    const int mdays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int days = 0;

    if (d.year >= 1970) {
        for (int y = 1970; y < d.year; ++y) days += isLeap(y) ? 366 : 365;
        for (int m = 1; m < d.month; ++m) {
            if (m == 2 && isLeap(d.year)) days += 29;
            else days += mdays[m-1];
        }
        days += (d.day - 1);
    } else {
        for (int y = d.year; y < 1970; ++y) days -= isLeap(y) ? 366 : 365;

        int daysFromYearStart = 0;
        for (int m = 1; m < d.month; ++m) {
            if (m == 2 && isLeap(d.year)) daysFromYearStart += 29;
            else daysFromYearStart += mdays[m-1];
        }
        daysFromYearStart += (d.day - 1);

        days += daysFromYearStart;
    }

    return days;
}

int dayBetweenDates(const date &d1, const date &d2) {

    int total1 = daySinceStartOf1970(d1);
    int total2 = daySinceStartOf1970(d2);

    return (total2 - total1) > 0 ? (total2 - total1) : (total1 - total2) ;
}
string dateOfWeek(const date &d1) {
    static string s[7] = {
        "Thursday","Friday","Saturday","Sunday",
        "Monday","Tuesday","Wednesday"
    };

    long long d = daySinceStartOf1970(d1);
    int idx = (d % 7 + 7) % 7;

    return s[idx];
}

