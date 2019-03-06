#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
struct pos {
	int r, c;
	pos(int r, int c) : r(r), c(c) {}
	pos() {}
};
int T, w, h, ans;
char map[1000][1000] = { 0, };
int visit[1000][1000] = { 0, };
int dr[] = { -1,0,1,0 };
int dc[] = { 0,-1,0,1 };
queue<pos> qsang;
queue<pos> qfire;
bool esc = false;

void move_fire() {
	int qsize = qfire.size();
	for (int t = 0; t < qsize; t++) {
		int rr = qfire.front().r;
		int cc = qfire.front().c;
		qfire.pop();
		for (int d = 0; d < 4; d++) {
			int nr = rr + dr[d];
			int nc = cc + dc[d];
			if (nr<0 || nc<0 || nr>h - 1 || nc>w - 1) continue;
			if (map[nr][nc] == '.') {
				map[nr][nc] = '*';
				qfire.push(pos(nr, nc));
			}
		}
	}
}

void move_sang() {
	int qsize = qsang.size();
	for (int t = 0; t < qsize; t++) {
		int rr = qsang.front().r;
		int cc = qsang.front().c;
		if (rr == 0 || cc == 0 || rr == h - 1 || cc == w - 1) {
			esc = true;
			ans = visit[rr][cc];
			return;
		}
		qsang.pop();
		for (int d = 0; d < 4; d++) {
			int nr = rr + dr[d];
			int nc = cc + dc[d];
			if (nr<0 || nc<0 || nr>h - 1 || nc>w - 1) continue;
			if (map[nr][nc] == '.' && visit[nr][nc] == 0) {
				visit[nr][nc] = visit[rr][cc] + 1;
				qsang.push(pos(nr, nc));
			}
		}
	}
}

int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		memset(visit, 0, sizeof(visit));
		cin >> w >> h;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
				if (map[i][j] == '@') {
					qsang.push(pos(i, j));
					visit[i][j] = 1;
					map[i][j] == '.';
				}
				else if (map[i][j] == '*') {
					qfire.push(pos(i, j));
				}
			}
		}
		esc = false;
		ans = 0;
		while (!qsang.empty() && !esc) {
			move_fire();
			move_sang();
		}
		while (!qsang.empty()) qsang.pop();
		while (!qfire.empty()) qfire.pop();

		if (esc) cout << ans << '\n';
		else cout << "IMPOSSIBLE" << '\n';
	}


	return 0;
}