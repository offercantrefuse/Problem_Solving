#include <iostream>
using namespace std;

int main() {
	int n, kim, lim, round = 0;
	cin >> n >> kim >> lim;
	while (n != 0) {
		round++;
		kim = (kim + 1) / 2;
		lim = (lim + 1) / 2;
		if (kim == lim) break;
		n /= 2;
	}
	cout << round;
	return 0;
}