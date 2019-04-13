#include <iostream>
using namespace std;
struct node {
	int r, c;
	node(int r, int c) : r(r), c(c) {}
	node() {}
};
int T, N, cnt6, cnt7, cnt8, cnt9, cnt10, ans, cnt;
int map[101][101] = { 0, };
int dr[] = { -1,0,1,0 };
int dc[] = { 0,1,0,-1 };
node worm6[2], worm7[2], worm8[2], worm9[2], worm10[2];

void simul(int r, int c, int d) {
	cnt = 0;
	int tmp = 0;
	int rr = r, cc = c, dd = d;
	while (1) {
		if (rr == r && cc == c && tmp > 0) return;
		tmp++;
		int nr = rr + dr[dd];
		int nc = cc + dc[dd];
		if (nr<0 || nr>N - 1 || nc<0 || nc>N - 1) { // °æ°è ¹Û
			dd = (dd + 2) % 4;
			rr = nr;
			cc = nc;
			cnt++;
			continue;
		}
		// 0 ÀÏ¶§
		if (map[nr][nc] == 0) {
			rr = nr;
			cc = nc;
			continue;
		}
		else {
			rr = nr;
			cc = nc;
			// 1~5 ºí·°
			if (map[nr][nc] == 1) {
				if (dd == 0) {
					dd = dd + 2;
					cnt++;
					continue;
				}
				else if (dd == 1) {
					dd = dd + 2;
					cnt++;
					continue;
				}
				else if (dd == 2) {
					dd = dd - 1;
					cnt++;
					continue;
				}
				else if (dd == 3) {
					dd = dd - 3;
					cnt++;
					continue;
				}
			}
			else if (map[nr][nc] == 2) {
				if (dd == 0) {
					dd = dd + 1;
					cnt++;
					continue;
				}
				else if (dd == 1) {
					dd = dd + 2;
					cnt++;
					continue;
				}
				else if (dd == 2) {
					dd = dd - 2;
					cnt++;
					continue;
				}
				else if (dd == 3) {
					dd = dd - 1;
					cnt++;
					continue;
				}
			}
			else if (map[nr][nc] == 3) {
				if (dd == 0) {
					dd = dd + 3;
					cnt++;
					continue;
				}
				else if (dd == 1) {
					dd = dd + 1;
					cnt++;
					continue;
				}
				else if (dd == 2) {
					dd = dd - 2;
					cnt++;
					continue;
				}
				else if (dd == 3) {
					dd = dd - 2;
					cnt++;
					continue;
				}
			}
			else if (map[nr][nc] == 4) {
				if (dd == 0) {
					dd = dd + 2;
					cnt++;
					continue;
				}
				else if (dd == 1) {
					dd = dd - 1;
					cnt++;
					continue;
				}
				else if (dd == 2) {
					dd = dd + 1;
					cnt++;
					continue;
				}
				else if (dd == 3) {
					dd = dd - 2;
					cnt++;
					continue;
				}
			}
			else if (map[nr][nc] == 5) {
				if (dd == 0) {
					dd = dd + 2;
					cnt++;
					continue;
				}
				else if (dd == 1) {
					dd = dd + 2;
					cnt++;
					continue;
				}
				else if (dd == 2) {
					dd = dd - 2;
					cnt++;
					continue;
				}
				else if (dd == 3) {
					dd = dd - 2;
					cnt++;
					continue;
				}
			}

			// 6~10 ¿úÈ¦
			else if (map[nr][nc] == 6) {
				if (nr == worm6[0].r && cc == worm6[0].c) {
					rr = worm6[1].r;
					cc = worm6[1].c;
					continue;
				}
				else {
					rr = worm6[0].r;
					cc = worm6[0].c;
					continue;
				}
			}
			else if (map[nr][nc] == 7) {
				if (nr == worm7[0].r && cc == worm7[0].c) {
					rr = worm7[1].r;
					cc = worm7[1].c;
					continue;
				}
				else {
					rr = worm7[0].r;
					cc = worm7[0].c;
					continue;
				}
			}
			else if (map[nr][nc] == 8) {
				if (nr == worm8[0].r && cc == worm8[0].c) {
					rr = worm8[1].r;
					cc = worm8[1].c;
					continue;
				}
				else {
					rr = worm8[0].r;
					cc = worm8[0].c;
					continue;
				}
			}
			else if (map[nr][nc] == 9) {
				if (nr == worm9[0].r && cc == worm9[0].c) {
					rr = worm9[1].r;
					cc = worm9[1].c;
					continue;
				}
				else {
					rr = worm9[0].r;
					cc = worm9[0].c;
					continue;
				}
			}
			else if (map[nr][nc] == 10) {
				if (nr == worm10[0].r && cc == worm10[0].c) {
					rr = worm10[1].r;
					cc = worm10[1].c;
					continue;
				}
				else {
					rr = worm10[0].r;
					cc = worm10[0].c;
					continue;
				}
			}
			else if (map[nr][nc] == -1 || nr == r && nc == c) {  // ¿úÈ¦
				return;
			}
		}
	}

}

int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		cnt6 = cnt7 = cnt8 = cnt9 = cnt10 = ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				if (map[i][j] == 6) {
					worm6[cnt6].r = i;
					worm6[cnt6++].c = j;
				}
				else if (map[i][j] == 7) {
					worm7[cnt7].r = i;
					worm7[cnt7++].c = j;
				}
				else if (map[i][j] == 8) {
					worm8[cnt8].r = i;
					worm8[cnt8++].c = j;
				}
				else if (map[i][j] == 9) {
					worm9[cnt9].r = i;
					worm9[cnt9++].c = j;
				}
				else if (map[i][j] == 10) {
					worm10[cnt10].r = i;
					worm10[cnt10++].c = j;
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 0) {
					for (int d = 0; d < 4; d++) {
						simul(i, j, d);
						ans = ans < cnt ? cnt : ans;
					}
				}
			}
		}
		cout << '#' << tc << ' ' << ans << '\n';
	}
	return 0;
}