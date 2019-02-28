#include <iostream>
using namespace std;

void solve(int n, int x, int y) {
	if (n == 0) return;
	solve(n - 1, x, 6 - x - y);
	cout << x << ' ' << y << '\n';
	solve(n - 1, 6 - x - y, y);
}

int main() {
	int m;
	cin >> m;
	cout << (1 << m) - 1 << '\n';
	solve(m, 1, 3);
	return 0;
}