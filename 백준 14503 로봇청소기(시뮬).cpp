#include <iostream>
#include <vector>
using namespace std;
int N, M, r, c, d;
int map[50][50] = { 0, };
int clean[50][50] = { 0, };
int dnum = 0;
int dr[] = { -1,0,1,0 };
int dc[] = { 0,1,0,-1 };
int main() {
	cin >> N >> M;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	while (1) {
		if (dnum == 4) {
			r += dr[(d + 2) % 4];
			c += dc[(d + 2) % 4];
			if (map[r][c] == 1) break;
			else {
				dnum = 0;
				continue;
			}
		}
		if (clean[r][c] == 0) {
			clean[r][c] = 1;
		}
		int nd = (d + 3) % 4;
		int nr = r + dr[nd];
		int nc = c + dc[nd];
		if (clean[nr][nc] == 0 && map[nr][nc] == 0) {
			r = nr;
			c = nc;
			d = nd;
			dnum = 0;
			continue;
		}
		else if (clean[nr][nc] == 1 || map[nr][nc] == 1) {
			dnum++;
			d = nd;
			continue;
		}
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (clean[i][j] == 1) cnt++;
		}
	}
	cout << cnt;
	return 0;
}