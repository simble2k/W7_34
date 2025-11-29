#pragma once
#include "student.h"
#include "date.h"

struct Course
{  
    char* id;         
    char* name;       
    Student* list;    
    bool open;
    int maxStudent, minStudent, currentStudent;
};

void deleteCourse(Course &c);

void inputCourse(Course &c, const char filename[]);
void outputCourse(const Course &c, const char filename[]);
void addStudent(Course &c);
void removeStudent(Course &c, const char id[]);

void studentBornThisMonth(const Course &c);
void studentBornThisDate(const Course &c);
void studentLegalToDrive(const Course &c);
void studentInK19Class(const Course &c, char filename[]);
void findStudentByid(const Course &c, char id[], char filename[]);
void findStudentByName(const Course &c, char name[], char filename[]);
void sortStudentById(const Course &c, char filename[]);
void sortStudentByFirstName(const Course &c, char filename[]);
void sortStudentByGpa(const Course &c, char filename[]);
void sortStudentByDob(const Course &c, char filename[]);