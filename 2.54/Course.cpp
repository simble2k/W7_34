#include "Course.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <cstring>
using namespace std;

void deleteCourse(Course &c) {
    if (c.list != nullptr) {
        delete[] c.list;
        c.list = nullptr;
    }
    if (c.id != nullptr) {
        delete[] c.id;
        c.id = nullptr;
    }
    if (c.name != nullptr) {
        delete[] c.name;
        c.name = nullptr;
    }
    c.currentStudent = 0;
}

void inputCourse(Course &c, const char filename[]){
    ifstream fin(filename);
    if(!fin) return;
    c.id = new char[100];
    c.name = new char[100];
    c.currentStudent = 0;

    fin.get(c.id, 100);
    fin.ignore();

    fin.get(c.name, 100);
    fin.ignore();

    fin >> c.currentStudent;
    fin.ignore();

    c.list = new Student[c.currentStudent];

    for(int i = 0; i < c.currentStudent; i++){
        readFromFile(fin, c.list[i]);
    }

    fin >> c.open;
    fin.ignore();

    fin >> c.maxStudent >> c.minStudent;

    fin.close();
}

void outputCourse(const Course &c, const char filename[]){
    ofstream fout(filename);
    if(!fout) return;
    fout << "Course id: " << c.id << '\n';
    fout << "Course name: " << c.name << '\n';
    for(int i = 0; i < c.currentStudent; i++){
        writeToFile(fout, c.list[i]);
        fout << '\n';
    }
    fout.close();
}

void addStudent(Course &c){
    if(c.currentStudent >= c.maxStudent) {
        cout << "Maximum number of student. Can't add more student to this course";
    }
    else {
        Student* newList = new Student[c.currentStudent + 1];

        for(int i = 0; i < c.currentStudent; i++) {
            newList[i] = c.list[i];
        }

        delete[] c.list;

        c.list = newList;

        inputStudent(c.list[c.currentStudent]);
        c.currentStudent++;
    }
}

void removeStudent(Course &c, const char id[]) {
    int pos = -1;

    for (int i = 0; i < c.currentStudent; i++) {
        if (c.list[i].id == id) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        cout << "Student not found!\n";
        return;
    }

    for (int i = pos; i < c.currentStudent - 1; i++) {
        c.list[i] = c.list[i + 1];
    }

    c.currentStudent--;
    cout << "Student removed successfully.\n";
    if(c.currentStudent < c.minStudent) c.open = false;

}

void studentBornThisMonth(const Course &c){
    date today;

    auto now = chrono::system_clock::now();
    time_t t = chrono::system_clock::to_time_t(now);
    tm *local = localtime(&t);

    today.day = local->tm_mday;
    today.month = local->tm_mon + 1;
    today.year = local->tm_year + 1900;
    int n = 0;
    for(int i = 0; i < c.currentStudent; i++){
        if(c.list[i].dob.month == today.month) {
            outputStudent(c.list[i]);
            cout << '\n';
            n++;
        }
    }
    if (n == 0) cout << "No student born in this month";
}

void studentBornThisDate(const Course &c){
    date today;

    auto now = chrono::system_clock::now();
    time_t t = chrono::system_clock::to_time_t(now);
    tm *local = localtime(&t);

    today.day = local->tm_mday;
    today.month = local->tm_mon + 1;
    today.year = local->tm_year + 1900;
    int n = 0;
    for(int i = 0; i < c.currentStudent; i++){
        if(c.list[i].dob.month == today.month && c.list[i].dob.day == today.day) {
            outputStudent(c.list[i]);
            cout << '\n';
            n++;
        }
    }
    if (n == 0) cout << "No student born in this date";
}

void studentLegalToDrive(const Course &c){
    date today;

    auto now = chrono::system_clock::now();
    time_t t = chrono::system_clock::to_time_t(now);
    tm *local = localtime(&t);

    today.day = local->tm_mday;
    today.month = local->tm_mon + 1;
    today.year = local->tm_year + 1900;
    int n = 0;
    for(int i = 0; i < c.currentStudent; i++){
        if(c.list[i].dob.year - today.year >= 18 && c.list[i].dob.month >= today.month && c.list[i].dob.day >= today.day) {
            outputStudent(c.list[i]);
            cout << '\n';
            n++;
        }
    }
    if (n == 0) cout << "No student legal to drive";
}

void studentInK19Class(const Course &c, char filename[]){
    ofstream fout(filename);
    int n = 0;
    for(int i =0; i < c.currentStudent; i++){
        if(getClassFromId(c.list[i]) == "K19"){
            writeToFile(fout, c.list[i]);
            n++;
        }
    }
    if (n == 0) fout << "No student in K19 class";
    fout.close();
}

void findStudentByid(const Course &c, char id[], char filename[]){
    ofstream fout(filename);
    int n = 0;
    for(int i = 0; i < c.currentStudent; i++){
        if(c.list[i].id == id){
            writeToFile(fout, c.list[i]);
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

void findStudentByName(const Course &c, char name[], char filename[]){
    ofstream fout(filename);
    int n = 0;
    for(int i = 0; i < c.currentStudent; i++){
        if (isSubStr(c.list[i].fullname, name)){
            writeToFile(fout, c.list[i]);
            n++;
        }
    }
    if(n == 0) fout << "Student not found!";
    fout.close();
}

void sortStudentById(const Course &c, char filename[]){
    ofstream fout(filename);
    for(int i = 0; i < c.currentStudent - 1; i++){
        for(int j = i + 1; j < c.currentStudent; j++){
            if(c.list[i].id > c.list[j].id) swap(c.list[i], c.list[j]);
        }
   }
   for(int i = 0; i < c.currentStudent; i++){ 
        writeToFile(fout, c.list[i]);
        fout << '\n';
   }
   fout.close();
}

void sortStudentByFirstName(const Course &c, char filename[]){
    ofstream fout(filename);
    for(int i = 0; i < c.currentStudent - 1; i++){
        for(int j = i + 1; j < c.currentStudent; j++){
            string first1, last1, first2, last2;
            splitName(c.list[i].fullname, first1, last1);
            splitName(c.list[j].fullname, first2, last2);
            if(first1 > first2) swap(c.list[i], c.list[j]);
        }
   }
   for(int i = 0; i < c.currentStudent; i++){ 
        writeToFile(fout, c.list[i]);
        fout << '\n';
   }
   fout.close();
}

void sortStudentByGpa(const Course &c, char filename[]){
    ofstream fout(filename);
    for(int i = 0; i < c.currentStudent - 1; i++){
        for(int j = i + 1; j < c.currentStudent; j++){
            if(c.list[i].gpa > c.list[j].gpa) swap(c.list[i], c.list[j]);
        }
   }
   for(int i = 0; i < c.currentStudent; i++){ 
        writeToFile(fout, c.list[i]);
        fout << '\n';
   }
   fout.close();
}

void sortStudentByDob(const Course &c, char filename[]){
    ofstream fout(filename);
    for(int i = 0; i < c.currentStudent - 1; i++){
        for(int j = i + 1; j < c.currentStudent; j++){
            if(compareTwoDate(c.list[i].dob, c.list[j].dob) == 1) swap(c.list[i], c.list[j]);
        }
   }
   for(int i = 0; i < c.currentStudent; i++){ 
        writeToFile(fout, c.list[i]);
        fout << '\n';
   }
   fout.close();
}