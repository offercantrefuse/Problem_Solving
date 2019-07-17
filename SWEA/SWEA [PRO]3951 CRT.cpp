#include <iostream>
using namespace std;

int T, N, b[10], n[10], ans;

bool check(int num) {
	for (int i = 0; i < N; i++) {
		if (num % n[i] != b[i])
			return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		int maxi = 0, idx = 0;
		for (int i = 0; i < N; i++) {
			cin >> b[i] >> n[i];
			if (maxi < n[i]) {
				maxi = n[i];
				idx = i;
			}
		}
		int k = 1;
		while (1) {
			int tmp = n[idx] * k + b[idx];
			if (check(tmp)) {
				ans = tmp;
				break;
			}
			k++;
		}
		cout << "#" << tc << ' ' << ans << '\n';
	}

	return 0;
}