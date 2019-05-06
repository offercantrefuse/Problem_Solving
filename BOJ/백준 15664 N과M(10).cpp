#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int N, M;
set<vector<int>> ss;
vector<int> arr;
int ans[8];

void dfs(int idx, int cnt) {
	if (cnt == M) {
		vector<int> vec;
		for (int i = 0; i < M; i++)
			vec.push_back(ans[i]);
		ss.insert(vec);
		return;
	}
	for (int i = idx; i < arr.size(); i++) {
		ans[cnt] = arr[i];
		dfs(i + 1, cnt + 1);
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}
	sort(arr.begin(), arr.end());
	dfs(0, 0);
	for (auto rs : ss) {
		for (int i = 0; i < rs.size(); i++)
			cout << rs[i] << ' ';
		cout << '\n';
	}
	return 0;
}