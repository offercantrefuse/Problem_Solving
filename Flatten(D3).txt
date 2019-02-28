#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void dump(int *a,int n) {
	int i, j, M, m;
	for (j = 0; j < n; j++) {
		M = 0; m = 0;
		for (i = 0; i < 99; i++) {
			if (a[M] <= a[i + 1]) {
				M = i + 1;
			}
			if (a[m] >= a[i + 1]) {
				m = i + 1;
			}
		}
		a[M]--;
		a[m]++;
	}
}

int main() {
	int t, n, i;
	int box[100] = { 0, };
	int max = 0, min = 0, result;

	for (t = 1; t <= 10; t++) {
		scanf("%d", &n);
		for (i = 0; i < 100; i++) {
			scanf("%d", &box[i]);
		}
		
		dump(box,n);
		
		for (i = 0; i < 99; i++) {
			if (box[max] <= box[i + 1]) {
				max = i + 1;
			}
			if (box[min] >= box[i + 1]) {
				min = i + 1;
			}
		}

		result = box[max] - box[min];

		printf("#%d %d\n", t, result);
	}

	return 0;
}

