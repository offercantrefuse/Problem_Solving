#include <iostream>
using namespace std;
int N, M, H;
int map[31][11] = { 0, };
bool flag = false;
void paint(int r, int c) {
	map[r][c] = 1;
	map[r][c + 1] = -1;
}
void unpaint(int r, int c) {
	map[r][c] = 0;
	map[r][c + 1] = 0;
}

bool check() {
	for (int j = 1; j <= N; j++) {
		int tmp = j;
		for (int i = 1; i <= H; i++) {
			if (map[i][tmp] == 1) tmp++;
			else if (map[i][tmp] == -1) tmp--;
		}
		if (tmp != j) return false;
	}
	return true;
}

void dfs(int r, int idx) {
	if (flag) return;
	if (idx == 0) {
		if (check()) {
			flag = true;
			return;
		}
		return;
	}
	for (int i = r; i <= H; i++) {
		for (int j = 1; j < N; j++) {
			if (flag) return;
			if (map[i][j] == 0 && map[i][j + 1] == 0) {
				paint(i, j);
				dfs(i, idx - 1);
				unpaint(i, j);
			}
		}
	}
}

int main() {
	cin >> N >> M >> H;
	int ans = 4;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		paint(a, b);
	}
	for (int i = 0; i <= 3; i++) {
		dfs(1, i);
		if (flag) {
			ans = i;
			break;
		}
	}
	if (ans > 3) cout << "-1";
	else cout << ans;
	return 0;
}