#define _CRT_SECURE_NO_WARNINGS
#define max(a,b) ((a>b)?a:b)
#include <stdio.h>

int main() {
	int t,n, i, j;
	int arr[100][100];
	int sum;
	int maxcol, maxrow, maxdia;
	int tmp1,tmp2;

	for (t = 1; t <= 10; t++) {
		scanf("%d", &n);


		for (i = 0; i < 100; i++) {
			for (j = 0; j < 100; j++) {
				scanf("%d", &arr[i][j]);
			}
		}

		maxcol = 0, maxrow = 0, maxdia = 0;

		for (i = 0; i < 100; i++) {
			sum = 0;
			for (j = 0; j < 100; j++) {
				sum += arr[i][j];
			}
			if (maxrow < sum)
				maxrow = sum;
		}
		for (i = 0; i < 100; i++) {
			sum = 0;
			for (j = 0; j < 100; j++) {
				sum += arr[j][i];
			}
			if (maxcol < sum)
				maxcol = sum;
		}

		sum = 0;
		for (i = 0, j = 0; i < 100, j < 100; i++, j++) {
			sum += arr[j][j];
		}
		maxdia = sum;

		sum = 0;
		for (i = 99, j = 99; i >= 0, j >= 0; i--, j--) {
			sum += arr[i][j];
		}
		if (maxdia < sum)
			maxdia = sum;
		
		tmp1 = max(maxcol, maxrow);
		tmp2 = max(tmp1, maxdia);

		printf("#%d %d\n", t, tmp2);
	}

	return 0;
}
