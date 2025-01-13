#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char word[101];
	int num = 0, n = 0;
	scanf("%s", word);             // 문자 배열 s에 입력받기

	for (int i = 0; word[i] != '\0'; i++) {
		num++;
	}

	n = num;

	if (n % 2 == 0) {
		for (int i = 0; i <= (n / 2) - 1; i++) {
			if (word[i] != word[--num]) {
				printf("0");
				return 0;
			}
		}
	}
	else if (n % 2 != 0) {
		for (int i = 0; i <= n / 2; i++) {
			if (word[i] != word[--num]) {
				printf("0");
				return 0;
			}
		}
	}

	printf("1");

	return 0;
}