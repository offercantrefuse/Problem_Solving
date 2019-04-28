#include <iostream>
#include <queue>
using namespace std;
struct pos {
	int s, d, z;
	pos(int s, int d, int z) : s(s), d(d), z(z) {}
	pos() {}
};

struct node {
	int r, c, s, d, z;
	node(int r, int c, int s, int d, int z) : r(r), c(c), s(s), d(d), z(z) {}
	node() {}
};

int R, C, M, x, ans;
pos map[101][101];
queue<node> q;

void fish() {
	// 땅과 가장 가까운 상어 잡기
	for (int i = 1; i <= R; i++) {
		if (map[i][x].z > 0) {
			ans += map[i][x].z;
			map[i][x].z = 0;
			map[i][x].d = 0;
			map[i][x].s = 0;
			break;
		}
	}
}

void go() {
	// map 탐색 -> q에 넣고 0으로 바꾸기
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (map[i][j].z > 0) {
				q.push(node(i, j, map[i][j].s, map[i][j].d, map[i][j].z));
				map[i][j].s = 0;
				map[i][j].d = 0;
				map[i][j].z = 0;
			}
		}
	}
	// q에서 pop 하면서 이동 -> map에 넣기
	while (!q.empty()) {
		int rr = q.front().r;
		int cc = q.front().c;
		int ss = q.front().s;
		int dd = q.front().d;
		int zz = q.front().z;
		q.pop();
		if (dd == 1) {  // 위
			if (ss <= rr - 1) { // 첫 구간
				if (map[rr - ss][cc].z < zz) {
					map[rr - ss][cc].s = ss;
					map[rr - ss][cc].d = dd;
					map[rr - ss][cc].z = zz;
				}

			}
			else if (ss > rr - 1 && ss <= rr + R - 2) {  // 두번째 구간
				if (map[1 + ss - (rr - 1)][cc].z < zz) {
					map[1 + ss - (rr - 1)][cc].s = ss;
					map[1 + ss - (rr - 1)][cc].d = 2;
					map[1 + ss - (rr - 1)][cc].z = zz;
				}
			}
			else {  // 세번째 구간
				if (map[R - (ss - (rr + R - 2))][cc].z < zz) {
					map[R - (ss - (rr + R - 2))][cc].s = ss;
					map[R - (ss - (rr + R - 2))][cc].d = dd;
					map[R - (ss - (rr + R - 2))][cc].z = zz;
				}
			}
		}
		else if (dd == 2) {  // 아래
			if (ss <= R - rr) { // 첫 구간
				if (map[rr + ss][cc].z < zz) {
					map[rr + ss][cc].s = ss;
					map[rr + ss][cc].d = dd;
					map[rr + ss][cc].z = zz;
				}
			}
			else if (ss > R - rr && ss <= 2 * R - rr - 1) {  // 두번째 구간
				if (map[R - (ss - (R - rr))][cc].z < zz) {
					map[R - (ss - (R - rr))][cc].s = ss;
					map[R - (ss - (R - rr))][cc].d = 1;
					map[R - (ss - (R - rr))][cc].z = zz;
				}
			}
			else {  // 세번째 구간
				if (map[1 + (ss - (2 * R - rr - 1))][cc].z < zz) {
					map[1 + (ss - (2 * R - rr - 1))][cc].s = ss;
					map[1 + (ss - (2 * R - rr - 1))][cc].d = dd;
					map[1 + (ss - (2 * R - rr - 1))][cc].z = zz;
				}
			}
		}
		else if (dd == 3) {  // 오른
			if (ss <= C - cc) { // 첫 구간
				if (map[rr][cc + ss].z < zz) {
					map[rr][cc + ss].s = ss;
					map[rr][cc + ss].d = dd;
					map[rr][cc + ss].z = zz;
				}

			}
			else if (ss > C - cc && ss <= 2 * C - cc - 1) {  // 두번째 구간
				if (map[rr][C - (ss - (C - cc))].z < zz) {
					map[rr][C - (ss - (C - cc))].s = ss;
					map[rr][C - (ss - (C - cc))].d = 4;
					map[rr][C - (ss - (C - cc))].z = zz;
				}
			}
			else {  // 세번째 구간
				if (map[rr][1 + (ss - (2 * C - cc - 1))].z < zz) {
					map[rr][1 + (ss - (2 * C - cc - 1))].s = ss;
					map[rr][1 + (ss - (2 * C - cc - 1))].d = dd;
					map[rr][1 + (ss - (2 * C - cc - 1))].z = zz;
				}
			}
		}
		else {  // 왼
			if (ss <= cc - 1) { // 첫 구간
				if (map[rr][cc - ss].z < zz) {
					map[rr][cc - ss].s = ss;
					map[rr][cc - ss].d = dd;
					map[rr][cc - ss].z = zz;
				}
			}
			else if (ss > cc - 1 && ss <= cc + C - 2) {  // 두번째 구간
				if (map[rr][1 + ss - (cc - 1)].z < zz) {
					map[rr][1 + ss - (cc - 1)].s = ss;
					map[rr][1 + ss - (cc - 1)].d = 3;
					map[rr][1 + ss - (cc - 1)].z = zz;
				}
			}
			else {  // 세번째 구간
				if (map[rr][C - (ss - (cc + C - 2))].z < zz) {
					map[rr][C - (ss - (cc + C - 2))].s = ss;
					map[rr][C - (ss - (cc + C - 2))].d = dd;
					map[rr][C - (ss - (cc + C - 2))].z = zz;
				}
			}
		}
	}
}

int main() {
	cin >> R >> C >> M;
	for (int i = 0; i < M; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		if (d == 1 || d == 2) s %= (2 * (R - 1));  // 방향에 따라 가로, 세로 길이의 2배 넘는 속도라면 줄여준다.
		else s %= 2 * (C - 1);
		map[r][c].s = s;
		map[r][c].d = d;
		map[r][c].z = z;
	}
	x = 1, ans = 0;
	while (x <= C) {
		fish();  // 상어 잡기
		go(); // 상어 이동
		x++;  // 낚시꾼 이동
	}
	cout << ans << '\n';
	return 0;
}