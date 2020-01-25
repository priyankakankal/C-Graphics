#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <graphics.h>
int main() {
	
   	int gd = DETECT,gm,left=100,top=100,right=200,bottom=200,x= 300,y=150,radius=50;
	float x0, y0, a, b, x_center, y_center, dx, dy, d1, d2;
   
	printf("Enter center of ellipse: x y\n");
	scanf("%f %f", &x_center, &y_center);
	printf("Enter length of major and minor axis:\n");
	scanf("%f %f", &a, &b);
	if(a < 0 || b < 0) {
		printf("error: axis cannot be negative\n");
		return 0;
	}

	x0 = 0;
	y0 = b;
	x_center = a + x_center;
	y_center = b + y_center;

	d1 = (b * b) - (a * a * b) + (0.25 * a * a);
	dx = 2 * b * b * x0;
	dy = 2 * a * a * y0;

	initgraph(&gd,&gm,NULL);

	while(dx < dy) {
		putpixel (x0 + x_center, y0 + y_center, RED);  
	    	putpixel (-x0 + x_center, y0 + y_center, RED);  
	    	putpixel (x0 + x_center, -y0 + y_center, RED);  
	    	putpixel (-x0 + x_center, -y0 + y_center, RED);
		if (d1 < 0) { 
		    x0++; 
		    dx = dx + (2 * b * b); 
		    d1 = d1 + dx + (b * b); 
		} 
		else { 
		    x0++; 
		    y0--; 
		    dx = dx + (2 * b * b); 
		    dy = dy - (2 * a * a); 
		    d1 = d1 + dx - dy + (b * b); 
		} 
	}

	d2 = ((b * b) * ((x0 + 0.5) * (x0 + 0.5))) + ((a * a) * ((y0 - 1) * (y0 - 1))) - (a * a * b * b);
	while(y0 >= 0) {
		putpixel (x0 + x_center, y0 + y_center, RED);  
	    	putpixel (-x0 + x_center, y0 + y_center, RED);  
	    	putpixel (x0 + x_center, -y0 + y_center, RED);  
	    	putpixel (-x0 + x_center, -y0 + y_center, RED);

		if (d2 > 0) { 
		    y0--; 
		    dy = dy - (2 * a * a); 
		    d2 = d2 + (a * a) - dy; 
		} 
		else { 
		    y0--; 
		    x0++; 
		    dx = dx + (2 * b * b); 
		    dy = dy - (2 * a * a); 
		    d2 = d2 + dx - dy + (a * a); 
		} 
	} 

	
	
	
	delay(5000);
	closegraph();
	return 0;
}
