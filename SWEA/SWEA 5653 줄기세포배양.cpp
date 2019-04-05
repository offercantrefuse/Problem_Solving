#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
	int r, c, s, age, l;  // s -> 0: 비활, 1: 활
	node(int r, int c, int s, int age, int l) : r(r), c(c), s(s), age(age), l(l) {}
	node() {}
};
int T, N, M, K, cnt, ans;
int map[352][352] = { 0, };
int dr[] = { -1,0,1,0 };
int dc[] = { 0,-1,0,1 };
queue<node> q;
vector<node> vec;

bool cmp(node a, node b) {
	return a.l > b.l;
}

void bfs() {
	while (!q.empty() && cnt < K) {
		int qSize = q.size();
		for (int t = 0; t < qSize; t++) {
			int rr = q.front().r;
			int cc = q.front().c;
			int ss = q.front().s;
			int aa = q.front().age;
			int ll = q.front().l;
			q.pop();
			if (ss == 0) {  // 비활
				if (aa == ll)
					q.push(node(rr, cc, 1, 1, ll));
				else {
					q.push(node(rr, cc, 0, aa + 1, ll));
				}
			}
			else {  // 활성
				if (aa == 1) {  // 첫 활성
					for (int d = 0; d < 4; d++) {
						int nr = rr + dr[d];
						int nc = cc + dc[d];
						if (map[nr][nc] == 0) {  // 빈 칸
							map[nr][nc] = ll;
							q.push(node(nr, nc, 0, 1, ll));
						}
					}
				}
				if (aa < ll) {
					q.push(node(rr, cc, 1, aa + 1, ll));
				}
			}
		}
		cnt++;
	}

}

int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> M >> K;
		for (int i = 0; i < 351; i++)
			memset(map[i], 0, sizeof(map[i]));
		for (int i = 150; i < 150 + N; i++) {
			for (int j = 150; j < 150 + M; j++) {
				cin >> map[i][j];
				if (map[i][j] != 0)
					vec.push_back(node(i, j, 0, 1, map[i][j]));
			}
		}
		sort(vec.begin(), vec.end(), cmp);
		for (node n : vec)
			q.push(n);
		vec.clear();
		cnt = 0;
		bfs();
		cout << '#' << tc << ' ' << q.size() << '\n';
		while (!q.empty()) q.pop();
	}
	return 0;
}
