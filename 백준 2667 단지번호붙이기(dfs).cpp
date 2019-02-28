#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, cnt = 0;
char map[25][25];
int dr[] = { 0,-1,0,1 };
int dc[] = { -1,0,1,0 };
int visited[25][25] = { 0, };
vector<int> answer;
bool flag = false;
void dfs(int r, int c) {
	visited[r][c] = 1;
	for (int i = 0; i < 4; i++) {
		int new_r = r + dr[i];
		int new_c = c + dc[i];
		if (new_r < 0 || new_c < 0 || new_r > n - 1 || new_c > n - 1) continue;
		if (map[new_r][new_c] == '1' && visited[new_r][new_c] == 0) {
			visited[new_r][new_c] = 1;
			cnt++;
			dfs(new_r, new_c);
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0 && map[i][j] =='1') {
				cnt = 1;
				dfs(i, j);
				answer.push_back(cnt);
			}
		}
	}
	sort(answer.begin(), answer.end());
	cout << answer.size() << '\n';
	for (int t : answer) cout << t << '\n';
	return 0;
}