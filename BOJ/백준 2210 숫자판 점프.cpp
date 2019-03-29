#include <iostream>
#include <set>
using namespace std;
int map[5][5];
bool visit[5][5];
int dr[] = { -1,0,1,0 };
int dc[] = { 0,-1,0,1 };
set<int> s;
void dfs(int r, int c, int num, int cnt) {
	if (cnt == 5) {
		s.insert(num);
		return;
	}
	for (int d = 0; d < 4; d++) {
		int nr = r + dr[d];
		int nc = c + dc[d];
		if (nr < 0 || nc < 0 || nr>4 || nc>4) continue;
		dfs(nr, nc, num * 10 + map[nr][nc], cnt + 1);
	}
}

int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dfs(i, j, map[i][j], 0);
		}
	}
	cout << s.size();
	return 0;
}