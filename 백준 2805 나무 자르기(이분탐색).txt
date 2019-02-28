#include <iostream>
using namespace std;
int n, m;
long long a[1000000];
bool check(long long x) {
	long long cnt = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > x) {
			cnt += a[i] - x;
		}
	}
	return cnt >= m;
}
int main() {
	cin >> n >> m;
	long long maxi = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (maxi < a[i])
			maxi = a[i];
	}
	long long l = 0;
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
