#include <stdio.h>
#include "mydata.h"

Point g_result = { 0,0 };

void Print(Point pt)
{
	printf("(%d, %d)\n", pt.x, pt.y);
}

int main(void) {

	Point pt1 = { 1,2 };
	Point pt2 = { 3,4 };

	Sum(pt1, pt2);
	Print(g_result);

	Sub(pt1, pt2);
	Print(g_result);

	return 0;

}


