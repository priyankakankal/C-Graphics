#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <graphics.h>
int main() {
	
   	int gd = DETECT,gm,left=100,top=100,right=200,bottom=200,x= 300,y=150,radius=50;
	float x0, y0, r, x_center, y_center, p;
   
	printf("Enter center: x y\n");
	scanf("%f %f", &x_center, &y_center);
	printf("Enter radius:\n");
	scanf("%f", &r);
	if(r < 0) {
		printf("error: Radius cannot be negative\n");
		return 0;
	}

	p = 1 - r;

	x0 = 0;
	y0 = r;
	x_center = r + x_center;
	y_center = r + y_center;

	
	initgraph(&gd,&gm,NULL);

	putpixel (x0 + x_center, y0 + y_center, RED); 
	
	if(r > 0) {
	    	putpixel (x0 + x_center, -y0 + y_center, RED);  
	    	putpixel (y0 + x_center, x0 + y_center, RED);  
	    	putpixel (-y0 + x_center, x0 + y_center, RED);
	} 

	while(x0 < y0) {

		
		x0++;	
		
		if(p <= 0) {
			p = p + 2*x0 + 1;
			
		} else {
			y0--;
			p = p + 2*x0 - 2*y0 +1;
		}

		if(x0 > y0)
			break;

		putpixel (x0 + x_center, y0 + y_center,RED);
		putpixel (-x0 + x_center, y0 + y_center,RED);
		putpixel (x0 + x_center, -y0 + y_center,RED);
		putpixel (-x0 + x_center, -y0 + y_center,RED);

		if(x0 != y0) {
			putpixel (y0 + x_center, x0 + y_center,RED);
			putpixel (-y0 + x_center, x0 + y_center,RED);
			putpixel (y0 + x_center, -x0 + y_center,RED);
			putpixel (-y0 + x_center, -x0 + y_center,RED);
		}
	

		
	}
	delay(5000);
	closegraph();
	return 0;
}
