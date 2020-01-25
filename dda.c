#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <graphics.h>
int main() {
	float x0, y0, x1, y1, xn, yn, delx, dely, m, steps;
	int i;
	
   	int gd = DETECT,gm,left=100,top=100,right=200,bottom=200,x= 300,y=150,radius=50;
   
	printf("Enter starting coordinates: x y\n");
	scanf("%f %f", &x0, &y0);
	printf("Enter ending coordinates: x y\n");
	scanf("%f %f", &xn, &yn);
	delx = xn - x0;
	dely = yn - y0;
	if(delx)
		m = dely / delx;
	else
		m = 0;
	if(abs(delx) > abs(dely))
		steps = abs(delx);
	else
		steps = abs(dely);
	printf("(%f, %f) (%f, %f)\n",x0, y0, xn, yn);
	printf("%f\n", steps);
	x1 = x0;
	y1 = y0;
	printf("Points:\n(%f, %f)\n",x0, y0);
	initgraph(&gd,&gm,NULL);
	for(i = 0; i < (int)steps; i++) {
		if(m == 0) {
			y1 = ceilf(y1 + 1);
		} else if(abs(m) < 1) {
			x1 = ceilf(x1 + 1);
			y1 = ceilf(y1 + m);
		} else if(abs(m) == 1) {
			x1 = ceilf(x1 + 1);
			y1 = ceilf(y1 + 1);
		} else {
			x1 = ceilf(x1 + 1/m);
			y1 = ceilf(y1 + 1);
		}
		putpixel (x1,y1,RED);
		//delay(100);
	}

 
   delay(5000);
   closegraph();
	return 0;
}
