#include <iostream>
using namespace std;

int main() {
	int n, s, start = 0, end = 0, mini = 100001, sum = 0;
	int a[100000] = { 0, };
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	while (end <= n) {
		if (sum < s) {
			if (end == n) {
				if (mini == 100001) mini = 0;
				break;
			}
			sum += a[end];
			end++;
		}
		else if (sum >= s) {
			mini = mini > (end - start) ? end - start : mini;
			sum -= a[start];
			start++;
		}
	}
	cout << mini;
	return 0;
}