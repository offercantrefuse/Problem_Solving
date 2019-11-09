#include <iostream>
#include <algorithm>
using namespace std;
int N, K;
int W[101], V[101], dp[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> W[i] >> V[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = K; j >= 0; j--) {
			if (j - W[i] >= 0)
				dp[j] = max(dp[j], dp[j - W[i]] + V[i]);
		}
	}
	cout << dp[K];
	return 0;
}