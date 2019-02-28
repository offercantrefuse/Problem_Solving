#include <iostream>
using namespace std;
int n;
int a[500000];
int b[500000];
long long solve(int start, int end) {
	if (start == end)
		return 0;
	int mid = (start + end) / 2;
	long long ans = solve(start, mid) + solve(mid + 1, end);
	int i = start;
	int j = mid + 1;
	int k = 0;
	while (i <= mid || j <= end) {
		if (i <= mid && (j > end || a[i] <= a[j])){
			b[k++] = a[i++];
		}
		else {
			ans += (long long) mid - i + 1;
			b[k++] = a[j++];
		}
	}
	for (int t = start; t <= end; t++) {
		a[t] = b[t - start];
	}
	return ans;
}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << solve(0, n - 1) << '\n';
	return 0;
}