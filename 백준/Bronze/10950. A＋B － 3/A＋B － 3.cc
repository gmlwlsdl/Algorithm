#include <stdio.h>

int main() {
	int n, arr[100];

	scanf("%d", &n);

	for (int i = 0;i < n;i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		arr[i] = x + y;
	}

	for (int i = 0;i < n;i++) {
		printf("%d\n",arr[i]);
	}

	return 0;
}