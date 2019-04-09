#include <iostream>
using namespace std;
int map[10][10], arr[6], ans;
bool found;

bool check(int r, int c, int size) {
	if (r + size - 1 >= 10 || c + size - 1 >= 10) return false;
	for (int i = r; i < r + size; i++) {
		for (int j = c; j < c + size; j++) {
			if (map[i][j] == 0) return false;
		}
	}
	return true;
}

void color(int r, int c, int size) {
	for (int i = r; i < r + size; i++) {
		for (int j = c; j < c + size; j++) {
			map[i][j] = 0;
		}
	}
}

void uncolor(int r, int c, int size) {
	for (int i = r; i < r + size; i++) {
		for (int j = c; j < c + size; j++) {
			map[i][j] = 1;
		}
	}
}

void dfs(int cnt) {
	int sr = -1, sc = -1;
	for (int i = 0; i < 10 && sr == -1; i++) {
		for (int j = 0; j < 10 && sr == -1; j++) {
			if (map[i][j] == 1) {
				sr = i;
				sc = j;
				break;
			}
		}
	}

	if (sr == -1 && sc == -1) {  // Á¾·á
		found = true;
		ans = ans > cnt ? cnt : ans;
		return;
	}

	for (int k = 1; k <= 5; k++) {
		if (arr[k] > 0) {
			if (check(sr, sc, k)) {
				arr[k]--;
				color(sr, sc, k);
				dfs(cnt + 1);
				uncolor(sr, sc, k);
				arr[k]++;
			}
			else {
				continue;
			}
		}
	}
}

int main() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 1; i <= 5; i++)
		arr[i] = 5;
	ans = 999;
	found = false;
	dfs(0);
	if (!found) cout << "-1" << '\n';
	else {
		if (ans == 999) cout << "0\n";
		else cout << ans << '\n';
	}
	return 0;
}