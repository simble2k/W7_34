#pragma once
#include "student.h"
#include "date.h"
struct Course
{  
    char id[100], name[100];
    Student list[100];
    bool open;
    int maxStudent, minStudent, currentStudent;
};
void inputCourse(Course &c, Student list[], const char filename[]);
void outputCourse(const Course &c, const Student list[], const char filename[]);
void addStudent(Course &c, Student list[]);
void removeStudent(Course &c, Student list[], const char id[]);
void studentBornThisMonth(const Course &c, const Student list[]);
void studentBornThisDate(const Course &c, const Student list[]);
void studentLegalToDrive(const Course &c, const Student list[]);
void studentInK19Class(const Course &c, const Student list[], char filename[]);
void findStudentByid(const Course &c, const Student list[],char id[], char filename[]);
void findStudentByName(const Course &c, const Student list[],char name[], char filename[]);
void sortStudentById(const Course &c, Student list[],char filename[]);
void sortStudentByFirstName(const Course &c, Student list[], char filename[]);
void sortStudentByGpa(const Course &c, Student list[],char filename[]);
void sortStudentByDob(const Course &c, Student list[],char filename[]);