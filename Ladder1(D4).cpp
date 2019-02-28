#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int t, n, i, j;
	int data[102][102] = { 0, };
	int start;

	for (t = 1; t <= 10; t++) {
		scanf("%d", &n);

		start = 0;

		for (i = 1; i <= 100; i++) {
			for (j = 1; j <= 100; j++) {
				scanf("%d", &data[i][j]);
			}
		}

		for (j = 1; j <= 100; j++) {
			if (data[100][j] == 2)
				start = j;
		}

		for (i = 100; i >= 1; i--) {
			while(data[i][start - 1] == 1) {
				data[i][start] = 0;
				start--;
			}
			while (data[i][start + 1] == 1) {
				start++;
			}
		}
		printf("#%d %d\n", t, start-1);
	}
	return 0;
}
