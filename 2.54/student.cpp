#include "student.h"
#include <iostream> 
#include <string>
#include <fstream>

using namespace std;

void trim(string &s) {
while (!s.empty() && isspace((unsigned char)s.front())) s.erase(s.begin());
while (!s.empty() && isspace((unsigned char)s.back())) s.pop_back();
}


void inputStudent(Student &s) {
cout << "Enter id: ";
cin >> s.id;
cin.ignore();


cout << "Enter full name: ";
getline(cin, s.fullname);
trim(s.fullname);


cout << "Enter GPA: ";
cin >> s.gpa;
cin.ignore();


cout << "Enter address: ";
getline(cin, s.address);
trim(s.address);

cout << "Enter date of birth: ";
cin >> s.dob.day >> s.dob.month >> s.dob.year;
}


void outputStudent(const Student &s) {
cout << "ID: " << s.id << "\n";
cout << "Full name: " << s.fullname << "\n";
cout << "GPA: " << s.gpa << "\n";
cout << "Address: " << s.address << "\n";
cout << "Date of birth: " << s.dob.day << "/" << s.dob.month << "/" <<   s.dob.year;
}


void writeToFile(ofstream &fout, const Student &s) {
fout << "Id: " << s.id << '\n';
fout << "Fullname: " << s.fullname << '\n';
fout << "Gpa: " << s.gpa << '\n';
fout << "Address: " << s.address << '\n';
fout << "Date of birth: " << s.dob.day << "/" << s.dob.month << "/" << s.dob.year;
}


void readFromFile(ifstream &fin, Student &s) {
    fin >> s.id;
    fin.ignore();

    getline(fin, s.fullname);
    getline(fin, s.address);

    fin >> s.gpa;
    fin.ignore();

    fin >> s.dob.day >> s.dob.month >> s.dob.year;
    fin.ignore();
}

void splitName(const string &full, string &first, string &last) {
    int pos = full.find(' ');
    if (pos == -1) {
        first = full;
        last = "";
    } else {
        first = full.substr(0, pos);
        last = full.substr(pos + 1);
    }
}
void outputStudentToFile(const string &filename, const Student &s) {
    string first, last;
    size_t pos = s.fullname.find(' ');
    if (pos == string::npos) {
        first = s.fullname;
        last = "";
    } else {
        first = s.fullname.substr(0, pos);
        last = s.fullname.substr(pos + 1);
    }

    string dob = to_string(s.dob.day) + "/" + to_string(s.dob.month) + "/" + to_string(s.dob.year);

    string age = "18 year 2 months, 2 days";

    ofstream fout(filename.c_str(), ios::app);
    if (!fout) return;

    fout << s.id << "," 
         << first << "," 
         << last << "," 
         << s.gpa << "," 
         << s.address << "," 
         << dob << "," 
         << age << "\n";

    fout.close();
}

string getClassFromId(const Student &s) {
    string digs;
    for (size_t i = 0; i < s.id.size() && digs.size() < 2; ++i) {
        char c = s.id[i];
        if (c >= '0' && c <= '9') digs.push_back(c);
        else break;
    }
    if (digs.size() >= 2) return string("K") + digs;
    return "K?";
}

int compareById(const Student &a, const Student &b) {
    if (a.id < b.id) return -1;
    if (a.id > b.id) return 1;
    return 0;
}

int compareByGpaThenId(const Student &a, const Student &b) {
    if (a.gpa < b.gpa) return -1;
    if (a.gpa > b.gpa) return 1;
    return compareById(a, b);
}

int compareByNameThenId(const Student &a, const Student &b) {
    if (a.fullname < b.fullname) return -1;
    if (a.fullname > b.fullname) return 1;
    return compareById(a, b);
}

int compareByFirstNameThenId(const Student &a, const Student &b) {
    string a1, a2, b1, b2;
    splitName(a.fullname, a1, a2);
    splitName(b.fullname, b1, b2);
    if (a1 < b1) return -1;
    if (a1 > b1) return 1;
    return compareById(a, b);
}

int compareByLastNameThenId(const Student &a, const Student &b) {
    string a1, a2, b1, b2;
    splitName(a.fullname, a1, a2);
    splitName(b.fullname, b1, b2);
    if (a2 < b2) return -1;
    if (a2 > b2) return 1;
    return compareById(a, b);
}

int compareByDobThenId(const Student &a, const Student &b) {
    if (a.dob.year != b.dob.year) return a.dob.year < b.dob.year ? -1 : 1;
    if (a.dob.month != b.dob.month) return a.dob.month < b.dob.month ? -1 : 1;
    if (a.dob.day != b.dob.day) return a.dob.day < b.dob.day ? -1 : 1;
    return compareById(a, b);
}
