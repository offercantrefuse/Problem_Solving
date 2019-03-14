#include <iostream>
using namespace std;
int M, N;
int visit[100][100] = { 0, };
int dr[] = { 0,1,0,-1 };
int dc[] = { 1,0,-1,0 };
int main() {
	cin >> M >> N;
	int r = 0, c = 0, d = 0, cnt = 0;
	visit[r][c] = 1;
	while (true) {
		int nr = r + dr[d];
		int nc = c + dc[d];
		if (nr<0 || nc<0 || nr>M - 1 || nc>N - 1 || visit[nr][nc] == 1) {
			d = (d + 1) % 4;
			int nnr = r + dr[d];
			int nnc = c + dc[d];
			if (nnr<0 || nnc<0 || nnr>M - 1 || nnc>N - 1 || visit[nnr][nnc]) break;
			cnt++;
			continue;
		}
		visit[nr][nc] = 1;
		r = nr;
		c = nc;
	}
	cout << cnt;
	return 0;
}