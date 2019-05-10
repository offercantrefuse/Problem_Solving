#include <iostream>
#include <cstring>
using namespace std;

int c, n;
int tile[10001];
int used[6] = { 0, };
int map[200][200] = { 0 };
int dr[] = { -1,-1,0,1,1,0 };
int dc[] = { 1,0,-1,-1,0,1 };
bool check[6];

void solve() {
	map[100][100] = 1;  // 첫 칸
	used[1] = 1;
	int nr = 100, nc = 100;
	int d = 0, now = 0;   // d: 방향, now: 타일 번호
	tile[0] = 1;
	while (now < 10000) {
		now++;
		nr = nr + dr[d];
		nc = nc + dc[d];
		while (map[nr + dr[(d + 1) % 6]][nc + dc[(d + 1) % 6]] == 0) {
			d = (d + 1) % 6;
		}
		memset(check, false, sizeof(check));   // 인접 숫자 여부
		for (int i = 0; i < 6; i++) {
			int tmpr = nr + dr[i];
			int tmpc = nc + dc[i];
			check[map[tmpr][tmpc]] = true;
		}
		int mini = 100000;   // 가장 적게 나타난 자원
		int m_idx = 1;
		for (int i = 5; i >= 1; i--) {
			if (!check[i]) {   // 인접한 수 아니면
				if (mini >= used[i]) {
					mini = used[i];
					m_idx = i;
				}
			}
		}
		map[nr][nc] = m_idx;
		used[m_idx]++;
		tile[now] = m_idx;
	}
}

int main() {
	cin >> c;
	solve();
	for (int tc = 1; tc <= c; tc++) {
		cin >> n;
		cout << tile[n - 1] << '\n';
	}
	return 0;
}