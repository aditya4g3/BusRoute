#include "Strings.h"
#include "Point2D.h"
#include "Student.h"

#ifndef BUSROUTE_H
#define BUSROUTE_H

typedef struct{
    Point2D* stops;
    String routeName;
}BusRoute;


BusRoute* mallocBusRoute(int stopCount);
int setStops(BusRoute* br, FILE* in,int stopCount);
String getNext(FILE* in);
String getClosestStop(BusRoute** routes,int* stopNum,int routeNum,Student* s);

#endif