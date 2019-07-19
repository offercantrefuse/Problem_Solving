#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int cnt[32001];
vector<vector<int>> vec;
vector<int> ans;
queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	// int cnt[N+1];
	// for (int i = 0; i <= N; i++) cnt[i] = 0;
	vec.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		cnt[b]++;
		vec[a].push_back(b);
	}
	for (int i = 1; i <= N; i++) {
		if (cnt[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int ff = q.front();
		q.pop();
		ans.push_back(ff);
		for (int i = 0; i < vec[ff].size(); i++) {
			if (cnt[vec[ff][i]] > 0) {
				cnt[vec[ff][i]]--;
				if (cnt[vec[ff][i]] == 0)
					q.push(vec[ff][i]);
			}
		}
	}
	for (int tmp : ans)
		cout << tmp << ' ';
	return 0;
}