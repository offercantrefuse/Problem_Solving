#include <iostream>
using namespace std;

struct data_type {
	// ºó°ø°£ 0 , ºñÈ°¼º 1, È°¼º 2, Á×À½ 3
	int status;
	int lp, hp;
};

int t, n, m, k;
data_type map[2][352][352];
int dir[4][2] = { {0,-1},{0,1},{1,0},{-1,0} };

int main() {
	cin >> t;

	for (int tc = 1; tc <= t; tc++) {
		cin >> n >> m >> k;
		for (int i = 0; i < n + k + 2; i++) {
			for (int j = 0; j < m + k + 2; j++) {
				map[0][i][j].status = 0;
				map[1][i][j].status = 0;
			}
		}

		for (int i = 0 + k / 2 + 1; i < n + k / 2 + 1; i++) {
			for (int j = 0 + k / 2 + 1; j < m + k / 2 + 1; j++) {
				cin >> map[0][i][j].lp;
				if (map[0][i][j].lp > 0) {
					map[0][i][j].status = 1;
					map[0][i][j].hp = 0;
				}
			}
		}

		n = n + k + 2;
		m = m + k + 2;

		int curmap = 0;
		for (int kk = 0; kk < k; kk++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (map[curmap][i][j].status == 3) {
						map[1 - curmap][i][j].status = map[curmap][i][j].status;
						continue;
					}
					else if (map[curmap][i][j].status == 1) {
						map[1 - curmap][i][j].hp = map[curmap][i][j].hp + 1;
						map[1 - curmap][i][j].lp = map[curmap][i][j].lp;
						if (map[1 - curmap][i][j].hp == map[1 - curmap][i][j].lp)
							map[1 - curmap][i][j].status = 2;
						else
							map[1 - curmap][i][j].status = 1;
					}
					else if (map[curmap][i][j].status == 2) {
						if (map[curmap][i][j].hp == map[curmap][i][j].lp) {
							for (int d = 0; d < 4; d++) {
								int i2, j2;
								i2 = i + dir[d][0];
								j2 = j + dir[d][1];
								if (map[curmap][i2][j2].status == 0) {
									if (map[1 - curmap][i2][j2].status == 0) {
										map[1 - curmap][i2][j2].status = 1;
										map[1 - curmap][i2][j2].lp = map[curmap][i][j].lp;
										map[1 - curmap][i2][j2].hp = 0;
									}
									else if (map[1 - curmap][i2][j2].status == 1 && map[1 - curmap][i2][j2].lp < map[curmap][i][j].lp)
										map[1 - curmap][i2][j2].lp = map[curmap][i][j].lp;
								}
							}
						}
						map[1 - curmap][i][j].hp = map[curmap][i][j].hp - 1;
						if (map[1 - curmap][i][j].hp == 0)
							map[1 - curmap][i][j].status = 3;
						else
							map[1 - curmap][i][j].status = 2;
					}
				}
			}
			curmap = 1 - curmap;
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[curmap][i][j].status == 1 || map[curmap][i][j].status == 2)
					ans++;
			}
		}
		cout << "#" << tc << ' ' << ans << '\n';
	}
	return 0;
}