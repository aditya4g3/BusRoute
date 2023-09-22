#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Point2D.h"
#include"Strings.h"
#include"BusRoute.h"
#include"Student.h"

#define SIZE 100

Student* mallocStudent(){
    Student* s;
    s = (Student*)malloc(sizeof(Student));
    s->name = mallocString(SIZE);
    return s;
}

/*
function that sets student details from the specified file.
returns 1 if coordinates and name are set successfully and 0 if 
coordinates couldn't be read successfully.
*/
int setStudent(Student* s,FILE* in){
    Point2D* set = fscanfPoint2D(in);
    if(set == (Point2D*)NULL){return 0;}
    s->location = *set;

    String studentName = getfString(in,"\n");
    strcpy(s->name, studentName);
    return 1;
}

void freeStudent(Student* s){
    free(s->name);
    free(s);
}



