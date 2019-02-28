#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int t, n, i, j, p;
	int data[102][102] = { 0, };
	int back[102][102] = { 0, };
	int start, x;
	int cnt, sum;

	for (t = 1; t <= 10; t++) {
		scanf("%d", &n);

		start = 0;
		x = 0;

		for (i = 1; i <= 100; i++) {
			for (j = 1; j <= 100; j++) {
				scanf("%d", &data[i][j]);
				back[i][j] = data[i][j];
			}
		}

		sum = 10000;

		for (j = 1; j <= 100; j++) {
			if (data[100][j] == 1) {
				start = j;
				int k = 100;
				cnt = 0;
				while (k != 1) {
					data[k][start] = 0;
					cnt++;
					if (data[k][start - 1] == 1) {
						data[k][start] = 0;
						start--;
					}
					else if (data[k][start + 1] == 1) {
						data[k][start] = 0;
						start++;
					}
					else
						k--;
				}
				if (sum >= cnt) {
					sum = cnt;
					x = start;
				}
				for (i = 1; i <= 100; i++) {
					for (p = 1; p <= 100; p++) {
						data[i][p] = back[i][p];
					}
				}
			}
		}
		printf("#%d %d\n", t, x-1);
	}
	return 0;
}

