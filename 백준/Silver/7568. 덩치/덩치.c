#include <stdio.h>

typedef struct {
	int height;
	int weight;
	int num;
}info;

int main() {
	int n,num[50];
	info arr[50];
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].height, &arr[i].weight);
	}

	for (int i = 0; i < n; i++) {
		int count = 1;
		for (int j = 0; j < n; j++) {
			if (i == j)
				continue;
			else if (arr[i].height < arr[j].height) { //i가 j보다 키가 작음
				if (arr[i].weight < arr[j].weight)
					count++;
			}
			continue;
		}
		arr[i].num = count;
	}
	
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i].num);
	}

	return 0;
}