#include <iostream>
using namespace std;
int num0[40] = { 0, }, num1[40] = { 0, };
int find_zero(int n) {
	num0[0] = 1;
	num0[1] = 0;
	for (int i = 2; i <= n; i++) {
		num0[i] = num0[i - 1] + num0[i - 2];
	}
	return num0[n];
}
int find_one(int n) {
	num1[0] = 0;
	num1[1] = 1;
	for (int i = 2; i <= n; i++) {
		num1[i] = num1[i - 1] + num1[i - 2];
	}
	return num1[n];
}
int main() {
	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << find_zero(n) << ' ' << find_one(n) << '\n';
		for (int i = 0; i < n; i++) {
			num0[i] = 0;
			num1[i] = 0;
		}
	}
	return 0;
}