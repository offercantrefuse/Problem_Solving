#include <iostream>
using namespace std;
int T, N, M, C;
int map[10][10] = { 0, };
int visit[10][10] = { 0, };
int profit1 = 0, profit2 = 0;
int ans;
struct pos {
	int r, c;
	pos(int rr, int cc) {
		r = rr;
		c = cc;
	}
	pos() {}
};
pos honey[2];
inline int maxi(int a, int b) { return a > b ? a : b; }
bool check(int r, int c) {
	for (int j = 0; j < M; j++) {
		if (visit[r][c + j] == 1) return false;
	}
	return true;
}

void visited(int r, int c) {
	for (int j = 0; j < M; j++)
		visit[r][c + j] = 1;
}

void unvisited(int r, int c) {
	for (int j = 0; j < M; j++)
		visit[r][c + j] = 0;
}

void fm0(int r, int c, int cnt, int pf) {
	if (c > honey[0].c + M - 1) {
		profit1 = maxi(pf, profit1);
		return;
	}
	for (int j = c; j <= honey[0].c + M - 1; j++) {
		if (cnt + map[r][j] <= C) {
			fm0(r, j + 1, cnt + map[r][j], pf + map[r][j] * map[r][j]);
		}
		else {
			fm0(r, j + 1, cnt, pf);
		}
	}
}
void fm1(int r, int c, int cnt, int pf) {
	if (c > honey[1].c + M - 1) {
		profit2 = maxi(pf, profit2);
		return;
	}
	for (int j = c; j <= honey[1].c + M - 1; j++) {
		if (cnt + map[r][j] <= C) {
			fm1(r, j + 1, cnt + map[r][j], pf + map[r][j] * map[r][j]);
		}
		else {
			fm1(r, j + 1, cnt, pf);
		}
	}
}

void dfs(int idx) {
	if (idx == 2) {
		profit1 = 0, profit2 = 0;
		fm0(honey[0].r, honey[0].c, 0, 0);
		fm1(honey[1].r, honey[1].c, 0, 0);
		ans = maxi(ans,profit1 + profit2);
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= N - M; j++) {
			if (check(i, j)) {
				honey[idx] = pos(i, j);
				visited(i, j);
				dfs(idx + 1);
				unvisited(i, j);
			}
		}
	}

}

int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> M >> C;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		ans = 0;
		dfs(0);
		cout << "#" << tc << ' ' << ans << '\n';
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				map[i][j] = 0;
				visit[i][j] = 0;
			}
		}
	}
	return 0;
}