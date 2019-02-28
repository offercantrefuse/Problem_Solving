#include <iostream>
using namespace std;
int digit;
int dp[1000000][20];

int swap(int num, int a, int b) {
	int arr[10];
	int tmp = num;
	for (int i = 0; i < digit; i++) {
		arr[i] = tmp % 10;
		tmp /= 10;
	}
	if (arr[a] == arr[b])
		return num;

	tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;

	num = 0;
	for (int i = digit - 1; i >= 0; i--) {
		num = num * 10 + arr[i];
	}

	return num;
}

int solve(int num, int cnt) {
	int &ret = dp[num][cnt];
	if (ret != -1) return ret;

	if (cnt == 0) return ret = num;
	ret = 0;
	for (int i = 0; i < digit - 1; i++) {
		for (int j = i + 1; j < digit; j++) {
			int tmp = solve(swap(num, i, j), cnt - 1);
			if (tmp > ret) ret = tmp;
		}
	}
	
	return ret;
}

int main() {
	int tc, num, cnt;
	cin >> tc;
	for (int k = 1; k <= tc; k++) {
		cin >> num >> cnt;
		int tmp = num;
		digit = 0;
		while (tmp) {
			tmp /= 10;
			digit++;
		}
		for (int i = 0; i < 1000000; i++) {
			for (int j = 0; j < 20; j++) {
				dp[i][j] = -1;
			}
		}

		cout << "#" << k << ' ' << solve(num, cnt) << endl;
	}
	return 0;
}