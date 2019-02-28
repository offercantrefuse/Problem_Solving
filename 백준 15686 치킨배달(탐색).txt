#include <iostream>
using namespace std;
struct pos {
	int r, c;
	pos(int rr, int cc) {
		r = rr;
		c = cc;
	}
	pos() {}
};
int N, M, sum = 0;
int numh = 0, numc = 0;
int closing[13] = { 0, }; // 0 close , 1 open
pos home[100], chicken[13];
int ch_dist[100] = { 0, };
int map[50][50] = { 0, };
int ans = 2000000000;

inline int mini(int a, int b) {
	return a > b ? b : a;
}
inline int abs(int a) {
	return a > 0 ? a : -a;
}
inline int dist(pos a, pos b) {
	return abs(a.r - b.r) + abs(a.c - b.c);
}

int solve() {
	int tmp = 0;
	for (int i = 0; i < numh; i++) {
		ch_dist[i] = 101;
	}
	for (int i = 0; i < numc; i++) {
		if (closing[i] == 1) {
			for (int j = 0; j < numh; j++) {
				ch_dist[j] = mini(ch_dist[j], dist(home[j], chicken[i]));
			}
		}
	}
	for (int i = 0; i < numh; i++) {
		tmp += ch_dist[i];
	}
	return tmp;
}

void dfs(int idx, int cnt, int maxnum) {
	if (idx == numc) {
		ans = mini(ans, solve());
		return;
	}
	for (int i = 0; i <= 1; i++) {
		if (i == 0) {
			closing[idx] = 0;
			dfs(idx + 1, cnt, maxnum);
		}
		else {
			if (cnt >= maxnum) break;
			closing[idx] = 1;
			dfs(idx + 1, cnt + 1, maxnum);
		}
	}
}

int main() {
	cin >> N >> M;
	int tmph = 0, tmpc = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				numh++;
				home[tmph].r = i;
				home[tmph].c = j;
				tmph++;
			}
			else if (map[i][j] == 2) {
				numc++;
				chicken[tmpc].r = i;
				chicken[tmpc].c = j;
				tmpc++;
			}
		}
	}
	dfs(0, 0, M);
	cout << ans;
	return 0;
}