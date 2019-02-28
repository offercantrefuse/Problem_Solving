#include <iostream>
using namespace std;
int n, k;
long long a[10000];
bool check(long long x) {
	int cnt = 0;
	for (int i = 0; i < k; i++) {
		cnt += a[i] / x;
	}
	return cnt >= n;
}
int main() {
	cin >> k >> n;
	long long maxi = 0;
	for (int i = 0; i < k; i++) {
		cin >> a[i];
		if (maxi < a[i]) {
			maxi = a[i];
		}
	}
	long long l = 1;
	long long r = maxi;
	long long ans = 0;
	while (l <= r) {
		long long mid = (l + r) / 2;
		if (check(mid)) {
			if (ans < mid) {
				ans = mid;
			}
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	cout << ans << '\n';
	return 0;
}