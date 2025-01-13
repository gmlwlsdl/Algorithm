#include <stdio.h>

int main() {
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {

		for (int j = (n - i); j > 0; j--) {

			if (j == 1) {
				for (int m = 0; m < (i+1) ; m++) {
					printf("*");
				}
			}
			else {
				printf(" ");
			}

		}
		printf("\n");
	}
	return 0;
}