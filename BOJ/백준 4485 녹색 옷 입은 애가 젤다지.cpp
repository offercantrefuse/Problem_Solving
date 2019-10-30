#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct node {
	int r, c, k;
	node(int r, int c, int k) :r(r), c(c), k(k) {}
	node() {}
};

struct cmp {
	bool operator()(node a, node b) {
		return a.k > b.k;
	}
};

const int INF = 2000000000;
int N, tc = 1;
int map[125][125] = { 0, };
int dist[125][125] = { 0, };
int dr[] = { -1,0,1,0 };
int dc[] = { 0,-1,0,1 };

priority_queue<node, vector<node>, cmp> q;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (cin >> N) {
		if (N == 0) break;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				dist[i][j] = INF;
			}
		}
		q.push(node(0, 0, map[0][0]));
		dist[0][0] = map[0][0];

		while (!q.empty()) {
			node nd = q.top();
			q.pop();
			int rr = nd.r;
			int cc = nd.c;
			int kk = nd.k;
			for (int d = 0; d < 4; d++) {
				int nr = rr + dr[d];
				int nc = cc + dc[d];
				if (nr<0 || nc<0 || nr>N - 1 || nc>N - 1) continue;
				if (dist[nr][nc] <= dist[rr][cc] + map[nr][nc]) continue;
				dist[nr][nc] = dist[rr][cc] + map[nr][nc];
				q.push(node(nr, nc, dist[nr][nc]));
			}
		}

		cout << "Problem " << tc << ": " << dist[N - 1][N - 1] << '\n';
		tc++;
	}
	return 0;
}