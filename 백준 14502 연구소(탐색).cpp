#include <iostream>
#include <queue>
using namespace std;
int N, M, ans = 0;
int tt = 0;
int map[8][8] = { 0, };
int tmp[8][8] = { 0, };
int dr[] = { 0,-1,0,1 };
int dc[] = { -1,0,1,0 };
struct pos {
	int r, c;
	pos(int rr, int cc) {
		r = rr;
		c = cc;
	}
	pos() {}
};
pos virus[10];
queue<pos> q;
void copy() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			tmp[i][j] = map[i][j];
		}
	}
}
void bfs(pos p) {
	q.push(p);
	while (!q.empty()) {
		int r = q.front().r;
		int c = q.front().c;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nc<0 || nr>N - 1 || nc>M - 1) continue;
			if (tmp[nr][nc] == 1) continue;
			else if (tmp[nr][nc]==0){
				tmp[nr][nc] = 2;
				q.push(pos(nr, nc));
			}
		}
	}
}
void spread() {
	for (int i = 0; i < tt; i++)
		bfs(virus[i]);
	return;
}
int count() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tmp[i][j] == 0) cnt++;
		}
	}
	return cnt;
}

void dfs(int r, int idx) {
	if (idx == 3) {
		copy();
		spread();
		ans = ans > count() ? ans : count();
		return;
	}
	for (int i = r; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				dfs(i, idx + 1);
				map[i][j] = 0;
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				virus[tt++] = pos(i, j);
			}
		}
	}
	dfs(0, 0);
	cout << ans;
	return 0;
}