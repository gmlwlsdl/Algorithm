#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n;
	int e = 1;
	int add = 6;
	int cnt = 1;

	scanf("%d", &n);

	while (1) {
		if (n <= e) {
			break;
		}
		e += add;
		cnt++;
		add += 6;
		
	}

	printf("%d", cnt);

	return 0;
}