#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <graphics.h>
int main() {
	float x0, y0, x1, y1, xn, yn, delx, dely, m, p;
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
		return 0;
	p = 2*dely - delx;
	x1 = x0;
	y1 = y0;
	initgraph(&gd,&gm,NULL);
	while((x1 != xn) || (y1 != yn)) {
		if(p <= 0) {
			p = p + 2*dely;
			x1 = x1 + 1;
		} else {
			p = p + 2*dely - 2*delx;
			x1 = x1 + 1;
			y1 = y1 + 1;
		}
		putpixel (x1,y1,RED);
		//delay(100);
	}
	delay(5000);
	closegraph();
	return 0;
}
