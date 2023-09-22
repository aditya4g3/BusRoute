#include "Point2D.h"
#include "Strings.h"

#ifndef STUDENT_H
#define STUDENT_H

typedef struct{
    Point2D location;
    String name;
}Student;

Student* mallocStudent();
int setStudent(Student* s,FILE* in);
void freeStudent(Student* s);

#endif