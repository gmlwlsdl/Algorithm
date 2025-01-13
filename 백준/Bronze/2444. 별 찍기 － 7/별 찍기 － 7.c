#include <stdio.h>

int main() {
	int n,m;
	int j = 0;
	
	scanf("%d", &n);

	for (int i = 0; i < ((n * 2) - 1); i++) {
		if (i < n) {
			for (int a = (n - i); a > 0; a--) {
				if (a == 1) {
					if (i == 0)
						printf("*");
					else
						for (m = 0; m < ((i * 2) + 1); m++)
							printf("*");
				}
				else {
					printf(" ");
				}
			}
			printf("\n");
		}
		else if (i >= n) { 
			for (int b=1; b < n; j++) {
			++j;
				if (j == 1) {
					if (i == n) {
						printf(" ");
						for (int o=(m-2); o >= 1; o--)
							printf("*");
						break;
					}
				}
				else if (j > 1) {
					for (int r = 0; r < j; r++)
						printf(" ");
					for (int p = (m-4); p >= 1; p--)
						printf("*");
					m -= 2;
					break;
				}
			}
			printf("\n");
		}
	}
	return 0;
}