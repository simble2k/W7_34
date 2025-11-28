#pragma once
#include <string>
#include "date.h"

using namespace std;

struct Student {
    string id;
    string fullname;
    double gpa;
    string address;
    date dob;
};

void inputStudent(Student &s);
void outputStudent(const Student &s);
void writeToFile(ofstream &fout, const Student &s);
void readFromFile(ifstream &fin, Student &s);
void outputStudentToFile(const string &filename, const Student &s);

void splitName(const string &full, string &first, string &last);
string getClassFromId(const Student &s);

int compareById(const Student &a, const Student &b);
int compareByGpaThenId(const Student &a, const Student &b);
int compareByNameThenId(const Student &a, const Student &b);
int compareByFirstNameThenId(const Student &a, const Student &b);
int compareByLastNameThenId(const Student &a, const Student &b);
int compareByDobThenId(const Student &a, const Student &b);
