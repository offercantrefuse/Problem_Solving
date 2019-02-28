#include <iostream>
using namespace std;
int N, M;
struct node {
	int r, c, num, dir;
	node(int rr, int cc, int nnum, int ddir) {
		r = rr;
		c = cc;
		num = nnum;
		dir = ddir;
	}
	node() {}
};
int map[8][8] = { 0, };
int tmp[8][8] = { 0, };
int cnum = 0;
int ans = 2000000000;
node cctv[8];

void copy() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			tmp[i][j] = map[i][j];
		}
	}
}

void paint() {
	for (int i = 0; i < cnum; i++) {
		if (cctv[i].num == 1) {
			if (cctv[i].dir == 0) { //¿À
				for (int cc = cctv[i].c + 1; cc < M; cc++) {
					if (tmp[cctv[i].r][cc] == 0) {
						tmp[cctv[i].r][cc] = 9;
					}
					else if (tmp[cctv[i].r][cc] == 6) {
						break;
					}
				}
			}
			else if (cctv[i].dir == 1) { //À§
				for (int rr = cctv[i].r - 1; rr >= 0; rr--) {
					if (tmp[rr][cctv[i].c] == 0) {
						tmp[rr][cctv[i].c] = 9;
					}
					else if (tmp[rr][cctv[i].c] == 6) {
						break;
					}
				}
			}
			else if (cctv[i].dir == 2) { //¿Þ
				for (int cc = cctv[i].c - 1; cc >= 0; cc--) {
					if (tmp[cctv[i].r][cc] == 0) {
						tmp[cctv[i].r][cc] = 9;
					}
					else if (tmp[cctv[i].r][cc] == 6) {
						break;
					}
				}
			}
			else if (cctv[i].dir == 3) { //¾Æ·¡
				for (int rr = cctv[i].r + 1; rr < N; rr++) {
					if (tmp[rr][cctv[i].c] == 0) {
						tmp[rr][cctv[i].c] = 9;
					}
					else if (tmp[rr][cctv[i].c] == 6) {
						break;
					}
				}
			}
		}
		else if (cctv[i].num == 2) {
			if (cctv[i].dir == 0) { // ¿À¿Þ
				for (int cc = cctv[i].c + 1; cc < M; cc++) {
					if (tmp[cctv[i].r][cc] == 0) {
						tmp[cctv[i].r][cc] = 9;
					}
					else if (tmp[cctv[i].r][cc] == 6) {
						break;
					}
				}
				for (int cc = cctv[i].c - 1; cc >= 0; cc--) {
					if (tmp[cctv[i].r][cc] == 0) {
						tmp[cctv[i].r][cc] = 9;
					}
					else if (tmp[cctv[i].r][cc] == 6) {
						break;
					}
				}
			}
			else if (cctv[i].dir == 1) { //À§¾Æ·¡
				for (int rr = cctv[i].r + 1; rr < N; rr++) {
					if (tmp[rr][cctv[i].c] == 0) {
						tmp[rr][cctv[i].c] = 9;
					}
					else if (tmp[rr][cctv[i].c] == 6) {
						break;
					}
				}
				for (int rr = cctv[i].r - 1; rr >= 0; rr--) {
					if (tmp[rr][cctv[i].c] == 0) {
						tmp[rr][cctv[i].c] = 9;
					}
					else if (tmp[rr][cctv[i].c] == 6) {
						break;
					}
				}
			}
		}
		else if (cctv[i].num == 3) {
			if (cctv[i].dir == 0) { // À§¿À
				for (int cc = cctv[i].c + 1; cc < M; cc++) {
					if (tmp[cctv[i].r][cc] == 0) {
						tmp[cctv[i].r][cc] = 9;
					}
					else if (tmp[cctv[i].r][cc] == 6) {
						break;
					}
				}
				for (int rr = cctv[i].r - 1; rr >= 0; rr--) {
					if (tmp[rr][cctv[i].c] == 0) {
						tmp[rr][cctv[i].c] = 9;
					}
					else if (tmp[rr][cctv[i].c] == 6) {
						break;
					}
				}
			}
			else if (cctv[i].dir == 1) { //¿À¾Æ·¡
				for (int cc = cctv[i].c + 1; cc < M; cc++) {
					if (tmp[cctv[i].r][cc] == 0) {
						tmp[cctv[i].r][cc] = 9;
					}
					else if (tmp[cctv[i].r][cc] == 6) {
						break;
					}
				}
				for (int rr = cctv[i].r + 1; rr < N; rr++) {
					if (tmp[rr][cctv[i].c] == 0) {
						tmp[rr][cctv[i].c] = 9;
					}
					else if (tmp[rr][cctv[i].c] == 6) {
						break;
					}
				}
			}
			else if (cctv[i].dir == 2) { //¿Þ¾Æ·¡
				for (int rr = cctv[i].r + 1; rr < N; rr++) {
					if (tmp[rr][cctv[i].c] == 0) {
						tmp[rr][cctv[i].c] = 9;
					}
					else if (tmp[rr][cctv[i].c] == 6) {
						break;
					}
				}
				for (int cc = cctv[i].c - 1; cc >= 0; cc--) {
					if (tmp[cctv[i].r][cc] == 0) {
						tmp[cctv[i].r][cc] = 9;
					}
					else if (tmp[cctv[i].r][cc] == 6) {
						break;
					}
				}
			}
			else if (cctv[i].dir == 3) { //À§¿Þ
				for (int cc = cctv[i].c - 1; cc >= 0; cc--) {
					if (tmp[cctv[i].r][cc] == 0) {
						tmp[cctv[i].r][cc] = 9;
					}
					else if (tmp[cctv[i].r][cc] == 6) {
						break;
					}
				}
				for (int rr = cctv[i].r - 1; rr >= 0; rr--) {
					if (tmp[rr][cctv[i].c] == 0) {
						tmp[rr][cctv[i].c] = 9;
					}
					else if (tmp[rr][cctv[i].c] == 6) {
						break;
					}
				}
			}
		}
		else if (cctv[i].num == 4) {
			if (cctv[i].dir == 0) { //¿ÞÀ§¿À
				for (int cc = cctv[i].c + 1; cc < M; cc++) {
					if (tmp[cctv[i].r][cc] == 0) {
						tmp[cctv[i].r][cc] = 9;
					}
					else if (tmp[cctv[i].r][cc] == 6) {
						break;
					}
				}
				for (int cc = cctv[i].c - 1; cc >= 0; cc--) {
					if (tmp[cctv[i].r][cc] == 0) {
						tmp[cctv[i].r][cc] = 9;
					}
					else if (tmp[cctv[i].r][cc] == 6) {
						break;
					}
				}
				for (int rr = cctv[i].r - 1; rr >= 0; rr--) {
					if (tmp[rr][cctv[i].c] == 0) {
						tmp[rr][cctv[i].c] = 9;
					}
					else if (tmp[rr][cctv[i].c] == 6) {
						break;
					}
				}
			}
			else if (cctv[i].dir == 1) { //À§¿À¾Æ·¡
				for (int cc = cctv[i].c + 1; cc < M; cc++) {
					if (tmp[cctv[i].r][cc] == 0) {
						tmp[cctv[i].r][cc] = 9;
					}
					else if (tmp[cctv[i].r][cc] == 6) {
						break;
					}
				}
				for (int rr = cctv[i].r + 1; rr < N; rr++) {
					if (tmp[rr][cctv[i].c] == 0) {
						tmp[rr][cctv[i].c] = 9;
					}
					else if (tmp[rr][cctv[i].c] == 6) {
						break;
					}
				}
				for (int rr = cctv[i].r - 1; rr >= 0; rr--) {
					if (tmp[rr][cctv[i].c] == 0) {
						tmp[rr][cctv[i].c] = 9;
					}
					else if (tmp[rr][cctv[i].c] == 6) {
						break;
					}
				}
			}
			else if (cctv[i].dir == 2) { //¿À¾Æ·¡¿Þ
				for (int cc = cctv[i].c + 1; cc < M; cc++) {
					if (tmp[cctv[i].r][cc] == 0) {
						tmp[cctv[i].r][cc] = 9;
					}
					else if (tmp[cctv[i].r][cc] == 6) {
						break;
					}
				}
				for (int rr = cctv[i].r + 1; rr < N; rr++) {
					if (tmp[rr][cctv[i].c] == 0) {
						tmp[rr][cctv[i].c] = 9;
					}
					else if (tmp[rr][cctv[i].c] == 6) {
						break;
					}
				}
				for (int cc = cctv[i].c - 1; cc >= 0; cc--) {
					if (tmp[cctv[i].r][cc] == 0) {
						tmp[cctv[i].r][cc] = 9;
					}
					else if (tmp[cctv[i].r][cc] == 6) {
						break;
					}
				}
			}
			else if (cctv[i].dir == 3) { // ¿ÞÀ§¾Æ·¡
				for (int rr = cctv[i].r + 1; rr < N; rr++) {
					if (tmp[rr][cctv[i].c] == 0) {
						tmp[rr][cctv[i].c] = 9;
					}
					else if (tmp[rr][cctv[i].c] == 6) {
						break;
					}
				}
				for (int cc = cctv[i].c - 1; cc >= 0; cc--) {
					if (tmp[cctv[i].r][cc] == 0) {
						tmp[cctv[i].r][cc] = 9;
					}
					else if (tmp[cctv[i].r][cc] == 6) {
						break;
					}
				}
				for (int rr = cctv[i].r - 1; rr >= 0; rr--) {
					if (tmp[rr][cctv[i].c] == 0) {
						tmp[rr][cctv[i].c] = 9;
					}
					else if (tmp[rr][cctv[i].c] == 6) {
						break;
					}
				}
			}
		}
		else if (cctv[i].num == 5) {
			if (cctv[i].dir == 0) { // ´Ù
				// ¿À
				for (int cc = cctv[i].c + 1; cc < M; cc++) {
					if (tmp[cctv[i].r][cc] == 0) {
						tmp[cctv[i].r][cc] = 9;
					}
					else if (tmp[cctv[i].r][cc] == 6) {
						break;
					}
				}
				// ¾Æ·¡
				for (int rr = cctv[i].r + 1; rr < N; rr++) {
					if (tmp[rr][cctv[i].c] == 0) {
						tmp[rr][cctv[i].c] = 9;
					}
					else if (tmp[rr][cctv[i].c] == 6) {
						break;
					}
				}
				// ¿Þ
				for (int cc = cctv[i].c - 1; cc >= 0; cc--) {
					if (tmp[cctv[i].r][cc] == 0) {
						tmp[cctv[i].r][cc] = 9;
					}
					else if (tmp[cctv[i].r][cc] == 6) {
						break;
					}
				}
				// À§
				for (int rr = cctv[i].r - 1; rr >= 0; rr--) {
					if (tmp[rr][cctv[i].c] == 0) {
						tmp[rr][cctv[i].c] = 9;
					}
					else if (tmp[rr][cctv[i].c] == 6) {
						break;
					}
				}
			}
		}
	}
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

void solve(int idx) {
	if (idx == cnum) {
		copy();
		paint();
		ans = ans > count() ? count() : ans;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (cctv[idx].num == 5 && i >= 1) break;
		else if (cctv[idx].num == 2 && i >= 2) break;
		else {
			cctv[idx].dir = i;
			solve(idx + 1);
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] >= 1 && map[i][j] <= 5) {
				cctv[cnum++] = node(i, j, map[i][j], 0);
			}
		}
	}
	solve(0);
	cout << ans;
	return 0;
}