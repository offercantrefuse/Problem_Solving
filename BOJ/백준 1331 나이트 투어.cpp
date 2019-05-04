#include <iostream>
using namespace std;

bool flag = true;
bool visit[7][7];

bool invalid(int r, int c, int nr, int nc) {
	if ((r == nr + 2 && c == nc - 1) || (r == nr + 2 && c == nc + 1) || (r == nr + 1 && c == nc + 2) || (r == nr + 1 && c == nc - 2) || (r == nr - 1 && c == nc - 2) || (r == nr - 1 && c == nc + 2) || (r == nr - 2 && c == nc - 1) || (r == nr - 2 && c == nc + 1)) {
		return false;
	}
	return true;
}

int main() {
	char c1, c2;
	cin >> c1 >> c2;
	int now_c = c1 - 'A';
	int now_r = c2 - '1';
	int sc = now_c, sr = now_r;
	visit[now_r][now_c] = true;
	int cnt = 1;
	for (int i = 0; i < 35; i++) {
		cin >> c1 >> c2;
		int col = c1 - 'A';
		int row = c2 - '1';
		cnt++;
		if (visit[row][col] || invalid(row, col, now_r, now_c)) {
			flag = false;
			break;
		}
		now_c = col;
		now_r = row;
		visit[now_r][now_c] = true;
	}
	if (!flag || cnt != 36) cout << "Invalid\n";
	else {
		if (invalid(sr, sc, now_r, now_c)) cout << "Invalid\n";
		else cout << "Valid\n";
	}
	return 0;
}