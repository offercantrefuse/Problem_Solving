#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct node {
	int r, c, num;
	node(int r, int c, int num) : r(r), c(c), num(num) {}
	node() {}
};
struct pos {
	int r, c;
	pos(int r, int c) : r(r), c(c) {}
	pos() {}
};
queue<node> q;
int R, C, T;
pos clean[2];
int map[50][50];
int dr[] = { -1,0,1,0 };
int dc[] = { 0,1,0,-1 };
vector<pos> up;
vector<pos> down;

void find() {  // 미먼 위치, 값 q에 넣기
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] > 0) {
				q.push(node(i, j, map[i][j]));
			}
		}
	}
}

void spread() {  // q에서 빼면서 4방향 보고 map에 표시
	while (!q.empty()) {
		int rr = q.front().r;
		int cc = q.front().c;
		int nnum = q.front().num;
		q.pop();
		for (int d = 0; d < 4; d++) {
			int nr = rr + dr[d];
			int nc = cc + dc[d];
			if (nr<0 || nc<0 || nr>R - 1 || nc>C - 1 || map[nr][nc] == -1) continue;
			map[rr][cc] -= nnum / 5;
			map[nr][nc] += nnum / 5;
		}
	}
}

void go() { // 위, 아래 나눠서 밀기
	// up 
	for (int i = up.size() - 1; i > 0; i--) {
		map[up[i].r][up[i].c] = map[up[i - 1].r][up[i - 1].c];
	}
	map[up[0].r][up[0].c] = 0;
	// down
	for (int i = down.size() - 1; i > 0; i--) {
		map[down[i].r][down[i].c] = map[down[i - 1].r][down[i - 1].c];
	}
	map[down[0].r][down[0].c] = 0;
}

void up_dir() { // 공기청정기 위쪽 순서
	int d = 1;
	int sr = clean[0].r, sc = clean[0].c;
	while (1) {
		int nr = sr + dr[d];
		int nc = sc + dc[d];
		if (nr<0 || nc<0 || nr>R - 1 || nc>C - 1) {
			d = (d + 3) % 4;
			continue;
		}
		if (nr == clean[0].r && nc == clean[0].c) break;
		sr = nr;
		sc = nc;
		up.push_back(pos(sr, sc));
	}
}

void down_dir() { // 공기청정기 아래쪽 순서
	int d = 1;
	int sr = clean[1].r, sc = clean[1].c;
	while (1) {
		int nr = sr + dr[d];
		int nc = sc + dc[d];
		if (nr<0 || nc<0 || nr>R - 1 || nc>C - 1) {
			d = (d + 1) % 4;
			continue;
		}
		if (nr == clean[1].r && nc == clean[1].c) break;
		sr = nr;
		sc = nc;
		down.push_back(pos(sr, sc));
	}
}

int count() {
	int sum = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] > 0) sum += map[i][j];
		}
	}
	return sum;
}
int main() {
	cin >> R >> C >> T;
	int idx = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				clean[idx].r = i;
				clean[idx++].c = j;
			}
		}
	}
	up_dir();
	down_dir();
	while (T > 0) {
		find();
		spread();
		go();
		T--;
	}
	cout << count() << '\n';
	return 0;
}