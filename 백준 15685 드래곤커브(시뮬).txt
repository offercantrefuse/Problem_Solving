#include <iostream>
using namespace std;
int N;
int map[101][101] = { 0, };
struct dg {
	int x, y, d, g;
	dg(int xx, int yy, int dd, int gg) {
		x = xx;
		y = yy;
		d = dd;
		g = gg;
	}
	dg() {};
};
dg curve[20];
int st[2048] = { 0, };
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };

void solve(dg c) {
	int top = 0, nx = c.x, ny = c.y;
	map[c.y][c.x] = 1;
	st[top] = c.d;
	map[c.y + dy[c.d]][c.x + dx[c.d]] = 1;
	nx += dx[st[top]];
	ny += dy[st[top]];
	for (int i = 1; i <= c.g; i++) {
		int tmpd = top;
		for (int j = 0; j < (1 << (i - 1)); j++) {
			nx += dx[(st[tmpd - j]+1) %4];
			ny += dy[(st[tmpd - j]+1) %4];
			map[ny][nx] = 1;
			st[++top] = (st[tmpd - j] + 1) % 4;
		}
	}
}
void paint() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2048; j++) st[j] = 0;
		solve(curve[i]);
	}
}

int count() {
	int cnt = 0;
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (map[i][j] == 1 && map[i + 1][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j + 1] == 1) {
				cnt++;
			}
		}
	}
	return cnt;
}
int main() {
	cin >> N;
	int x, y, d, g;
	int idx = 0;
	for (int i = 0; i < N; i++) {
		cin >> x >> y >> d >> g;
		curve[idx] = dg(x, y, d, g);
		idx++;
	}
	paint();
	cout << count();
	return 0;
}