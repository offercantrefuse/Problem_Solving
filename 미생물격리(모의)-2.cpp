#include <iostream>
using namespace std;
struct node {
	int num, dir, big;
	node(int nnum, int ddir, int bbig) {
		num = nnum;
		dir = ddir;
		big = bbig;
	}
	node() {}
};
int T, N, M, K;
int cur;
int dr[5] = { 0,-1,1,0,0 };
int dc[5] = { 0,0,0,-1,1 };
node map[2][100][100];

int oppo(int dir) {
	if (dir == 1) return 2;
	else if (dir == 2) return 1;
	else if (dir == 3) return 4;
	else return 3;
}

void move() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[cur][i][j].num > 0) {
				int nr = i + dr[map[cur][i][j].dir];
				int nc = j + dc[map[cur][i][j].dir];
				if (nr == 0 || nc == 0 || nr == N - 1 || nc == N - 1) {
					map[1 - cur][nr][nc].num = map[cur][i][j].num / 2;
					map[1 - cur][nr][nc].dir = oppo(map[cur][i][j].dir);
				}
				else {
					if (map[1 - cur][nr][nc].num > 0) {
						if (map[1 - cur][nr][nc].big < map[cur][i][j].num) {
							map[1 - cur][nr][nc].big = map[cur][i][j].num;
							map[1 - cur][nr][nc].num += map[cur][i][j].num;
							map[1 - cur][nr][nc].dir = map[cur][i][j].dir;
						}
						else {
							map[1 - cur][nr][nc].num += map[cur][i][j].num;
						}
					}
					else {
						map[1 - cur][nr][nc].num = map[cur][i][j].num;
						map[1 - cur][nr][nc].dir = map[cur][i][j].dir;
						map[1 - cur][nr][nc].big = map[cur][i][j].num;
					}
				}
			}
			map[cur][i][j].num = 0;
			map[cur][i][j].dir = 0;
			map[cur][i][j].big= 0;
		}
	}
	cur = 1 - cur;
}

int main() {
	cin >> T;
	int ans = 0;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> M >> K;
		for (int i = 0; i < K; i++) {
			int tmpr, tmpc, tmpnum, tmpdir;
			cin >> tmpr >> tmpc >> tmpnum >> tmpdir;
			map[0][tmpr][tmpc].num = tmpnum;
			map[0][tmpr][tmpc].dir = tmpdir;
		}
		ans = 0;
		cur = 0;
		for (int i = 0; i < M; i++)
			move();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ans += map[cur][i][j].num;
			}
		}
		cout << "#" << tc << ' ' << ans << '\n';

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				map[cur][i][j].num = 0;
				map[cur][i][j].dir = 0;
			}
		}
	}
	return 0;
}