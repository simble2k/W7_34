//25125080
//PHAM QUOC BAO
//25A02
#include "Course.h"
#include "date.h"
#include "student.h"
#include <iostream>
#include <fstream>
using namespace std;

void courseMenu(){
    cout << "\n============= Course Menu ============= \n";
    cout << "0. Exit program\n";
    cout << "1. Input a course (from text file)\n";
    cout << "2. Output a course (to text file)\n";
    cout << "3. Add a student to course\n";
    cout << "4. Remove a student from course\n";
    cout << "5. Student(s) born in this month\n";
    cout << "6. Student(s) born on this date\n";
    cout << "7. Student(s) legal to have driving licences\n";
    cout << "8. Find student(s) in K19 class (to text file)\n";
    cout << "9. Find student by id (to text file)\n";
    cout << "10. Find student by name (to text file)\n";
    cout << "11. Sort student by id (to text file)\n";
    cout << "12. Sort student by first name (to text file)\n";
    cout << "13. Sort student by gpa (to text file)\n";
    cout << "14. Sort student by date of birth (to text file)\n";  
    cout << "\n============= Course Menu ============= \n";
}

int main(){
    Course c;
    c.id = nullptr;
    c.name = nullptr;
    c.list = nullptr;
    c.currentStudent = 0;

    char* filename = new char[100];
    char* id = new char[100];
    char* name = new char[100];

    while(true){
        courseMenu();
        cout << "Enter your choice: ";
        int opt; cin >> opt;  
        cin.ignore();
        switch (opt)
        {
        case 0:
            cout << "Exiting program. See you again!";
            delete[] filename;
            delete[] id;
            delete[] name;
            deleteCourse(c);
            return 0;
        case 1:
            cout << "Enter filename: ";
            cin.get(filename,100);
            cin.ignore();
            inputCourse(c, filename);
            break;
        case 2:
            cout << "Enter filename: ";
            cin.get(filename,100);
            cin.ignore();
            outputCourse(c, filename);
            break;
        case 3:
            addStudent(c);
            break;
        case 4:
            cout << "Enter ID to remove: ";
            cin >> id;
            removeStudent(c, id);
            break;
        case 5:
            studentBornThisMonth(c);
            break;
        case 6:
            studentBornThisDate(c);
            break;
        case 7:
            studentLegalToDrive(c);
            break;
        case 8:
            cout << "Enter filename: ";
            cin.get(filename,100);
            cin.ignore();
            studentInK19Class(c, filename);
            break;
        case 9:
            cout << "Enter id to find: ";
            cin.get(id,100);
            cin.ignore();
            cout << "Enter filename: ";
            cin.get(filename,100);
            cin.ignore();
            findStudentByid(c, id, filename);
            break;
        case 10:
            cout << "Enter name to find: ";
            cin.get(name,100);
            cin.ignore();
            cout << "Enter filename: ";
            cin.get(filename,100);
            cin.ignore();
            findStudentByName(c, name, filename);
            break;
        case 11:
            cout << "Enter filename: ";
            cin.get(filename,100);
            cin.ignore();
            sortStudentById(c, filename);
            break;
        case 12:
            cout << "Enter filename: ";
            cin.get(filename,100);
            cin.ignore();
            sortStudentByFirstName(c, filename);
            break;
        case 13:
            cout << "Enter filename: ";
            cin.get(filename,100);
            cin.ignore();
            sortStudentByGpa(c, filename);
            break;
        case 14:
            cout << "Enter filename: ";
            cin.get(filename,100);
            cin.ignore();
            sortStudentByDob(c, filename);
            break;
        default:
            cout << "Please enter a valid option from 0 to 14";
            break;
        }
    }
}