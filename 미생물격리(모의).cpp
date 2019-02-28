#include <iostream>
using namespace std;

typedef struct {
	int cnt;
	int dir;
	int maxcnt;
}node;

int n, m, k;
node map[101][101];
node next_map[101][101];
int xy[5][2] = { {0,0},{-1,0},{1,0},{0,-1},{0,1} };

void move() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j].cnt > 0) {
				int dir = map[i][j].dir;
				int nextx = i + xy[dir][0];
				int nexty = j + xy[dir][1];

				if (nextx == 0 || nextx == n - 1 || nexty == 0 || nexty == n - 1) {
					next_map[nextx][nexty].cnt = map[i][j].cnt / 2;

					if (dir == 1) {
						next_map[nextx][nexty].dir = 2;
					}
					else if (dir == 2) {
						next_map[nextx][nexty].dir = 1;
					}
					else if (dir == 3) {
						next_map[nextx][nexty].dir = 4;
					}
					else if (dir == 4) {
						next_map[nextx][nexty].dir = 3;
					}
				}
				else {
					if (next_map[nextx][nexty].maxcnt > 0) {
						next_map[nextx][nexty].cnt += map[i][j].cnt;
						if (next_map[nextx][nexty].maxcnt < map[i][j].cnt) {
							next_map[nextx][nexty].maxcnt = map[i][j].cnt;
							next_map[nextx][nexty].dir = map[i][j].dir;
						}
					}
					else {
						next_map[nextx][nexty].cnt = map[i][j].cnt;
						next_map[nextx][nexty].maxcnt = map[i][j].cnt;
						next_map[nextx][nexty].dir = map[i][j].dir;
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = next_map[i][j];
			next_map[i][j] = { 0,0,0 };
		}
	}
}

int get_answer() {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum += map[i][j].cnt;
		}
	}
	return sum;
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int tmp_x, tmp_y, tmp_cnt, tmp_dir;

		cin >> n >> m >> k;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				map[i][j] = { 0,0,0 };
		for (int i = 0; i < k; i++) {
			cin >> tmp_x >> tmp_y >> tmp_cnt >> tmp_dir;
			map[tmp_x][tmp_y] = { tmp_cnt,tmp_dir,tmp_cnt };
		}

		for (int i = 0; i < m; i++) {
			move();
		}

		cout << "#" << tc << ' ' << get_answer() << endl;
	}
	return 0;
}