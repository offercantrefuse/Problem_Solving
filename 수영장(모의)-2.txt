#include <iostream>
using namespace std;
int T;
int price[4] = { 0, };
int plan[13] = { 0, };
int ans;

void dfs(int idx, int cost) {
	if (idx > 12) {
		ans = ans > cost ? cost : ans;
		return;
	}
	if (plan[idx] == 0) {
		dfs(idx + 1, cost);
	}
	else {
		dfs(idx + 1, cost + plan[idx] * price[0]);
		dfs(idx + 1, cost + price[1]);
		dfs(idx + 3, cost + price[2]);
		dfs(idx + 12, cost + price[3]);
	}
}

int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		for (int i = 0; i < 4; i++) cin >> price[i];
		for (int i = 1; i <= 12; i++) cin >> plan[i];
		ans = 2e9;
		dfs(1, 0);
		cout << "#" << tc << ' ' << ans << '\n';
	}
	return 0;
}