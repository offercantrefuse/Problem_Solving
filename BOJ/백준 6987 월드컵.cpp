#include <iostream>
using namespace std;

int play[6][3] = { 0, };
bool flag;
int comb[15][2];
int ans[4] = { 0, };

void combination(int a, int b) {
	int cnt = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = i + 1; j < 6; j++) {
			comb[cnt][0] = i;
			comb[cnt][1] = j;
			cnt++;
		}
	}
}

void dfs(int idx) {
	if (idx == 15) {
		flag = true;
		return;
	}
	if (flag)
		return;
	if (play[comb[idx][0]][0] > 0 && play[comb[idx][1]][2] > 0) {
		play[comb[idx][0]][0]--;
		play[comb[idx][1]][2]--;
		dfs(idx + 1);
		play[comb[idx][0]][0]++;
		play[comb[idx][1]][2]++;
	}
	if (flag)
		return;
	if (play[comb[idx][0]][1] > 0 && play[comb[idx][1]][1] > 0) {
		play[comb[idx][0]][1]--;
		play[comb[idx][1]][1]--;
		dfs(idx + 1);
		play[comb[idx][0]][1]++;
		play[comb[idx][1]][1]++;
	}
	if (flag)
		return;
	if (play[comb[idx][0]][2] > 0 && play[comb[idx][1]][0] > 0) {
		play[comb[idx][0]][2]--;
		play[comb[idx][1]][0]--;
		dfs(idx + 1);
		play[comb[idx][0]][2]++;
		play[comb[idx][1]][0]++;
	}
}

int main() {
	combination(0, 0);
	for (int tc = 1; tc <= 4; tc++) {
		for (int i = 0; i < 6; i++) {
			cin >> play[i][0] >> play[i][1] >> play[i][2];
		}
		flag = false;
		bool overFive = false;
		for (int i = 0; i < 6; i++) {
			if (play[i][0] + play[i][1] + play[i][2] != 5) {
				overFive = true;
				break;
			}
		}
		if (!overFive) dfs(0);
		if (flag && !overFive) ans[tc - 1] = 1;
	}
	cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << ' ' << ans[3];
}