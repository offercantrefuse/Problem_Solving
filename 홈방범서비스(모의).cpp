#include <iostream>
#define dist(a,b) ((a>b)? a-b:b-a)
using namespace std;
int N, M;
int map[20][20] = { 0, };
int ans;


int run_cost(int a) {
	int c;
	c = a * a + (a + 1)*(a + 1);
	return c;
}

int dfs(int cnt) {
	int maxi = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int sum = 0;
			for (int k = i - cnt; k <= i + cnt; k++) {
				int tmp = dist(i, k);
				for (int l = j - cnt + tmp; l <= j + cnt - tmp; l++) {
					if (k >= 0 && k <= N - 1 && l >= 0 && l <= N - 1) {
						if (map[k][l] == 1) {
							sum += M;
						}
					}
				}
				if (sum - run_cost(cnt) >= 0) { 
					maxi = (maxi<sum/M)? sum/M: maxi; 
				}
			}
		}
	}
	return maxi;
}


int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		ans = -1;

		for (int i = 0; i <= 2 * N - 2; i++) {
			ans = (ans<dfs(i))? dfs(i): ans;
		}

		cout << "#" << tc << ' ' << ans << endl;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				map[i][j] = 0;
			}
		}
	}
	return 0;
}