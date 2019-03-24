#include <iostream>
#include <algorithm>
using namespace std;
const int INF = -1e9 - 1;
int N, M;
int map[1002][1002] = { 0, };
int dp[3][1002][1002] = { 0, };

int max3(int a, int b, int c) {
	return max(max(a, b), c);
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}
	// dp[0~2][i][j] : (i,j)로 0~2 방향에서 올 수 있는 경로 중 최대값 
	// 0: 왼, 1: 오, 2: 위

	dp[0][1][1] = map[1][1];
	for (int j = 1; j <= M; j++)
		dp[2][1][j] = INF;
	for (int j = 2; j <= M; j++)
		dp[0][1][j] = dp[0][1][j - 1] + map[1][j];
	for (int j = M; j >= 1; j--)
		dp[1][1][j] = INF;

	for (int i = 2; i <= N; i++) { // 2 -> 0 -> 1
		for (int j = 1; j <= M; j++) { // 2: 위
			dp[2][i][j] = max3(dp[0][i - 1][j], dp[1][i - 1][j], dp[2][i - 1][j]) + map[i][j];
		}
		for (int j = 1; j <= M; j++) { // 0: 왼 
			if (j == 1) {
				dp[0][i][j] = INF;
				continue;
			}
			dp[0][i][j] = max(dp[2][i][j - 1], dp[0][i][j - 1]) + map[i][j];
		}
		for (int j = M; j >= 1; j--) { // 1: 오
			if (j == M) {
				dp[1][i][j] = INF;
				continue;
			}
			dp[1][i][j] = max(dp[1][i][j + 1], dp[2][i][j + 1]) + map[i][j];
		}
	}
	cout << max3(dp[0][N][M], dp[1][N][M], dp[2][N][M]);
	return 0;
}