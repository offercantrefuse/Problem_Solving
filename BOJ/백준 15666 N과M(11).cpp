#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int N, M;
set<int> tmp_set;
vector<int> arr;
int ans[8];

void dfs(int idx, int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < arr.size(); i++) {
		ans[idx] = arr[i];
		dfs(idx + 1, cnt + 1);
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		tmp_set.insert(tmp);
	}
	for (auto tt : tmp_set)
		arr.push_back(tt);
	sort(arr.begin(), arr.end());
	dfs(0, 0);
	return 0;
}