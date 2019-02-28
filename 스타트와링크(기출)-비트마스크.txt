#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	int s[20][20];
	int ans = 1000000000;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> s[i][j];
		}
	}
	for (int i = 0; i < (1<<N); i++) {
		vector<int> first, second;
		for (int j = 0; j < N; j++) {
			if (i&(1 << j))
				first.push_back(j);
			else
				second.push_back(j);
		}
		if (first.size() != N / 2) continue;
		int t1 = 0, t2 = 0;
		for (int k = 0; k < N/2; k++) {
			for (int t = 0; t < N/2; t++) {
				if (k == t) continue;
				t1 += s[first[k]][first[t]];
				t2 += s[second[k]][second[t]];
			}
		}
		ans = (ans > abs(t1 - t2)) ? abs(t1 - t2) : ans;	
	}
	cout << ans << '\n';

	return 0;
}