#include <iostream>
#include <vector>
using namespace std;
struct pos{
	int r, c;
	pos(int r, int c) : r(r), c(c) {}
	pos(){}
};
int N, M;
int map[100][100] = { 0, };
int dr[] = { -1,0,1,0 };
int dc[] = { 0,-1,0,1 };
int visit[100][100] = { 0, };
vector<pos> cheese;
vector<pos> n_cheese;

void color(int r, int c) {
	map[r][c] = 2;
	visit[r][c] = 1;
	for (int d = 0; d < 4; d++) {
		int nr = r + dr[d];
		int nc = c + dc[d];
		if (nr<0 || nr>N - 1 || nc<0 || nc>M - 1) continue;
		if (visit[nr][nc] == 0 && map[nr][nc] == 0) {
			color(nr, nc);
		}
	}
}

bool check(pos p) {
	int cnt = 0;
	for (int d = 0; d < 4; d++) {
		int nr = p.r + dr[d];
		int nc = p.c + dc[d];
		if (map[nr][nc] == 2) cnt++;
	}
	return cnt >= 2 ? true : false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				cheese.push_back(pos(i, j));
			}
		}
	}
	int time = 0;
	color(0, 0);
	while (!cheese.empty()) {
		for (int i = 0; i < cheese.size();i++) {
			if (check(cheese[i])) {  // 치즈 바깥 확인
				map[cheese[i].r][cheese[i].c] = 0;
				n_cheese.push_back(cheese[i]);
				cheese.erase(cheese.begin() + i);
				i--;
			}
		}
		for (int i = n_cheese.size()-1; i >=0; i--) {
			color(n_cheese[i].r, n_cheese[i].c);
			n_cheese.pop_back();
		}
		time++;
	}
	cout << time;
	return 0;
}