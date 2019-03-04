#include <iostream>
#include <cstring>
using namespace std;

int N, M, ans, cc;
int map[20][20] = { 0, };
int visit[20][20] = { 0, };
int check[20][20] = { 0, };
int dr[] = { -1,0,1,0 };
int dc[] = { 0,-1,0,1 };
bool fail = false;

void find(int r, int c) {
	for (int d = 0; d < 4; d++) {
		int nr = r + dr[d];
		int nc = c + dc[d];
		if (nr<0 || nc<0 || nr>N - 1 || nc>M - 1) continue;
		if (map[nr][nc] == 0) {
			cc = 0;
			fail = true;
		}
		if (map[nr][nc] == 2 && check[nr][nc] == 0) {
			check[nr][nc] = 1;
			cc++;
			find(nr, nc);
		}
	}
}

int solve() {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 2 && check[i][j] == 0) {
				check[i][j] = 1;
				cc = 1;
				fail = false;
				find(i, j);
				if (!fail) sum += cc;
			}
		}
	}
	return sum;
}

void baduk(int r, int cnt) {
	if (cnt == 2) {
		memset(check, 0, sizeof(check));
		int tmp = solve();
		ans = ans > tmp ? ans : tmp;
		return;
	}
	for (int i = r; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0 && visit[i][j] == 0) {
				visit[i][j] = 1;
				map[i][j] = 1;
				baduk(i, cnt + 1);
				visit[i][j] = 0;
				map[i][j] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	ans = 0;
	baduk(0, 0);
	cout << ans;
	return 0;
}