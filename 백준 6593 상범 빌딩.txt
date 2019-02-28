#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
struct pos {
	int x, y, z; // x->c , y->r, z->h
	pos(int x, int y, int z) : x(x), y(y), z(z) {};
	pos() {}
};
int L, R, C, ans = 0;
int dr[] = { 0,-1,0,1,0,0 };
int dc[] = { -1,0,1,0,0,0 };
int dh[] = { 0,0,0,0,-1,1 };
char map[30][30][30];
int visit[30][30][30] = { 0, };
queue<pos> q;
pos fin;

void bfs() {
	while (!q.empty()) {
		int rr = q.front().y;
		int cc = q.front().x;
		int hh = q.front().z;
		if (rr == fin.y && cc == fin.x && hh == fin.z) {
			ans = visit[hh][rr][cc] - 1;
			break;
		}
		q.pop();
		for (int d = 0; d < 6; d++) {
			int nr = rr + dr[d];
			int nc = cc + dc[d];
			int nh = hh + dh[d];
			if (nr<0 || nr>R - 1 || nc<0 || nc>C - 1 || nh<0 || nh>L - 1) continue;
			if (visit[nh][nr][nc] == 0 && map[nh][nr][nc] == '.') {
				visit[nh][nr][nc] = visit[hh][rr][cc] + 1;
				q.push(pos(nc, nr, nh));
			}
		}
	}
}

int main() {
	while (1) {
		cin >> L >> R >> C;
		memset(visit, 0, sizeof(visit));
		memset(map, '#', sizeof(map));
		while (!q.empty()) q.pop();
		if (L == 0 && R == 0 && C == 0) break;
		for (int h = 0; h < L; h++) {
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					cin >> map[h][i][j];
					if (map[h][i][j] == 'S') {
						q.push(pos(j, i, h));
						visit[h][i][j] = 1;
					}
					else if (map[h][i][j] == 'E') {
						fin = pos(j, i, h);
						map[h][i][j] = '.';
					}
				}
			}
		}
		ans = 0;
		bfs();
		if (ans == 0) cout << "Trapped!" << '\n';
		else cout << "Escaped in " << ans << " minute(s)." << '\n';
	}
	return 0;
}