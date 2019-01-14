#include <iostream>
using namespace std;

int T, N, M, K;

int cabb[50][50] = { 0, };
int visit[50][50] = { 0, };
int cnt = 0;
int dr[] = { -1,0,1,0 };
int dc[] = { 0,-1,0,1 };

void dfs(int r, int c) {
	visit[r][c] = 1;
	for (int d = 0; d < 4; d++) {
		int nr = r + dr[d];
		int nc = c + dc[d];
		if (nr<0 || nr>N - 1 || nc<0 || nc>M - 1) continue;
		if (cabb[nr][nc] == 1 && visit[nr][nc] == 0) {
			dfs(nr, nc);
		}
	}
}

int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		// 입력
		cin >> M >> N >> K;
		for (int i = 0; i < K; i++) {
			int X, Y;
			cin >> X >> Y;
			cabb[Y][X] = 1;
		}
		// 탐색
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (cabb[i][j] == 1 && visit[i][j] == 0) {
					cnt++;
					dfs(i, j);
				}
			}
		}
		// 출력
		cout << cnt << '\n';
		// 초기화
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cabb[i][j] = 0;
				visit[i][j] = 0;
			}
		}
		cnt = 0;
	}
	return 0;
}