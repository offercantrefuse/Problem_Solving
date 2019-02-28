#include <iostream>
using namespace std;
int T, N, M;
int map[20][20] = { 0, };
inline int abs(int a) { return a > 0 ? a : -a; }
inline int price(int a) { return a * a + (a - 1)*(a - 1); }
inline int maxi(int a, int b) { return a > b ? a : b; }
int solve(int r, int c, int k) {
	int home = 0;
	for (int i = r - (k - 1); i <= r + (k - 1); i++) {
		for (int j = c - (k - 1) + abs(i - r); j <= c + (k - 1) - abs(i - r); j++) {
			if (i<0 || i>N - 1 || j<0 || j>N - 1) continue;
			if (map[i][j] == 1) home++;
		}
	}
	if (price(k) <= home*M) return home;
	else return 0;
}

int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> M;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> map[i][j];
		int ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 1; k <= 2 * N - 1; k++) {
					ans = maxi(solve(i, j, k), ans);
				}
			}
		}
		cout << "#" << tc << ' ' << ans << '\n';
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				map[i][j] = 0;
	}
	return 0;
}