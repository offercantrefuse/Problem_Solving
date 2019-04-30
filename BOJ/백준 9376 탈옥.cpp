#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct pos {
	int r, c;
	pos(int r, int c) : r(r), c(c) {}
	pos() {}
};
int T, H, W, ans;
char map[102][102];
int visit1[102][102];
int visit2[102][102];
int visit3[102][102];
int all[102][102];
int dr[] = { -1,0,1,0 };
int dc[] = { 0,1,0,-1 };

pos thief[3];
queue<pos> q1;
queue<pos> q2;
queue<pos> q3;
vector<pos> door;

void bfs1() {
	while (!q1.empty()) {
		int rr = q1.front().r;
		int cc = q1.front().c;
		q1.pop();
		for (int d = 0; d < 4; d++) {
			int nr = rr + dr[d];
			int nc = cc + dc[d];
			if (nr<0 || nc<0 || nr>H + 1 || nc>W + 1) continue;
			if (map[nr][nc] == '.' || map[nr][nc] == '$') {
				if (visit1[nr][nc] == 0 || (visit1[nr][nc] > visit1[rr][cc])) {  // 방문을 안했거나 or 더 짧게 방문 가능하면 들어감
					q1.push(pos(nr, nc));
					visit1[nr][nc] = visit1[rr][cc];
				}
			}
			else if (map[nr][nc] == '#') {
				if (visit1[nr][nc] == 0 || (visit1[nr][nc] > visit1[rr][cc] + 1)) {  // 문이면 +1 하면서 방문
					q1.push(pos(nr, nc));
					visit1[nr][nc] = visit1[rr][cc] + 1;
				}
			}
		}
	}
}

void bfs2() {
	while (!q2.empty()) {
		int rr = q2.front().r;
		int cc = q2.front().c;
		q2.pop();
		for (int d = 0; d < 4; d++) {
			int nr = rr + dr[d];
			int nc = cc + dc[d];
			if (nr<0 || nc<0 || nr>H + 1 || nc>W + 1) continue;
			if (map[nr][nc] == '.' || map[nr][nc] == '$') {
				if (visit2[nr][nc] == 0 || (visit2[nr][nc] > visit2[rr][cc])) {
					q2.push(pos(nr, nc));
					visit2[nr][nc] = visit2[rr][cc];
				}
			}
			else if (map[nr][nc] == '#') {
				if (visit2[nr][nc] == 0 || (visit2[nr][nc] > visit2[rr][cc] + 1)) {
					q2.push(pos(nr, nc));
					visit2[nr][nc] = visit2[rr][cc] + 1;
				}
			}
		}
	}
}

void bfs3() {
	while (!q3.empty()) {
		int rr = q3.front().r;
		int cc = q3.front().c;
		q3.pop();
		for (int d = 0; d < 4; d++) {
			int nr = rr + dr[d];
			int nc = cc + dc[d];
			if (nr<0 || nc<0 || nr>H + 1 || nc>W + 1) continue;
			if (map[nr][nc] == '.' || map[nr][nc] == '$') {
				if (visit3[nr][nc] == 0 || (visit3[nr][nc] > visit3[rr][cc])) {
					q3.push(pos(nr, nc));
					visit3[nr][nc] = visit3[rr][cc];
				}
			}
			else if (map[nr][nc] == '#') {
				if (visit3[nr][nc] == 0 || (visit3[nr][nc] > visit3[rr][cc] + 1)) {
					q3.push(pos(nr, nc));
					visit3[nr][nc] = visit3[rr][cc] + 1;
				}
			}
		}
	}
}

void add_all() {
	for (int i = 0; i < H + 2; i++) {
		for (int j = 0; j < W + 2; j++) {
			if (map[i][j] == '.' || map[i][j] == '$') {  // 문이 아닌 곳은 방문만 한 곳이므로 처음에 visit=1 이었으므로 -3을 해줌
				all[i][j] = visit1[i][j] + visit2[i][j] + visit3[i][j] - 3;
			}
			else if (map[i][j] == '#') {  // 문인 곳은 visit=1 이었던 세 곳 -3 을 해준 뒤 각각 문을 3번 연 것이므로 -2를 해줌
				all[i][j] = visit1[i][j] + visit2[i][j] + visit3[i][j] - 5;
			}
		}
	}
}

void cmp() {
	for (int i = 0; i < H + 2; i++) {
		for (int j = 0; j < W + 2; j++) {
			if (map[i][j] != '*')
				ans = ans < all[i][j] ? ans : all[i][j];
		}
	}
}

int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> H >> W;
		for (int i = 0; i < 102; i++) {  // 초기화
			for (int j = 0; j < 102; j++) {
				map[i][j] = '.';
				visit1[i][j] = 0;
				visit2[i][j] = 0;
				visit3[i][j] = 0;
				all[i][j] = 0;
			}
		}
		ans = 200000;
		thief[0] = pos(0, 0);
		int idx = 1;
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) {
				cin >> map[i][j];
				if (map[i][j] == '$') thief[idx++] = pos(i, j);
				else if (map[i][j] == '#') {
					door.push_back(pos(i, j));
				}
			}
		}
		q1.push(thief[0]);   // 도둑 1,2,3 위치 queue에 넣기
		q2.push(thief[1]);
		q3.push(thief[2]);

		visit1[thief[0].r][thief[0].c] = 1;   // 첫 위치 1로
		visit2[thief[1].r][thief[1].c] = 1;
		visit3[thief[2].r][thief[2].c] = 1;

		bfs1();
		bfs2();
		bfs3();
		add_all();
		cmp();

		door.clear();

		cout << ans << '\n';
	}
	return 0;
}