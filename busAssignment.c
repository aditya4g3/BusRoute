#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"Point2D.h"
#include"Strings.h"
#include"BusRoute.h"
#include"Student.h"

#define COLWIDTH 20

void printIndented(String name, String closestStop, int indentation);

int main(int argc, char*argv[]){
    FILE* file = fopen(argv[1],"r");
    if(file == (FILE*) NULL){
        fprintf(stderr,"Failed to open: %s.\n",argv[1]);
        return EXIT_FAILURE;
    }

    int routeNum = atoi(getNext(file)); //number of routes

    BusRoute** br = (BusRoute**) malloc(sizeof(BusRoute*)*routeNum);
    if(br == (BusRoute**)NULL){
        fprintf(stderr, "Memory allocation failed. Program terminating.");
        return EXIT_FAILURE;
    }
    int stopNum[routeNum];  //int array storing number of stops in each route
    int s=0;
    int assignStopNum;
    for(int i=0;i<routeNum;i++){
        assignStopNum = atoi(getNext(file));
        stopNum[i]= assignStopNum;
        br[i] = mallocBusRoute(stopNum[i]);
        if(br[i] == (BusRoute*)NULL){
                fprintf(stderr, "Memory allocation failed. Program terminating.");
                return EXIT_FAILURE;
                for(int j=0;j<i;j++){
                    free(br[j]);
                }
                free(br); 
        }
        s = setStops(br[i],file,stopNum[i]);
        if(s==0){break;}
    }

    Student* student = mallocStudent();
    if(student == (Student*)NULL){
        fprintf(stderr, "Memory allocation failed. Program terminating.");
        for(int j=0;j<routeNum;j++){
            free(br[j]);
        }
        free(br); 
        return EXIT_FAILURE;
    }
    printf("\n");
    printIndented("StudentName","ClosestRoute\tStopNumber",4);
    String closestStop;
    while(!feof(stdin)){
        s = setStudent(student,stdin);
        if(feof(stdin) || s==0){break;}
        closestStop = getClosestStop(br,stopNum,routeNum,student);
        printIndented(student->name,closestStop,4);
        free(closestStop);
    }

    for(int j=0;j<routeNum;j++){
            free(br[j]);
    }

    free(br);
    free(student);
    fclose(file);
    return EXIT_SUCCESS;
}

void printIndented(String name, String closestStop, int indentation) {
    printf("%*s%-25s%-25s\n", indentation, "", name, closestStop);
}

