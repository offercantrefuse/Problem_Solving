#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int N, S, J, K;
		cin >> N >> S >> J >> K;
		vector<int> rest(K);
		for (int i = 0; i < K; i++) {
			cin >> rest[i];
		}
		int now = S;
		int ans = 0;
		while (now <= N) {
			for (int i = 0; i < K; i++) {
				if (now == rest[i]) {
					ans++;
				}
			}
			now += J + 1;
		}
		cout << "#" << tc << ' ' << ans << '\n';
	}
	return 0;
}