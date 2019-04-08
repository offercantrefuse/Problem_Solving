#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct card {
	int num, color;
	card(int num, int color) : num(num), color(color) {}
	card() {}
};
int T;
card arr[9];
int nums[10];
int cnt[3];

bool cmp(card a, card b) {
	if (a.color == b.color)
		return a.num < b.num;
	return a.color < b.color;
}

void solve(int from, int to) {
	for (int i = 1; i <= 9; i++) {
		if (nums[i] >= 3) {
			nums[i] -= 3;
		}
	}
	for (int i = 1; i <= 7; i++) {
		if (nums[i] >= 1) {
			int tmp = nums[i];
			nums[i] -= tmp;
			nums[i + 1] -= tmp;
			nums[i + 2] -= tmp;
		}
	}
}

bool check() {
	for (int i = 1; i <= 9; i++) {
		if (nums[i] != 0) return false;
	}
	return true;
}

int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		bool can_win = true;
		memset(cnt, 0, sizeof(cnt));
		memset(nums, 0, sizeof(nums));
		for (int i = 0; i < 9; i++) {
			char ch;
			cin >> ch;
			arr[i].num = ch - '0';
		}
		for (int i = 0; i < 9; i++) {
			char ch;
			cin >> ch;
			if (ch == 'R') {
				arr[i].color = 0;
				cnt[0]++;
			}
			else if (ch == 'G') {
				arr[i].color = 1;
				cnt[1]++;
			}
			else {
				arr[i].color = 2;
				cnt[2]++;
			}
		}
		if (cnt[0] % 3 != 0 || cnt[1] % 3 != 0 || cnt[2] % 3 != 0)
			can_win = false;
		if (can_win) {
			sort(arr, arr + 9, cmp);
			for (int i = 0; i < cnt[0]; i++) {
				nums[arr[i].num]++;
			}
			solve(0, cnt[0]);
			if (!check()) can_win = false;
			for (int i = cnt[0]; i < cnt[0] + cnt[1] && can_win; i++) {
				nums[arr[i].num]++;
			}
			solve(cnt[0], cnt[0] + cnt[1]);
			if (!check()) can_win = false;
			for (int i = cnt[0] + cnt[1]; i < 9 && can_win; i++) {
				nums[arr[i].num]++;
			}
			solve(cnt[0] + cnt[1], 9);
			if (!check()) can_win = false;
		}
		if (can_win) cout << '#' << tc << ' ' << "Win\n";
		else  cout << '#' << tc << ' ' << "Continue\n";
	}
	return 0;
}