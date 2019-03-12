#include <iostream>
using namespace std;
int N, ans = 0;
int map[17][17] = { 0, };
void dfs(int r, int c, int dir) {
	if ((r == N && c == N - 1 && dir == 0) || (r == N - 1 && c == N && dir == 1) || (r == N - 1 && c == N - 1 && dir == 2)) {
		ans++;
		return;
	}
	int nr, nc, ndir;
	if (dir == 0) { // 가로
		// 가로 전진
		nr = r;
		nc = c + 1;
		ndir = 0;
		if (nc + 1 <= N && map[nr][nc + 1] == 0) {
			dfs(nr, nc, ndir);
		}
		// 대각선
		nr = r;
		nc = c + 1;
		ndir = 2;
		if (nr + 1 <= N && nc + 1 <= N && map[nr + 1][nc] == 0 && map[nr][nc + 1] == 0 && map[nr + 1][nc + 1] == 0) {
			dfs(nr, nc, ndir);
		}
	}
	else if (dir == 1) { // 세로
		// 세로 전진
		nr = r + 1;
		nc = c;
		ndir = 1;
		if (nr + 1 <= N && map[nr + 1][nc] == 0) {
			dfs(nr, nc, ndir);
		}
		// 대각선
		nr = r + 1;
		nc = c;
		ndir = 2;
		if (nr + 1 <= N && nc + 1 <= N && map[nr + 1][nc] == 0 && map[nr][nc + 1] == 0 && map[nr + 1][nc + 1] == 0) {
			dfs(nr, nc, ndir);
		}
	}
	else { // 대각선
		// 가로
		nr = r + 1;
		nc = c + 1;
		ndir = 0;
		if (nr <= N && nc + 1 <= N && map[nr][nc + 1] == 0) {
			dfs(nr, nc, ndir);
		}
		// 세로 
		nr = r + 1;
		nc = c + 1;
		ndir = 1;
		if (nr + 1 <= N && nc <= N && map[nr + 1][nc] == 0) {
			dfs(nr, nc, ndir);
		}
		// 대각선
		nr = r + 1;
		nc = c + 1;
		ndir = 2;
		if (nr + 1 <= N && nc + 1 <= N && map[nr + 1][nc] == 0 && map[nr][nc + 1] == 0 && map[nr + 1][nc + 1] == 0) {
			dfs(nr, nc, ndir);
		}
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
	// r, c, dir
	dfs(1, 1, 0);
	cout << ans;
	return 0;
}