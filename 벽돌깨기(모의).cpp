#include <iostream>
using namespace std;
int arr[15][12] = { 0, };
int n, h, w;
int ans;
int map[15][12] = { 0, };

void init() {
	ans = 2000000000;
}

void block_init() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			map[i][j] = arr[i][j];
		}
	}
}

int bomb_1() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (map[i][j] > 10) {
				int d = map[i][j] - 10;
				map[i][j] = 0;

				int sx = j - d + 1;
				int ex = j + d - 1;
				if (sx < 0) sx = 0;
				if (ex >= w) ex = w - 1;

				int flag = 0;

				for (int x = sx; x <= ex; x++) {
					if (map[i][x] == 1) map[i][x] = 0;
					else if (map[i][x] > 1 && map[i][x] < 10) {
						map[i][x] += 10;
						flag = 1;
					}
				}

				int sy = i - d + 1;
				int ey = i + d - 1;
				if (sy < 0) sy = 0;
				if (ey >= h) ey = h - 1;
				for (int y = sy; y <= ey; y++) {
					if (map[y][j] == 1) map[y][j] = 0;
					else if (map[y][j] > 1 && map[y][j] < 10) {
						map[y][j] += 10;
						flag = 1;
					}
				}
				if (flag == 1) return 1;
			}
		}
	}
	return 0;
}

void bomb(int x) {
	for (int y = 0; y < h; y++) {
		if (map[y][x] == 1) {
			map[y][x] = 0;
			return;
		}
		else if (map[y][x] > 1) {
			map[y][x] += 10;
			break;
		}
	}
	int flag = 1;
	while (flag) flag = bomb_1();
}

void down() {
	for (int j = 0; j < w; j++) {
		for (int i = h - 1; i >= 0; i--) {
			if (map[i][j] == 0) {
				for (int y = i - 1; y >= 0; y--) {
					if (map[y][j] != 0) {
						map[i][j] = map[y][j];
						map[y][j] = 0;
						break;
					}
				}
			}
		}
	}
}

void block_check() {
	int cnt = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (map[i][j] > 0) cnt++;
		}
	}
	if (ans > cnt) ans = cnt;
}

void solve() {
	int b[4];
	for (b[0] = 0; b[0] < w; b[0]++) {
		for (b[1] = 0; b[1] < w; b[1]++) {
			for (b[2] = 0; b[2] < w; b[2]++) {
				for (b[3] = 0; b[3] < w; b[3]++) {
					block_init();
					for (int i = 0; i < n; i++) {
						bomb(b[i]);
						down();
					}
					block_check();
					if (ans == 0) return;
					if (n < 4) break;
				}
				if (n < 3) break;
			}
			if (n < 2) break;
		}
	}
}
int main() {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n >> w >> h;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> arr[i][j];
			}
		}
		init();
		solve();
		cout << "#" << tc << ' ' << ans << '\n';
		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < 12; j++) {
				arr[i][j] = 0;
			}
		}
	}

	return 0;
}