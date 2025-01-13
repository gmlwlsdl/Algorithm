#include <stdio.h>
#include <string.h>

int main() {
	char c[100];

	scanf("%s", c);
	int len = strlen(c);

	for (char i = 'a'; i <= 'z'; i++) {
		for (int j = 0; j<len; j++) {
			if (c[j] == i) {
				printf("%d ", j);
				break;
			}
			else if (c[j] != i) {
				if (j == (len - 1))
					printf("-1 ");
				else continue;
			}
		}
	}
	return 0;
}