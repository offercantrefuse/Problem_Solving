#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct pos {
	int r, c, h;
	pos(int r, int c, int h) : r(r), c(c), h(h) {}
	pos() {}
};
int maze[5][5][5] = { 0, };
int test[5][5][5] = { 0, };
int arr[5][5][5] = { 0, };
int dr[] = { -1,0,1,0,0,0 };
int dc[] = { 0,-1,0,1,0,0 };
int dh[] = { 0,0,0,0,-1,1 };
int direc[5] = { 0, };
int ans = 1000;


vector<int> vec;

void rot(int idx, int dir) {
	int tmp[5][5] = { 0, };
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			arr[idx][i][j] = test[idx][i][j];
		}
	}
	for (int d = 0; d < dir; d++) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				tmp[i][j] = arr[idx][4 - j][i];
			}
		}
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				arr[idx][i][j] = tmp[i][j];
			}
		}
	}

}

int bfs() {
	int visit[5][5][5] = { 0, };
	if (arr[0][0][0] == 0) {
		return 1000;
	}
	queue<pos> q;
	q.push(pos(0, 0, 0));
	visit[0][0][0] = 1;
	while (!q.empty()) {
		int rr = q.front().r;
		int cc = q.front().c;
		int hh = q.front().h;
		q.pop();
		if (rr == 4 && cc == 4 && hh == 4) break;
		for (int d = 0; d < 6; d++) {
			int nr = rr + dr[d];
			int nc = cc + dc[d];
			int nh = hh + dh[d];
			if (nr < 0 || nc < 0 || nh < 0 || nr>4 || nc>4 || nh>4) continue;
			if (visit[nh][nr][nc] == 0 && arr[nh][nr][nc] == 1) {
				visit[nh][nr][nc] = visit[hh][rr][cc] + 1;
				q.push(pos(nr, nc, nh));
			}
		}
	}
	if (visit[4][4][4] == 0) return 1000;
	else return visit[4][4][4] - 1;
}

void solve(int idx) {
	if (idx == 5) {
		for (int i = 0; i < 5; i++) {
			rot(i, direc[i]);
		}
		int tmp = bfs();
		ans = ans < tmp ? ans : tmp;
		return;
	}
	for (int d = 0; d < 4; d++) {
		direc[idx] = d;
		solve(idx + 1);
	}
}

int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				cin >> maze[i][j][k];
			}
		}
	}

	for (int i = 0; i < 5; i++)
		vec.push_back(i);

	ans = 1000;
	do {
		for (int t = 0; t < vec.size(); t++) {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					test[t][i][j] = maze[vec[t]][i][j];
				}
			}
		}
		solve(0);
	} while (next_permutation(vec.begin(), vec.end()));
	if (ans == 1000) cout << "-1";
	else cout << ans;
	return 0;
}