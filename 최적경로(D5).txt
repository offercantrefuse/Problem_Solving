#include <iostream>
using namespace std;
int n;
int graph[12][12];
int memo[12][1 << 12];

struct node {
	int x;
	int y;
}node[15];

int dif(int a, int b) {
	return (a > b) ? a - b : b - a;
}

int dist(int m, int n) {
	return dif(node[m].x, node[n].x) + dif(node[m].y, node[n].y);
}

void make_graph() {
	for (int i = 0; i < n + 2; i++) {
		for (int j = 0; j < n + 2; j++) {
			if (i == j) graph[i][j] = 0;
			else {
				graph[i][j] = dist(i, j);
			}
		}
	}
}

int solve(int pos, int visited) {
	int& ret = memo[pos][visited];
	if (ret != -1) return ret;

	if (visited == (1 << (n + 2)) - 1 - 2)
		return ret = graph[pos][1];

	ret = 999999;
	for (int next = 2; next < n + 2; ++next) {
		if (!(visited&(1 << next)) && graph[pos][next]) {
			int tmp = graph[pos][next] + solve(next, visited | (1 << next));
			if (tmp < ret) ret = tmp;
		}
	}
	return ret;
}

int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n;
		for (int i = 0; i < n + 2; i++) {
			cin >> node[i].x >> node[i].y;
		}
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 12; j++) {
				graph[i][j] = 0;
			}
		}
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < (1<<12); j++) {
				memo[i][j] = -1;
			}
		}
		make_graph();
		cout << "#" << t << ' ' << solve(0, 1) << endl;
	}
	return 0;
}
