#include <iostream>
#include <queue>
using namespace std;
struct pos {
	int r, c, crack;  // ±ú¸é 1 
	pos(int r, int c, int crack) : r(r), c(c), crack(crack) {}
	pos() {}
};
int N, M, cnt;
bool found;
char map[1001][1001];
int visit[1001][1001][2] = { 0, };
int dr[] = { -1,0,1,0 };
int dc[] = { 0, -1,0,1 };
queue<pos> q;

void bfs() {
	cnt = 0;
	while (!q.empty()) {
		cnt++;
		int size = q.size();
		for (int t = 0; t < size; t++) {
			int rr = q.front().r;
			int cc = q.front().c;
			int cr = q.front().crack;
			if (cr == 0) visit[rr][cc][0] = 1;
			else visit[rr][cc][1] = 1;
			q.pop();
			if (rr == N && cc == M) {
				found = true;
				return;
			}
			for (int d = 0; d < 4; d++) {
				int nr = rr + dr[d];
				int nc = cc + dc[d];
				if (nr<1 || nr>N || nc<1 || nc>M) continue;
				if (visit[nr][nc][cr] == 0) {
					if (map[nr][nc] == '0') {
						q.push(pos(nr, nc, cr));
						if (cr == 0) visit[nr][nc][0] = 1;
						else visit[nr][nc][1] = 1;
					}
					else {
						if (cr == 0) {
							q.push(pos(nr, nc, 1));
							if (cr == 0) visit[nr][nc][0] = 1;
							else visit[nr][nc][1] = 1;
						}
					}
				}
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}
	q.push(pos(1, 1, 0));
	found = false;
	bfs();
	if (found) cout << cnt;
	else cout << "-1";
	return 0;
}