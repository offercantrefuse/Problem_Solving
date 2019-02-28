#include <iostream>
using namespace std;
int main() {
	int n, m,ans;
	cin >> n >> m;
	if (n == 1) {
		ans = 1;
	}
	else if (n == 2) {
		ans = (m > 7) ? 4 : (m+1)/2;
	}
	else {
		if (m < 7) {
			ans = (m > 4) ? 4 : m;
		}
		else {
			ans = m - 2;
		}
	}
	cout << ans << '\n';
	return 0;
}