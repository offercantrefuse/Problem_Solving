#include <iostream>
using namespace std;
int N, K, L, ans;
int map[101][101] = { 0, };
int snake[101][101] = { 0, };
int headr = 1, headc = 1;
int head = 0, tail = 0;
int dr[] = { 0,-1,0,1 };
int dc[] = { 1,0,-1,0 };
bool flag = false;
struct info {
	int hour, direc;
	info(int hh, int dd) {
		hour = hh;
		direc = dd;
	}
	info() {}
};
char move_info[10000];
struct pos {
	int r, c;
	pos(int rr, int cc) {
		r = rr;
		c = cc;
	}
	pos() {}
};
pos sn[10201];

void move(int hr, int hc, int d) {
	ans++;
	int nr = hr + dr[d];
	int nc = hc + dc[d];
	if (nr < 1 || nc<1 || nr>N || nc>N || snake[nr][nc] == 1) {
		flag = true;
		return;
	}
	if (map[nr][nc] == 1) {
		headr = nr;
		headc = nc;
		head++;
		sn[head] = pos(nr, nc);
		snake[sn[tail].r][sn[tail].c] = 1;
		snake[nr][nc] = 1;
		map[nr][nc] = 0;
	}
	else if (map[nr][nc] == 0) {
		headr = nr;
		headc = nc;
		snake[sn[tail].r][sn[tail].c] = 0;
		tail++;
		head++;
		sn[head] = pos(nr, nc);
		snake[nr][nc] = 1;
	}
}

int conv(char c, int dir) {
	if (c == 'D') {
		return (dir + 3) % 4;
	}
	else if (c == 'L') {
		return (dir + 1) % 4;
	}
	else {
		return dir;
	}
}

void go() {
	int dir = 0;
	headr = 1, headc = 1;
	int cnt = 0;
	while (1) {
		if (flag) return;
		move(headr, headc, dir);
		cnt++;
		dir = conv(move_info[cnt], dir);
	}
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int tmpr, tmpc;
		cin >> tmpr >> tmpc;
		map[tmpr][tmpc] = 1;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		int tmpa;
		char tmpc;
		cin >> tmpa >> tmpc;
		move_info[tmpa] = tmpc;
	}
	ans = 0;
	sn[0] = pos(1, 1);
	go();
	cout << ans;
	return 0;
}