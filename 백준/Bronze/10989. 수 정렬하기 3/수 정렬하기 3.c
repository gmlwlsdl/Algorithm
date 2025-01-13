#include <stdio.h>
int arr[10001] = { 0, };

int main() {
	int n, num, j;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		arr[num]++;
	}

	for (int i = 1; i < 10001; i++) {
		j = arr[i];
		if (j > 0) {
			for (int m = 0; m < j; m++)
				printf("%d\n", i);
		}
		else
			continue;
	}

	return 0;
}