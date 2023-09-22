#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include"Point2D.h"
#include"Strings.h"
#include"BusRoute.h"
#include"Student.h"

#define SIZE 100

BusRoute* mallocBusRoute(int stopCount){
    BusRoute* br;
    br = (BusRoute*)malloc(sizeof(BusRoute));
    Point2D* pt;
    pt = (Point2D*)(malloc(sizeof(Point2D)*stopCount));
    br->stops = pt;
    br->routeName = mallocString(SIZE);
    return br;
}

/*function that sets stops from the specified file.
returns 1 if Stops are set successfully and 0 if 
coordinates couldn't be read successfully.
*/
int setStops(BusRoute* br, FILE* in,int stopCount){
    Point2D* pt = br->stops;
    Point2D* set;
    for(int i=0;i<stopCount;i++){
        set = fscanfPoint2D(in);    
        if(set == (Point2D*)NULL){return 0;}
        pt[i] = *set;
    }
    String stopName =  getfString(in,"\n");
    strcpy(br->routeName, stopName);
    return 1;
}
/**
 * gets an array of characters until the next space or '\n'
*/
String getNext(FILE* in){
    char terminators[2];
    terminators[0]=' ';
    terminators[1] = '\n';
    //terminators[2] = (char)NULL;
    String numstr = getfString(in,terminators);
    return numstr;
}

void freeBusRoute(BusRoute* br){
    free(br->routeName);
    free(br->stops);
    free(br);
}

/**
 function that takes in an array of routes, int array with number of stops 
 for each route, total number of routes and a pointer to a student. Returns
 a string with the student's closest bus route name and stop number.
*/
String getClosestStop(BusRoute** routes,int* stopNum,int routeNum,Student* s){
    Point2D* home = &(s->location);
    BusRoute* r = routes[0];
    Point2D* stop = &(r->stops[0]);
    double min =  getDistancePoint2D(home,stop),dist=-1;
    int closestStopNum=1;
    String closestRouteName = r->routeName;
    int numberOfStops =0;
    for(int i=0;i<routeNum;i++){
        r = routes[i];
        numberOfStops = stopNum[i];
        for(int j=0; j<numberOfStops;j++){
            stop = &(r->stops[j]);
            dist = getDistancePoint2D(home,stop);
            if(dist<min){
                min = dist;
                closestStopNum = j+1;
                closestRouteName = r->routeName;
            }
        }
    }
    String result = mallocString(SIZE*3);
    sprintf(result,"%s\t%d",closestRouteName,closestStopNum);
    return result;
}




