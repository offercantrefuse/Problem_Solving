#define _CRT_SECURE_NO_WARNINGS
#define max(a,b) ((a>b)?a:b)
#include <stdio.h>

int main() {

	int T, n;
	int i;
	int arr[1000] = { 0, };
	int cnt;
	int tmp1,tmp2,tmp3;
	

	for (T = 1; T <= 10; T++) {
		scanf("%d", &n);
		int sum = 0;
		for (i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		
		for (i = 2; i < n - 2; i++) {
			if (arr[i] > arr[i - 1] && arr[i] > arr[i - 2] && arr[i] > arr[i + 1] && arr[i] > arr[i + 2]) {
				cnt = 0;
				tmp1 = max(arr[i - 1], arr[i - 2]);
				tmp2 = max(arr[i + 1], arr[i + 2]);
				tmp3 = max(tmp1, tmp2);
				cnt = arr[i] - tmp3;
				sum += cnt;
			}
		}

		printf("#%d %d\n", T, sum);


	}

	return 0;
}

