#include <stdio.h>

int main() {
	int n,m,arr[100];
	int x = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d ", &arr[i]);
	}

	scanf("%d", &m);

	for (int j = 0; j < n; j++) {
		if (arr[j] == m)
			x++;
		else
			continue;
	}

	printf("%d", x);
}