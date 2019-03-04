#include <iostream>
#include <vector>
using namespace std;
struct pos {
	int r, c;
	pos(int rr, int cc) {
		r = rr;
		c = cc;
	}
};
int T, N, K;
int map[8][8] = { 0, };
int visit[8][8] = { 0, };
vector<pos> peak;
int dc[] = { -1,0,1,0 };
int dr[] = { 0,-1,0,1 };
int ans;

void go(int r, int c, int cnt, bool flag) {
	visit[r][c] = 1;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr<0 || nr>N - 1 || nc<0 || nc>N - 1) continue;
		if (map[nr][nc] < map[r][c] && visit[nr][nc] == 0) {
			go(nr, nc, cnt + 1, flag);
		}
		else if (map[nr][nc] >= map[r][c] && visit[nr][nc] == 0 && flag == false) {
			if (map[nr][nc] - map[r][c] < K) {
				for (int j = K; j > map[nr][nc] - map[r][c]; j--) {
					map[nr][nc] -= j;
					go(nr, nc, cnt + 1, true);
					map[nr][nc] += j;
				}
			}
		}
	}
	visit[r][c] = 0;
	ans = (ans > cnt) ? ans : cnt;
}

int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> K;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		ans = 0;
		int maxi = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				maxi = map[i][j] > maxi ? map[i][j] : maxi;
			}
		}
		int tmp = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == maxi) {
					peak.push_back(pos(i, j));
				}
			}
		}
		for (int i = 0; i < peak.size(); i++) {
			go(peak[i].r, peak[i].c, 0, false);
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				map[i][j] = 0;
				visit[i][j] = 0;
			}
		}
		peak.clear();
		cout << "#" << tc << ' ' << ans +1  << '\n';
	}
	return 0;
}