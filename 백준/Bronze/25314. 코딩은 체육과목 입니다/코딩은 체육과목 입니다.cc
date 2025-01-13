#include <stdio.h>

int main() {
	int n;

	scanf("%d", &n);

	do {
		printf("long ");
		n -= 4;
	} while (n != 0);
	printf("int");

	return 0;
}