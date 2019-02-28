#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {

	int T, n;
	int t, i, j, m;

	scanf("%d", &T);

	for (t = 0; t < T; t++) {
		scanf("%d", &n);
		
		int score[1000] = { 0, };
		int k = 0;

		for (i = 0; i < 1000; i++) {
			scanf("%d",&score[i]);
		}
	
		int arr[101] = { 0, };
		for (j = 0; j< 1000; j++) {
			arr[score[j]]++;
		}

		for (m = 1; m < 101; m++) {
			if (arr[k] <= arr[m]) {
				k = m ;
			}
		}

		printf("#%d %d\n", n, k);
	}
	return 0;
}

