#include <stdio.h>
#include <graphics.h>

void mybound(int x, int y) {
	int current;
	current = getpixel(x, y);
	if(current == 0) {
		putpixel (x, y, 10);
		mybound(x + 1, y);
		mybound(x - 1, y);
		mybound(x, y + 1);
		mybound(x, y - 1);
	}
}

int main() {
	int gd = DETECT,gm;
	int x, y, current;
	int left = 150, top = 150;
	int right = 450, bottom = 450;
	initgraph(&gd,&gm,NULL);
	rectangle(left, top, right, bottom);
	x = (left + right)/2;
	y = (top + bottom)/2;
	for(; x <= right; x++) {
		for(; y <= bottom; y++) {
			mybound(x, y);
		}
	}
	delay(1000);
	closegraph();
	return 0;
}


