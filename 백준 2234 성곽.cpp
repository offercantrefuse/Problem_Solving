#include <iostream>
using namespace std;
int n, m, room = 0;
int map[50][50] = { 0, };
int visit[50][50] = { 0, };
int room_area[2501] = { 0, };
int adj[2501][2501] = { 0, };
int dr[] = { 0,-1,0,1 };
int dc[] = { -1,0,1,0 };

void dfs(int r, int c, int num) {  // visit에 방번호 넣기
	visit[r][c] = room;
	room_area[room]++;
	for (int d = 0; d < 4; d++) {
		int nr = r + dr[d];
		int nc = c + dc[d];
		if (nr<0 || nr>m - 1 || nc<0 || nc>n - 1) continue;
		if (map[r][c] & (1 << d) || visit[nr][nc] > 0) continue;
		else {
			dfs(nr, nc, map[nr][nc]);
		}
	}
}

void color(int r, int c) {  // 인접행렬 표시
	for (int d = 0; d < 4; d++) {
		int nr = r + dr[d];
		int nc = c + dc[d];
		if (nr<0 || nr>m - 1 || nc<0 || nc>n - 1) continue;
		if (visit[r][c] != visit[nr][nc]) {
			adj[visit[r][c]][visit[nr][nc]] = 1;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] == 0) {
				room++;
				dfs(i, j, map[i][j]);
			}
		}
	}
	int maxi = 0;
	for (int i = 0; i <= room; i++)  // 방넓이 최대값
		maxi = maxi > room_area[i] ? maxi : room_area[i];

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			color(i, j);
		}
	}
	int maxi2 = maxi; // 칸막이빼고 방넓이 최대값
	for (int i = 0; i <= room; i++) {
		for (int j = 0; j <= room; j++) {
			if (adj[i][j] == 1) {
				maxi2 = maxi2 > room_area[i] + room_area[j] ? maxi2 : room_area[i] + room_area[j];
			}
		}
	}

	cout << room << '\n' << maxi << '\n' << maxi2 << '\n';
	return 0;
}