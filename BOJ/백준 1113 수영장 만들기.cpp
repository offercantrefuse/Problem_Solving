#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
struct node {
	int r, c;
	node(int r, int c) : r(r), c(c) {}
	node() {}
};

int n, m, wall, ans, now;
int map[50][50];
bool visit[50][50];
int dr[] = { -1,0,1,0 };
int dc[] = { 0,-1,0,1 };
queue<node> q;
queue<node> graph;
bool flag;

void bfs() {  // 주변 그래프
	while (!q.empty() && !flag) {
		int rr = q.front().r;
		int cc = q.front().c;
		visit[rr][cc] = true;
		q.pop();
		for (int d = 0; d < 4; d++) {
			int nr = rr + dr[d];
			int nc = cc + dc[d];
			if (nr<0 || nc<0 || nr>n - 1 || nc>m - 1 || map[nr][nc] == 0) {
				flag = true;
				break;
			}
			if (map[nr][nc] > now && map[nr][nc] < wall) {  // 최소 벽 갱신
				wall = map[nr][nc];
			}
			if (!visit[nr][nc] && map[nr][nc] <= now) {  // 작거나 같은 곳 graph에 넣기
				visit[nr][nc] = true;
				graph.push(node(nr, nc));
				q.push(node(nr, nc));
			}
		}
	}
	while (!flag && !graph.empty()) {
		int rr = graph.front().r;
		int cc = graph.front().c;
		graph.pop();
		ans += wall - map[rr][cc];
		map[rr][cc] = wall;
	}

}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			map[i][j] = c - '0';
		}
	}
	ans = 0;
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < m - 1; j++) {
			while (!q.empty()) q.pop();
			while (!graph.empty()) graph.pop();
			now = map[i][j];
			wall = 9;
			flag = false;
			memset(visit, false, sizeof(visit));
			q.push(node(i, j));
			graph.push(node(i, j));
			bfs();
		}
	}
	cout << ans;
	return 0;
}