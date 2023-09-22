#ifndef POINT2D_H
#define POINT2D_H

typedef struct point2d
{
	double x;
	double y;

} Point2D;

void freePoint2D(Point2D* pPtThis);
Point2D* createPoint2D(double x, double y);
void setPoint2D(Point2D* pPtThis, double x, double y);
void setXPoint2D(Point2D* pPtThis, double x);
double getYPoint2D(Point2D* pPtThis);
Point2D* fscanfPoint2D(FILE* pFin);
double getDistancePoint2D( Point2D* ptThis, Point2D* pPtThat);

#endif
