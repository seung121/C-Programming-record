// header.h
#ifndef __MYHEADER_H__
#define __MYHEADER_H__

extern int num;
struct Point
{
	int x;
	int y;
};
typedef struct Point Point;

void Sum(Point pt1, Point pt2);

void Sub(Point pt1, Point pt2);


#endif
