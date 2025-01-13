#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define size 1000

typedef char element;

typedef struct {
	element* data[size];
	int front, rear;
} QueueType;

void init(QueueType* q) {
	q->rear = q->front = -1;
}

int is_empty(QueueType* q) {
	return q->front == q->rear;
}

int is_full(QueueType* q) {
	return q->rear == size - 1;
}

void enqueue(QueueType* q, element e[]) {
	if (is_full(q)) {
		printf("Over");
	}
	else {
		q->rear++;
		q->data[q->rear] = e;
		
	}
}

void print(QueueType* q) {
	for (int i = q->front + 1; i <= q->rear; i++) {
		printf("%s", q->data[i]);
		if (i != q->rear) {
			printf("\n");
		}
	}
}

int main() {
	int a, b, c;
	bool d = true;
	QueueType q;
	init(&q);

	do {
		scanf("%d %d %d", &a, &b, &c);

		if (a == 0 && b == 0 && c == 0) {
			print(&q);
			d = false;
		}
		else if (a >= (b + c) || b >= (a + c) || c >= (a + b)) {
			enqueue(&q, "Invalid");
		}
		else {
			if (a == b && b == c && a == c) {
				enqueue(&q, "Equilateral");
			}
			else if (a == b || b == c || a == c) {
				enqueue(&q, "Isosceles");
			}
			else {
				enqueue(&q, "Scalene");
			}
		}
	} while (d);

	return 0;
}
