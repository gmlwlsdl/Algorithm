#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	double h,w,n,m;
	double row, col;

	scanf("%lf %lf %lf %lf", &h, &w, &n, &m);
	
	row = ceil(h / ( n + 1));
	col = ceil(w / ( m + 1));

	printf("%.lf", row * col);
}