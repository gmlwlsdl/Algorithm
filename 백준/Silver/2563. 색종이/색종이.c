#include <stdio.h>
int arr[100][100]={ 0, };

int main() {
	int n, x, y;
	int count = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x,&y);
		
		for (int a = x; a < (x + 10); a++) {
			for (int b = y; b < (y + 10); b++) {
				if (arr[a][b] == 0)
					arr[a][b] = 1;
				else
					count++;
			}
		}
	}

	printf("%d", (n*100)-count);
		 
    return 0;
}