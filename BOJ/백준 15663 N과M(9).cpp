#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int N, M, arr[8], ans[8];
bool visit[8];
set<vector<int>> ss;

void dfs(int cnt) {
	if (cnt == M) {
		vector<int> vec;
		for (int i = 0; i < M; i++)
			vec.push_back(ans[i]);
		ss.insert(vec);
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			ans[cnt] = arr[i];
			dfs(cnt + 1);
			visit[i] = false;
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	dfs(0);
	for (auto rs : ss) {
		for (auto tmp : rs)
			cout << tmp << ' ';
		cout << '\n';
	}
	return 0;
}