#include <iostream>
#include <cstring>
using namespace std;
int N, tt, cnt;
int map[100][100] = { 0, };
int visit[100][100] = { 0, };
int dr[] = { -1,0,1,0 };
int dc[] = { 0,-1,0,1 };

void dfs(int r, int c) {
	visit[r][c] = 1;
	for (int d = 0; d < 4; d++) {
		int nr = r + dr[d];
		int nc = c + dc[d];
		if (nr<0 || nc<0 || nr>N - 1 || nc>N - 1) continue;
		if (visit[nr][nc] == 0 && map[nr][nc] > tt) {
			dfs(nr, nc);
		}
	}
}
int main() {
	cin >> N;
	int max_height = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] > max_height) max_height = map[i][j];
		}
	}
	int ans = 0;
	// 최대높이까지 탐색 
	for (tt = 0; tt <= max_height; tt++) {
		for (int i = 0; i < N; i++) memset(visit[i], 0, sizeof(visit[i]));
		cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visit[i][j] == 0 && map[i][j] > tt) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		ans = ans < cnt ? cnt : ans;
	}
	cout << ans;
	return 0;
}