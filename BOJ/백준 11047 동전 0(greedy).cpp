#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k, ans = 0;
	vector<int> a;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	for (int i = n - 1; i >= 0; i--) {
		while (k >= a[i]) {
			ans++;
			k -= a[i];
		}
	}
	cout << ans << '\n';
}