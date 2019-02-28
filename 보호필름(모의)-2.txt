#include <iostream>
using namespace std;
int T, D, W, K;
int film[13][20] = { 0, };
int tmp[13][20] = { 0, };
int ans;
int change[13] = { 0, };  // 0 : A , 1: B , 2: º¯È­x

void init_tmp() {
	for (int i = 0; i < D; i++) {
		for (int j = 0; j < W; j++) {
			tmp[i][j] = film[i][j];
		}
	}
}

void copy() {
	for (int i = 0; i < D; i++) {
		if (change[i] == 0) {
			for (int j = 0; j < W; j++)
				tmp[i][j] = 0;
		}
		else if (change[i] == 1) {
			for (int j = 0; j < W; j++)
				tmp[i][j] = 1;
		}
	}
}

bool col_valid(int col) {
	int now = tmp[0][col], cnt = 1;
	for (int i = 1; i < D; i++) {
		if (now == tmp[i][col]) {
			cnt++;
			if (cnt == K) return true;
		}
		else {
			now = tmp[i][col];
			cnt = 1;
		}
	}
	return false;
}

bool check() {
	for (int j = 0; j < W; j++) {
		if (!col_valid(j)) return false;
	}
	return true;
}


void dfs(int idx, int chg) {
	if (ans <= chg) return;
	if (idx == D) {
		init_tmp();
		copy();
		if (check()) {
			ans = ans > chg ? chg : ans;
			return;
		}
		else return;
	}
	for (int i = 2; i >= 0; i--) {
		change[idx] = i;
		if (i == 0) {
			if (chg >= K) continue;
			dfs(idx + 1, chg + 1);
		}
		else if (i == 1) {
			if (chg >= K) continue;
			dfs(idx + 1, chg + 1);
		}
		else dfs(idx + 1, chg);
	}
}


int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> D >> W >> K;
		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				cin >> film[i][j];
				tmp[i][j] = film[i][j];
			}
		}
		ans = 2000000000;
		if (K == 1) ans = 0;
		else dfs(0, 0);

		cout << "#" << tc << ' ' << ans << '\n';
		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				film[i][j] = 0;
				tmp[i][j] = 0;
			}
		}
	}
	return 0;
}