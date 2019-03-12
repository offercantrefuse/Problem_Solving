#include <iostream>
using namespace std;
int N;
long ans = 0;
int map[33][33] = { 0, };
long long dp[33][33][3] = { 0, };

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
	// r, c, dir
	dp[1][2][0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == 1) continue;
			// 가로
			dp[i][j][0] += dp[i][j - 1][0] + dp[i][j - 1][2];
			// 세로
			dp[i][j][1] += dp[i - 1][j][1] + dp[i - 1][j][2];
			// 대각선
			if (map[i - 1][j] == 0 && map[i][j - 1] == 0)
				dp[i][j][2] += dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
		}
	}
	cout << dp[N][N][0] + dp[N][N][1] + dp[N][N][2];
	return 0;
}