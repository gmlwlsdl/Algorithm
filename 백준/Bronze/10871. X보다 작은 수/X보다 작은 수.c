#include <stdio.h>

int main() {
	int n, x, arr[10001];
	scanf("%d %d", &n, &x);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int j = 0; j < n; j++) {
		if (arr[j] < x)
			printf("%d ", arr[j]);
		else
			continue;
	}
}