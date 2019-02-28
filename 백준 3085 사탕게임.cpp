#include <iostream>
using namespace std;

int N, maxi = 1;
char map[50][50];
int dr[] = { 0,1 };  // 0: right, 1: down
int dc[] = { 1,0 };

void find_row(int r) { // r 행의 최대값
	char tmp = map[r][0];
	int cnt = 1;
	for (int i = 1; i < N; i++) {
		if (tmp == map[r][i]) {
			cnt++;
			maxi = maxi < cnt ? cnt : maxi;
		}
		else {
			tmp = map[r][i];
			cnt = 1;
		}
	}
}

void find_col(int c) { // c 열의 최대값
	char tmp = map[0][c];
	int cnt = 1;
	for (int i = 1; i < N; i++) {
		if (tmp == map[i][c]) {
			cnt++;
			maxi = maxi < cnt ? cnt : maxi;
		}
		else {
			tmp = map[i][c];
			cnt = 1;
		}
	}
}
void swap(int r1, int c1, int r2, int c2) {
	char tmp = map[r1][c1];
	map[r1][c1] = map[r2][c2];
	map[r2][c2] = tmp;
}

void solve(int r, int c) {
	for (int d = 0; d < 2; d++) {
		int nr = r + dr[d];
		int nc = c + dc[d];
		if (nr > N - 1 || nc > N - 1) continue;
		swap(r, c, nr, nc);
		find_row(r);
		find_row(nr);
		find_col(c);
		find_col(nc);
		swap(r, c, nr, nc);
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {  // 연속된 최대값 찾아놓기
		find_row(i);
		find_col(i);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			solve(i, j);
		}
	}
	cout << maxi;
	return 0;
}