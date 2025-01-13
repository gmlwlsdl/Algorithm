#include <stdio.h>

int main() {
	double sum1;
	int num, pri[100];
	int sum2 = 0;

	scanf("%lf\n %d", &sum1, &num);

	for (int i=0; i < num; i++) {
		int x, y = 0;
		scanf("%d %d", &x, &y);
		pri[i] = x*y;
		sum2 += pri[i];
	}

	if (sum1 == (double)sum2)
		printf("Yes");
	else
		printf("No");

	return 0;
}