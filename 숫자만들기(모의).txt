#include <iostream>
#include <stdio.h>
using namespace std;
#define INF 2e9

int op[4];
int num[13];
int MAX, MIN;
int N;

void dfs(int remain[4], int now, int n) {
	if (n == N) {
		MAX = now > MAX ? now : MAX;
		MIN = now < MIN ? now : MIN;
		
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (remain[i] > 0) {
			remain[i]--;
			if (i == 0) {
				dfs(remain, now + num[n], n + 1);
			}
			else if (i == 1) {
				dfs(remain, now - num[n], n + 1);
			}
			else if (i == 2) {
				dfs(remain, now * num[n], n + 1);
			}
			else if (i == 3) {
				dfs(remain, now / num[n], n + 1);
			}
			remain[i]++;
		}
	}
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		MAX = -INF;
		MIN = INF;
		for (int i = 0; i < 4; i++) {
			cin >> op[i];
		}
		for (int i = 0; i < N; i++) {
			cin >> num[i];
		}
		dfs(op, num[0], 1);
		
		cout << "#" << tc << ' ' << MAX - MIN << endl;
	}
	return 0;
}