#include <iostream>
using namespace std;
int N, M, arr[9] = { 0, };
bool visit[9];
void dfs(int idx, int aa) {
	if (idx == M) {
		for (int i = 0; i < aa; i++)
			cout << arr[i] << " ";
		cout << '\n';
		return;
	}
	for (int i = idx + 1; i <= N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			arr[aa] = i;
			dfs(idx + 1, aa + 1);
			visit[i] = false;
		}
	}
}
int main() {
	cin >> N >> M;
	dfs(0, 0);
	return 0;
}