#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
struct node {
	int a, b, cost;
	node(int a, int b, int cost) : a(a), b(b), cost(cost) {}
	node() {}
};

bool cmp(node a, node b) {
	return a.cost < b.cost;
};

int N, M, ans = 0;
int root[1001] = { 0, };
deque<node> vec;

int find(int x) {   // root 찾기
	if (root[x] == x) return x;
	return root[x] = find(root[x]);
}

void union_find(int x, int y) {   // 두개 합치기
	x = find(x);
	y = find(y);
	root[y] = x;
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		root[i] = i;
	}
	int tmpa, tmpb, tmpc;
	for (int i = 0; i < M; i++) {
		cin >> tmpa >> tmpb >> tmpc;
		vec.push_back(node(tmpa, tmpb, tmpc));
	}
	sort(vec.begin(), vec.end(), cmp);
	while (!vec.empty()) {
		node nd = vec.front();
		vec.pop_front();
		if (find(nd.a) == find(nd.b)) continue;
		union_find(nd.a, nd.b);
		ans += nd.cost;
	}
	cout << ans;
	return 0;
}