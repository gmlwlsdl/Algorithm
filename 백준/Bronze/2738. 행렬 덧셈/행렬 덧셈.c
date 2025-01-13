#include <stdio.h>

int main() {
	int n, m;
	int arr0[100][100], arr1[100][100];

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr0[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr1[i][j]);
		}
	}

	for (int o = 0; o < n; o++) {
		for (int z = 0; z < m; z++) {
			arr0[o][z] += arr1[o][z];
			printf("%d ", arr0[o][z]);
		}
		printf("\n");
	}
	return 0;
}