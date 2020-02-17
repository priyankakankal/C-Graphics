#include <graphics.h>
#include <stdio.h>

void scanline(int n, int *coor);

int main() {
	int n, i, j;
	int gd = DETECT,gm, coor[100];	
	printf("Enter the number of vertices of polygon: \n");
	scanf("%d", &n);
	
	if(!n) {
		initgraph(&gd,&gm,NULL);
		circle(100, 100, 50);
		//circlescan(100, 100)
	} else {
		printf("Enter the coordinates:\n");
		for(i = 0, j = 0; i < n; i++, j+=2) {
			printf("x%d y%d: ", i, i);
			scanf("%d %d", &coor[j], &coor[j+ 1]);
		}
		coor[j] = coor[0];
		coor[j + 1] = coor[1];
		initgraph(&gd,&gm,NULL);
		drawpoly(n + 1, coor);
		scanline(j + 1, coor);
	}
	delay(1000);
	closegraph();
	return 0;
}

void scanline(int n, int *coor) {
	int ymin, ymax, xmin, xmax, i, j, inter[100], size, k;
	ymin = ymax= coor[1];
	xmin = xmax = coor[0];
	for(i = 1; i < n; i+=2) {
		if(coor[i] < ymin)
			ymin = coor[i];
		if(coor[i] > ymax)
			ymax = coor[i];
		if(coor[i - 1] < xmin)
			xmin = coor[i - 1];
		if(coor[i - 1] > xmax)
			xmax = coor[i - 1];
	}
	
	for(i = ymin; i < ymax; i++) {
		size = 0;
		for(j = xmin; j <= xmax; j++) {
			if(getpixel(j, i) != 0) {
				inter[size] = j;
				size++;
			}
			
		}
		for(j = 0; j < size; j+= 2) {
			if((j != 0) && ((size - 1) % 2 == 0)) {
				for(k = inter[j - 1]; k < inter[j]; k++)
					putpixel (k, i, RED);
			} else {
				for(k = inter[j]; k < inter[j + 1]; k++)
					putpixel (k, i, RED);
			}
		}
		delay(100);
	}
}

