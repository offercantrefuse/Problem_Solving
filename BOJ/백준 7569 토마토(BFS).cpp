#include <iostream>
#include <queue>
using namespace std;
int M, N, H, cnt = 0, sum = 0, day = 0;
bool found = false;
int visit[100][100][100] = { 0, };
int tomato[100][100][100] = { 0, };
int dx[] = { -1,0,1,0,0,0 };
int dy[] = { 0,-1,0,1,0,0 };
int dz[] = { 0,0,0,0,1,-1 };
struct pos {
	int x, y, z;
	pos(int xx, int yy, int zz) {
		x = xx;
		y = yy;
		z = zz;
	}
	pos() {}
};

queue<pos> q;

void bfs() {
	while (!q.empty()) {
		if (cnt == sum) {
			found = true;
			return;
		}
		int size = q.size();
		for (int t = 0; t < size; t++) {
			int x = q.front().x;
			int y = q.front().y;
			int z = q.front().z;
			q.pop();
			for (int i = 0; i < 6; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				int nz = z + dz[i];
				if (nx<0 || nx>M - 1 || ny<0 || ny>N - 1 || nz<0 || nz>H - 1)continue;
				if (visit[nz][ny][nx] == 0 && tomato[nz][ny][nx] == 0) {
					visit[nz][ny][nx] = 1;
					tomato[nz][ny][nx] = 1;
					cnt++;
					q.push(pos(nx, ny, nz));
				}
			}
		}
		day++;
	}
}

int main() {
	cin >> M >> N >> H;
	sum = M * N * H;
	for (int h = 0; h < H; h++) {  // 높이
		for (int n = 0; n < N; n++) {  // 세로
			for (int m = 0; m < M; m++) {  // 가로
				cin >> tomato[h][n][m];
				if (tomato[h][n][m] == 1) {
					q.push(pos(m, n, h));
					visit[h][n][m] = 1;
					cnt++;
				}
				else if (tomato[h][n][m] == -1) {
					sum--;
				}
			}
		}
	}
	bfs();
	if (found) cout << day << '\n';
	else cout << "-1" << '\n';
	return 0;
}