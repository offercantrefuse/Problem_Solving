#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int loc[10];
int mass[10];
int n;

double bisection(int pos) {
	double mid, low = loc[pos], high = loc[pos + 1];

	for (int k = 0; k < 100; k++) {
		double leftforce = 0, rightforce = 0;

		mid = (high + low) / 2.0;
		for (int i = 0; i <= pos; i++) {
			double dx = mid - loc[i];
			leftforce += mass[i] / (dx*dx);
		}
		for (int i = pos + 1; i < n; i++) {
			double dx = loc[i] - mid;
			rightforce += mass[i] / (dx*dx);
		}
		if (leftforce > rightforce)
			low = mid;
		else
			high = mid;
	}
	return mid;
}

int main() {
	int tc;

	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> loc[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> mass[i];
		}
		cout << "#" << t << ' ';
		for (int i = 0; i < n - 1; i++) {
			printf("%.10f ", bisection(i));
		}
		cout << endl;
	}
	return 0;
}