#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct node {
	int idx, cost;
	node(int idx, int cost) : idx(idx), cost(cost) {}
	node() {}
};

struct cmp {
	bool operator()(node a, node b) {
		return a.cost > b.cost;
	}
};

priority_queue<node, vector<node>, cmp> pq;
const int MAX_NUM = 1000001;
int N, M, cnt = 0;
long ans = 0;
vector<vector<pair<int, int>>> adj(10001);
bool visit[10001];
int dist[10001];

int main() {
	cin >> N >> M;
	int tmpa, tmpb, tmpc;
	for (int i = 1; i <= N; i++) dist[i] = MAX_NUM;
	for (int i = 0; i < M; i++) {
		cin >> tmpa >> tmpb >> tmpc;
		adj[tmpa].push_back(make_pair(tmpb, tmpc));
		adj[tmpb].push_back(make_pair(tmpa, tmpc));
	}
	pq.push(node(tmpa, 0));
	dist[tmpa] = 0;
	while (!pq.empty() && cnt <= N) {
		node nd = pq.top();
		pq.pop();
		if (visit[nd.idx]) continue;
		visit[nd.idx] = true;
		cnt++;
		for (auto tmp : adj[nd.idx]) {
			if (!visit[tmp.first]) {
				pq.push(node(tmp.first, tmp.second));
				if (dist[tmp.first] > tmp.second) dist[tmp.first] = tmp.second;
			}
		}
	}
	long long ans = 0;
	for (int i = 1; i <= N; i++) ans += dist[i];
	cout << ans;
	return 0;
}