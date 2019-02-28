#include <iostream>
using namespace std;
int visit[29][29] = { 0, };
int N;
double east, west, south, north;
double sum = 0.0;
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
double go_prob[4];

void dfs(int idx, int r, int c, double prob) {
	if (visit[r][c] == 1) return;
	visit[r][c] = 1;
	if (idx == N) {
		sum += prob;
		return;
	}
	for (int d = 0; d < 4; d++) {
		int nr = r + dir[d][0];
		int nc = c + dir[d][1];
		if (visit[nr][nc] == 0) {
			dfs(idx + 1, nr, nc, prob*go_prob[d]);
			visit[nr][nc] = 0;
		}
		else continue;
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < 4; i++) {
		cin >> go_prob[i];
		go_prob[i] /= 100;
	}
	dfs(0, 14, 14, 1.0);
	cout.precision(11);
	cout << sum;
	return 0;
}