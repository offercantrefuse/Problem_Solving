#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int t, i, j,k;
	char board[8][8];
	int length;
	int cnt;

	for (t = 1; t <= 10; t++) {

		cnt = 0;
		scanf("%d", &length);

		for (i = 0; i < 8; i++) {
			scanf("%s", board[i]);
		}

		for (i = 0; i <8 ; i++) {
			for (j = 0; j <= 8-length; j++) {
				for (k = 0; k <= length / 2; k++) {
					if (board[i][j+k] != board[i][j+length - 1 - k]) {
						break;
					}
					if (k == length / 2)
						cnt++;
				}
			
			}
		}

		for (i = 0; i <8; i++) {
			for (j = 0; j <= 8 - length; j++) {
				for (k = 0; k <= length / 2; k++) {
					if (board[j + k][i] != board[j + length - 1 - k][i]) {
						break;
					}
					if (k == length / 2)
						cnt++;
				}

			}
		}
		printf("#%d %d\n", t, cnt);
	}
	return 0;
}