#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n, m, disc[11][11][11][11], bx, by, rx, ry;
char a[11][11];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int bfs() {
	queue<pair<pair<int, int>, pair<int, int>>> qu;
	qu.push({ { rx,ry },{ bx,by } });
	disc[rx][ry][bx][by] = 1;
	int ret = 0;
	while (qu.size()) {
		int qs = qu.size();
		while (qs--) {
			int x = qu.front().first.first;
			int y = qu.front().first.second;
			int z = qu.front().second.first;
			int w = qu.front().second.second;
			qu.pop();
			if (a[x][y] == 'O'&& a[x][y] != a[z][w])
				return ret;
			for (int i = 0; i < 4; i++) {
				int cx = x, cy = y, cz = z, cw = w;
				while (a[cx + dx[i]][cy + dy[i]] != '#'&&a[cx][cy] != 'O') {
					cx += dx[i];
					cy += dy[i];
				}
				while (a[cz + dx[i]][cw + dy[i]] != '#'&&a[cz][cw] != 'O') {
					cz += dx[i];
					cw += dy[i];
				}
				if (cx == cz && cy == cw) {
					if (a[cx][cy] == 'O') continue;
					if (abs(cx - x) + abs(cy - y) < abs(cz - z) + abs(cw - w)) {
						cz -= dx[i];
						cw -= dy[i];
					}
					else {
						cx -= dx[i];
						cy -= dy[i];
					}
				}
				if (disc[cx][cy][cz][cw])continue;
				qu.push({ { cx,cy } ,{ cz,cw } });
				disc[cx][cy][cz][cw] = 1;
			}
		}
		if (ret == 10)
			return -1;
		ret++;
	}
	return -1;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'B') {
				bx = i;
				by = j;
			}
			else if (a[i][j] == 'R') {
				rx = i;
				ry = j;
			}
		}
	}
	cout << bfs() << endl;
	return 0;
}


