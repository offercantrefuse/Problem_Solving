#include <iostream>
using namespace std;
bool flag = false;
int m, n;
char map[1000][1000];
int visited[1000][1000] = { 0, };
struct pos {
	int r, c;
	pos(int rr, int cc) {
		r = rr;
		c = cc;
	}
};
int dc[] = { 0,-1,0,1 };
int dr[] = { 1,0,-1,0 };

void dfs(pos p) {
	visited[p.r][p.c] = 1;
	if (p.r == m - 1) {
		flag = true;
		return;
	}
	if (flag) return;
	for (int i = 0; i < 4; i++) {
		int new_r = p.r + dr[i];
		int new_c = p.c + dc[i];
		if (new_r < 0 || new_c < 0 || new_r > m - 1 || new_c > n - 1) continue;
		if (map[new_r][new_c] == '0' && visited[new_r][new_c] == 0) {
			dfs(pos(new_r, new_c));
		}
	}
}
int main() {
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n;i++) {
		if( (!flag) && map[0][i]=='0') dfs(pos(0,i));
	}
	flag ? cout << "YES" : cout << "NO";
	return 0;
}