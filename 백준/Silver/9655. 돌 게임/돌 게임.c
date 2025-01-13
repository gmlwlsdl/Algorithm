#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int cnt = 0;

	scanf("%d", &cnt);

	if ((cnt % 2) == 0) {
		printf("CY");
	}
	else {
		printf("SK");
	}
}
