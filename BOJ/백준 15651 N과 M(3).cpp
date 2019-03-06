#include <iostream>
using namespace std;
int N, M, arr[9] = { 0, };
int visit[9] = { 0, };

void dfs(int aidx, int cnt) {
	if (cnt == M) {
		for (int i = 0; i < aidx; i++)
			cout << arr[i] << " ";
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++) {
		arr[aidx] = i;
		dfs(aidx + 1, cnt + 1);
	}
}

int main() {
	cin >> N >> M;
	dfs(0, 0);
	return 0;
}