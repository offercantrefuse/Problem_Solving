#include <iostream>
#include <cmath>
using namespace std;
int n, k;
int a[500] = { 0, };

double find() {
	double ans = INFINITY;
	for (int t = k; t <= n; t++) {
		double cand = INFINITY;
		for (int i = 0; i <= n - t; i++) {
			double avg = 0.0;
			double sum = 0.0;
			double dev = 0.0;
			for (int j = 0; j < t; j++) {
				avg += a[i + j];
			}
			avg /= t;
			for (int j = 0; j < t; j++) {
				sum += (a[i + j] - avg)*(a[i + j] - avg);
			}
			dev = sqrt(sum / t);
			cand = (dev < cand) ? dev : cand;
		}
		ans = (cand < ans) ? cand : ans;
	}
	return ans;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout.precision(15);
	cout << find() << '\n';
	return 0;
}