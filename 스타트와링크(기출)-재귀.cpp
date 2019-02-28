#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int s[20][20];
int team[20] = { 0, };
int ans;

void dfs(int n, int *team, int cnt) {
	if (cnt == N / 2 || n == N) {
		int sumA = 0, sumB = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (team[i] == 0) {
					if (team[j] == 0) {
						sumA += s[i][j];
					}
				}
				if (team[i] == 1) {
					if (team[j] == 1) {
						sumB += s[i][j];
					}
				}
			}
		}
		ans = (ans > abs(sumA - sumB)) ? abs(sumA - sumB) : ans;
		return;
	}
	team[n] = 1;
	dfs(n + 1, team, cnt + 1);
	team[n] = 0;
	dfs(n + 1, team, cnt);
}


int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> s[i][j];
		}
	}
	ans = 1000000000;
	dfs(0, team, 0);
	cout << ans << '\n';

	return 0;
}