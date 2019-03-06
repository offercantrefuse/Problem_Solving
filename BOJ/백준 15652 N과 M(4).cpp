#include <iostream>
using namespace std;
int N, M, arr[9] = { 0, };
int visit[9] = { 0, };

void dfs(int num, int aidx, int cnt) {
	if (cnt == M) {
		for (int i = 0; i < aidx; i++)
			cout << arr[i] << " ";
		cout << '\n';
		return;
	}
	for (int i = num; i <= N; i++) {
		arr[aidx] = i;
		dfs(i, aidx + 1, cnt + 1);
	}
}

int main() {
	cin >> N >> M;
	dfs(1, 0, 0);
	return 0;
}