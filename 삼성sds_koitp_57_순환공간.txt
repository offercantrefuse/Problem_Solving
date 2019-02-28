#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int n, m, r1, c1, r2, c2;
		cin >> n >> m >> r1 >> c1 >> r2 >> c2;
		int big_r, big_c, small_r, small_c;
		if (r1 > r2) {
			big_r = r1, small_r = r2;
		}
		else {
			big_r = r2, small_r = r1;
		}
		if (c1 > c2) {
			big_c = c1, small_c = c2;
		}
		else{
			big_c = c2, small_c = c1;
		}
		int row, col;
		col = (big_c - small_c > small_c + m - big_c) ? small_c + m - big_c : big_c - small_c;
		row = (big_r - small_r > small_r + n - big_r) ? small_r + n - big_r : big_r - small_r;
		int ans = col + row;

		cout << "#" << tc << ' ' << ans << '\n';
	}
	return 0;
}