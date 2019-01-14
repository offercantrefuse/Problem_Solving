#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
struct pos {
	int r, c, h;
	pos(int rr, int cc, int hh) {
		r = rr;
		c = cc;
		h = hh;
	}
	pos() {}
};
int N, M, cnt_ice = 0, year = 0;
int map[300][300] = { 0, };
int visit[300][300] = { 0, };
int dr[] = { -1,0,1,0 };
int dc[] = { 0,-1,0,1 };
vector<pos> ice;

int act(int row, int col) {  // 4방향 0 개수 세기
	int cnt_zero = 0;
	for (int i = 0; i < 4; i++) {
		int nr = row + dr[i];
		int nc = col + dc[i];
		if (nr<0 || nr>N - 1 || nc<0 || nc>M - 1) continue;
		if (map[nr][nc] == 0) cnt_zero++;
	}
	return cnt_zero;
}

void melt() {  // vector 순회하면서 녹이기
	int size = ice.size();
	for (int i = 0; i < size; i++) {
		ice[i].h -= act(ice[i].r, ice[i].c);
		if (ice[i].h <= 0) ice[i].h = 0;
	}
	for (int i = size - 1; i >= 0; i--) {
		map[ice[i].r][ice[i].c] = ice[i].h;
		if (ice[i].h == 0) ice.erase(ice.begin() + i);

	}
}

void dfs(int r, int c) {  // vector의 [0] 번째부터 연결된 것 세기
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr<0 || nr>N - 1 || nc<0 | nc>M - 1) continue;
		if (visit[nr][nc] == 0 && map[nr][nc] > 0) {
			cnt_ice++;
			visit[nr][nc] = 1;
			dfs(nr, nc);
		}
	}
}

bool find() {   // 2개 이상이면 true
	dfs(ice[0].r, ice[0].c);
	if (cnt_ice != ice.size()) return true;
	else return false;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] > 0) {
				ice.push_back(pos(i, j, map[i][j]));
			}
		}
	}
	while (!find()) {
		melt();
		year++;
		cnt_ice = 0;
		memset(visit, 0, sizeof(visit));
		if (ice.size() == 0) {
			year = 0;
			break;
		}
	}
	cout << year;
	return 0;
}
