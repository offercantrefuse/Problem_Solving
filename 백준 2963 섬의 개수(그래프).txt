#include <iostream>
using namespace std;
int w, h;
int cnt = 0;
int map[50][50] = { 0, };
int visited[50][50] = { 0, };
int dr[] = { 0,-1,-1,-1,0,1,1,1 };
int dc[] = { -1,-1,0,1,1,1,0,-1 };
bool flag = false;

void dfs(int r, int c) {
	if (map[r][c] == 1) {
		flag = true;
		visited[r][c] = 1;
		for (int i = 0; i < 8; i++) {
			int new_r = r + dr[i];
			int new_c = c + dc[i];
			if (new_r < 0 || new_c < 0 || new_r > h - 1 || new_c > w - 1) continue;
			if (visited[new_r][new_c] == 0) {
				visited[new_r][new_c] = 1;
				dfs(new_r, new_c);
			}
		}
	}
}

int main() {
	while (cin >> w >> h) {
		if (w == 0 && h == 0) break;
		cnt = 0;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				cin >> map[i][j];

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				flag = false;
				if (visited[i][j] == 0) dfs(i, j);
				if (flag) cnt++;
			}
		}
		cout << cnt << '\n';
		// ÃÊ±âÈ­
		for (int i = 0; i < 50; i++) {
			for (int j = 0; j < 50; j++) {
				map[i][j] = 0;
				visited[i][j] = 0;
			}
		}
	}
	return 0;
}