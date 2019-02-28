#include <iostream>
#include <string>
#include <vector>
using namespace std;
char map[12][6];
int num[73] = { 0, };
int visit[12][6] = { 0, };
int dr[] = { -1,0,1,0 };
int dc[] = { 0,-1,0,1 };
int idx = 0;

void dfs(int r, int c, char ch) {
	visit[r][c] = idx;
	num[idx]++;
	for (int d = 0; d < 4; d++) {
		int nr = r + dr[d];
		int nc = c + dc[d];
		if (nr < 0 || nr>11 || nc < 0 || nc>5) continue;
		if (map[nr][nc] != '.' && visit[nr][nc] == 0 && map[nr][nc] == map[r][c]) dfs(nr, nc, map[r][c]);
	}
}

int main() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> map[i][j];
		}
	}
	int ans = 0;
	bool puyo = true; // 뿌요 1개이상 되는지
	while (puyo) {
		// visit, num 초기화
		memset(visit, 0, sizeof(visit));
		memset(num, 0, sizeof(num));
		puyo = false;
		// 탐색: visit 체크 (증가), puyo 체크, room개수 증가
		idx = 1;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (map[i][j] != '.' && visit[i][j] == 0) {
					dfs(i, j, map[i][j]);
					idx++;
				}
			}
		}
		// num중에 4 이상이 있으면 뿌요 가능 -> map '.' 으로
		for (int k = 1; k <= idx; k++) {
			if (num[k] >= 4) {
				puyo = true;
				for (int i = 0; i < 12; i++) {
					for (int j = 0; j < 6; j++) {
						if (visit[i][j] == k) map[i][j] = '.';
					}
				}
			}
		}
		// 한 column씩 밑으로 내려주기
		for (int j = 0; j < 6; j++) {
			vector<char> vec;
			for (int i = 11; i >= 0; i--) {
				if (map[i][j] != '.') vec.push_back(map[i][j]);
			}
			int cnt = 0;
			for (int k = 11; k > 11 - vec.size(); k--) {
				map[k][j] = vec[cnt++];
			}
			for (int k = 11 - vec.size(); k >= 0; k--) {
				map[k][j] = '.';
			}
		}
		if (puyo) ans++;
	}
	cout << ans;
	return 0;
}
