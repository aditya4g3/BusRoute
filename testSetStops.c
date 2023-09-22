#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include"Point2D.h"
#include"Strings.h"
#include"BusRoute.h"

#define SIZE 100

int main(int argc, char* argv[]){
    FILE* in = fopen(argv[1],"r");
    if(in == (FILE*) NULL){
        fprintf(stderr,"Failed to open: %s.\n",argv[1]);
        return EXIT_FAILURE;
    }

    int numberOfRoutes = atoi(getNext(in));

    BusRoute** br = (BusRoute**) malloc(sizeof(BusRoute*)*numberOfRoutes);
    if(br == (BusRoute**)NULL){
        fprintf(stderr, "Memory allocation failed. Program terminating.");
        return EXIT_FAILURE;
    }
    int stopNum[numberOfRoutes]; 
    int s=0;
    int stopIndex;
    for(int i=0;i<numberOfRoutes;i++){
        stopIndex = atoi(getNext(in));
        stopNum[i]= stopIndex;
        br[i] = mallocBusRoute(stopNum[i]);
        if(br[i] == (BusRoute*)NULL){
                fprintf(stderr, "Memory allocation failed. Program terminating.");
                return EXIT_FAILURE;
                for(int j=0;j<i;j++){
                    free(br[j]);
                }
                free(br); 
        }
        s = setStops(br[i],in,stopNum[i]);
        if(s==0){break;}
    }
    for(int i=0;i<numberOfRoutes;i++){
        Point2D* stop = br[i]->stops;
        printf("Route Name: %s\n",br[i]->routeName);
        for(int j=0;j<stopNum[i];j++){
            printf("\tStop %d: (%lf, %lf)\n",(j+1),stop[j].x,stop[j].y);
        }
    }
}