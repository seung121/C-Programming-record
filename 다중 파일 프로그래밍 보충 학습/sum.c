#include "mydata.h"

extern Point g_result;

void Sum(Point pt1, Point pt2)
{
	g_result.x = pt1.x + pt1.y;
	g_result.y = pt1.y + pt2.y;
}
