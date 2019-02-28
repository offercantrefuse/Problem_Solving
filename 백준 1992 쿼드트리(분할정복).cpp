#include <iostream>
using namespace std;
int n;
char map[64][64];

bool same(int l, int x, int y) {
	for (int i = x; i < x + l; i++) {
		for (int j = y; j < y + l; j++) {
			if (map[x][y] != map[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void solve(int l, int x, int y) {
	int m = l / 2;
	if (same(l, x, y)) {
		cout << map[x][y];
	}
	else {
		cout << '(';
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				solve(m, x + m * i, y + m * j);
			}
		}
		cout << ')';
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	solve(n, 0, 0);
	return 0;
}