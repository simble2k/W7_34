#include "Course.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <cstring>
using namespace std;

void inputCourse(Course &c, Student list[], const char filename[]){
    ifstream fin(filename);
    if(!fin) return;

    c.currentStudent = 0;

    fin.get(c.id, 100);
    fin.ignore();

    fin.get(c.name, 100);
    fin.ignore();

    fin >> c.currentStudent;
    fin.ignore();

    for(int i = 0; i < c.currentStudent; i++){
        readFromFile(fin, list[i]);
    }

    fin >> c.open;
    fin.ignore();

    fin >> c.maxStudent >> c.minStudent;

    fin.close();
}

void outputCourse(const Course &c, const Student list[], const char filename[]){
    ofstream fout(filename);
    if(!fout) return;
    fout << "Course id: " << c.id << '\n';
    fout << "Course name: " << c.name << '\n';
    for(int i = 0; i < c.currentStudent; i++){
        writeToFile(fout, list[i]);
        fout << '\n';
    }
    fout.close();
}
void addStudent(Course &c, Student list[]){
    if(c.currentStudent == c.maxStudent) cout << "Maximum number of student. Can't add more student to this course";
    else{
        inputStudent(list[c.currentStudent]);
        c.currentStudent++;
    }
}
void removeStudent(Course &c, Student list[], const char id[]) {
    int pos = -1;

    for (int i = 0; i < c.currentStudent; i++) {
        if (list[i].id == id) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        cout << "Student not found!\n";
        return;
    }

    for (int i = pos; i < c.currentStudent - 1; i++) {
        list[i] = list[i + 1];
    }

    c.currentStudent--;
    cout << "Student removed successfully.\n";
    if(c.currentStudent < c.minStudent) c.open = false;
}
void studentBornThisMonth(const Course &c,const Student list[]){
    date today;

    auto now = chrono::system_clock::now();
    time_t t = chrono::system_clock::to_time_t(now);
    tm *local = localtime(&t);

    today.day = local->tm_mday;
    today.month = local->tm_mon + 1;
    today.year = local->tm_year + 1900;
    int n = 0;
    for(int i = 0; i < c.currentStudent; i++){
        if(list[i].dob.month == today.month) {
            outputStudent(list[i]);
            cout << '\n';
            n++;
    }
    }
    if (n == 0) cout << "No student born in this month";
}
void studentBornThisDate(const Course &c, const Student list[]){
    date today;

    auto now = chrono::system_clock::now();
    time_t t = chrono::system_clock::to_time_t(now);
    tm *local = localtime(&t);

    today.day = local->tm_mday;
    today.month = local->tm_mon + 1;
    today.year = local->tm_year + 1900;
    int n = 0;
    for(int i = 0; i < c.currentStudent; i++){
        if(list[i].dob.month == today.month && list[i].dob.day == today.day) {
            outputStudent(list[i]);
            cout << '\n';
            n++;
    }
    }
    if (n == 0) cout << "No student born in this date";
}
void studentLegalToDrive(const Course &c, const Student list[]){
    date today;

    auto now = chrono::system_clock::now();
    time_t t = chrono::system_clock::to_time_t(now);
    tm *local = localtime(&t);

    today.day = local->tm_mday;
    today.month = local->tm_mon + 1;
    today.year = local->tm_year + 1900;
    int n = 0;
    for(int i = 0; i < c.currentStudent; i++){
        if(list[i].dob.year - today.year >= 18 && list[i].dob.month >= today.month && list[i].dob.day >= today.day) {
            outputStudent(list[i]);
            cout << '\n';
            n++;
    }
    }
    if (n == 0) cout << "No student legal to drive";
}
void studentInK19Class(const Course &c, const Student list[], char filename[]){
    ofstream fout(filename);
    int n = 0;
    for(int i =0; i < c.currentStudent; i++){
        if(getClassFromId(list[i]) == "K19"){
            writeToFile(fout,list[i]);
            n++;
        }
    }
    if (n == 0) fout << "No student in K19 class";
    fout.close();
}
void findStudentByid(const Course &c, const Student list[],char id[], char filename[]){
    ofstream fout(filename);
    int n = 0;
    for(int i = 0; i < c.currentStudent; i++){
        if(list[i].id == id){writeToFile(fout, list[i]);
        n++;
        break;
        }
    }
    if(n == 0) fout << "Student not found";
    fout.close();
}
bool isSubStr(string s1, char s2[]) {
    int n = s1.size();
    int m = strlen(s2);

    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && s1[i + j] == s2[j]) {
            j++;
        }
        if (j == m) return true;
    }

    return false;
}
void findStudentByName(const Course &c, const Student list[], char name[], char filename[]){
    ofstream fout(filename);
    int n = 0;
    for(int i = 0; i < c.currentStudent; i++){
        if (isSubStr(list[i].fullname,name)){
            writeToFile(fout,list[i]);
            n++;
        }
    }
    if(n == 0) fout << "Student not found!";
    fout.close();
}
void sortStudentById(const Course &c,Student list[],char filename[]){
    ofstream fout(filename);
    for(int i = 0; i < c.currentStudent - 1; i++){
        for(int j = i + 1; j < c.currentStudent; j++){
            if(list[i].id > list[j].id) swap(list[i],list[j]);
        }
   }
   for(int i = 0; i < c.currentStudent; i++){ 
        writeToFile(fout,list[i]);
        fout << '\n';
   }
   fout.close();
}
void sortStudentByFirstName(const Course &c, Student list[], char filename[]){
    ofstream fout(filename);
    for(int i = 0; i < c.currentStudent - 1; i++){
        for(int j = i + 1; j < c.currentStudent; j++){
            string first1,last1,first2,last2;
            splitName(list[i].fullname,first1,last1);
            splitName(list[j].fullname,first2,last2);
            if(first1 > first2) swap(list[i],list[j]);
        }
   }
   for(int i = 0; i < c.currentStudent; i++){ 
        writeToFile(fout,list[i]);
        fout << '\n';
   }
   fout.close();
}
void sortStudentByGpa(const Course &c, Student list[],char filename[]){
    ofstream fout(filename);
    for(int i = 0; i < c.currentStudent - 1; i++){
        for(int j = i + 1; j < c.currentStudent; j++){
            if(list[i].gpa > list[j].gpa) swap(list[i],list[j]);
        }
   }
   for(int i = 0; i < c.currentStudent; i++){ 
        writeToFile(fout,list[i]);
        fout << '\n';
   }
   fout.close();
}
void sortStudentByDob(const Course &c, Student list[],char filename[]){
    ofstream fout(filename);
    for(int i = 0; i < c.currentStudent - 1; i++){
        for(int j = i + 1; j < c.currentStudent; j++){
            if(compareTwoDate(list[i].dob,list[j].dob) == 1) swap(list[i],list[j]);
        }
   }
   for(int i = 0; i < c.currentStudent; i++){ 
        writeToFile(fout,list[i]);
        fout << '\n';
   }
   fout.close();
}