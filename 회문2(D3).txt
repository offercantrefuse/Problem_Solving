#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int t, n, i, j, k;
	char board[100][100];
	int length;
	int max;

	for (t = 1; t <= 10; t++) {

		scanf("%d", &n);
		max = 0;

		for (i = 0; i < 100; i++) {
			scanf("%s", board[i]);
		}
		for (length = 2; length <= 100; length++) {
			for (i = 0; i < 100; i++) {
				for (j = 0; j <= 100 - length; j++) {
					for (k = 0; k <= length / 2; k++) {
						if (board[i][j + k] != board[i][j + length - 1 - k]) {
							break;
						}
						if (k == length / 2) {
							if (max < length) {
								max = length;
							}
						}
					}

				}
			}

			for (i = 0; i < 100; i++) {
				for (j = 0; j <= 100 - length; j++) {
					for (k = 0; k <= length / 2; k++) {
						if (board[j + k][i] != board[j + length - 1 - k][i]) {
							break;
						}
						if (k == length / 2)
							if (max < length)
								max = length;
					}

				}
			}
		}
		printf("#%d %d\n", n, max);
	}
	return 0;
}