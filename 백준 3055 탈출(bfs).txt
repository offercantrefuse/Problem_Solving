#include <iostream>
#include <queue>
using namespace std;
int R, C;
int dr[] = { 0,-1,0,1 };
int dc[] = { 1,0,-1,0 };
char map[50][50];
struct pos {
	int r, c;
	pos(int rr, int cc) {
		r = rr;
		c = cc;
	}
	pos() {}
};
queue<pos> hodge, water;
bool found = false;

void water_move() {
	int size = water.size();
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 4; j++) {
			int nr = water.front().r + dr[j];
			int nc = water.front().c + dc[j];
			if (nr<0 || nc<0 || nr>R - 1 || nc>C - 1) continue;
			if (map[nr][nc] == '.' || map[nr][nc] == 'S') {
				map[nr][nc] = '*';
				water.push(pos(nr, nc));
			}
		}
		water.pop();
	}
}
void hodge_move() {
	int size = hodge.size();
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 4; j++) {
			int nr = hodge.front().r + dr[j];
			int nc = hodge.front().c + dc[j];
			if (nr<0 || nc<0 || nr>R - 1 || nc>C - 1) continue;
			if (map[nr][nc] == '.') {
				map[nr][nc] = 'S';
				hodge.push(pos(nr, nc));
			}
			else if (map[nr][nc] == 'D') {
				found = true;
				return;
			}
		}
		hodge.pop();
	}
}

int main() {
	int time = 0;
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == '*') water.push(pos(i, j));
			else if (map[i][j] == 'S') hodge.push(pos(i, j));
		}
	}
	while (1) {
		if (found || hodge.size() == 0) break;
		water_move();
		hodge_move();
		time++;
	}
	if (found) cout << time;
	else cout << "KAKTUS";
	return 0;
}