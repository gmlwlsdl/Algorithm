#include <stdio.h>

int main() {
	int arr[1001];
	int n,swap;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < n; i++) {
		for (int j = (i + 1); j < n; j++) {
			if (arr[i] > arr[j]) {
				swap = arr[i];
				arr[i] = arr[j];
				arr[j] = swap;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d\n", arr[i]);
	}

	return 0;
}