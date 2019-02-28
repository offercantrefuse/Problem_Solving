#include <iostream>
using namespace std;
int a[10][10] = { 0, };
int n;

bool check(int r, int c) {
	bool water = false, mount = false, land = false;
	for (int i = -1; i <= 1; i++) {
		if ((r + i) < 0 || (r + i) >= n) continue;
		for (int j = -1; j <= 1; j++) {
			if ((c + j) < 0 || (c + j) >= n) continue;
			if (a[r + i][c + j] == 0)
				return false;
			if (a[r + i][c + j] == 1)
				water = true;
			if (a[r + i][c + j] == 2)
				mount = true;
			if (a[r + i][c + j] == 3)
				land = true;
		}
	}
	if (water && mount && land) return true;
	else return false;
}

int main() {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (check(i, j)) {
					ans++;
				}
			}
		}
		cout << "#" << tc << ' ' << ans << '\n';
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				a[i][j] = -1;
			}
		}
	}
	return 0;
}