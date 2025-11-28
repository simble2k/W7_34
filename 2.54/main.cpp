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
    Student s[100];
    char filename[100];
    char id[100];
    char name[100];

    while(true){
        courseMenu();
        cout << "Enter your choice: ";
        int opt; cin >> opt;  
        cin.ignore();
        switch (opt)
        {
        case 0:
            cout << "Exiting program. See you again!";
            return 0;
        case 1:
            cout << "Enter filename: ";
            cin.get(filename,100);
            cin.ignore();
            inputCourse(c,s,filename);
            break;
        case 2:
            cout << "Enter filename: ";
            cin.get(filename,100);
            cin.ignore();
            outputCourse(c,s,filename);
            break;
        case 3:
            addStudent(c,s);
            break;
        case 4:
            cout << "Enter ID to remove: ";
            cin >> id;
            removeStudent(c, s, id);
            break;
        case 5:
            studentBornThisMonth(c,s);
            break;
        case 6:
            studentBornThisDate(c,s);
            break;
        case 7:
            studentLegalToDrive(c,s);
            break;
        case 8:
            cout << "Enter filename: ";
            cin.get(filename,100);
            cin.ignore();
            studentInK19Class(c,s,filename);
            break;
        case 9:
            cout << "Enter id to find: ";
            cin.get(id,100);
            cin.ignore();
            cout << "Enter filename: ";
            cin.get(filename,100);
            cin.ignore();
            findStudentByid(c,s,id,filename);
            break;
        case 10:
            cout << "Enter name to find: ";
            cin.get(name,100);
            cin.ignore();
            cout << "Enter filename: ";
            cin.get(filename,100);
            cin.ignore();
            findStudentByName(c,s,name,filename);
            break;
        case 11:
            cout << "Enter filename: ";
            cin.get(filename,100);
            cin.ignore();
            sortStudentById(c,s,filename);
            break;
        case 12:
            cout << "Enter filename: ";
            cin.get(filename,100);
            cin.ignore();
            sortStudentByFirstName(c,s,filename);
            break;
        case 13:
            cout << "Enter filename: ";
            cin.get(filename,100);
            cin.ignore();
            sortStudentByGpa(c,s,filename);
            break;
        case 14:
            cout << "Enter filename: ";
            cin.get(filename,100);
            cin.ignore();
            sortStudentByDob(c,s,filename);
            break;
        default:
            cout << "Please enter a valid option from 0 to 14";
            break;
        }
    }
}