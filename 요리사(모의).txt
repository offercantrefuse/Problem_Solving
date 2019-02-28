#include <iostream>
#include <stdio.h>
using namespace std;
#define INF 2e9

bool check[21];
int s[21][21], ans;

int abs(int a) {
	return a > 0 ? a : -a;
}

int min(int a, int b) {
	return a > b ? b : a;
}

void recursion(int N, int cnt, int food) {
	if (cnt == N) {
		int A = 0, B = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j) continue;
				if (check[i] && check[j]) A += s[i][j];
				if (!check[i] && !check[j]) B += s[i][j];
			}
		}
		ans = min(ans, abs(A - B));
		return;
	}
	if (food > 0) {
		check[cnt] = true;
		recursion(N, cnt + 1, food - 1);
		check[cnt] = false;
	}
	recursion(N, cnt + 1, food);
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int N;
		cin >> N;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> s[i][j];
			}
		}
		ans = INF;
		recursion(N, 0, N / 2);
		cout << "#" << tc << ' ' << ans << endl;
	}
	return 0;
}