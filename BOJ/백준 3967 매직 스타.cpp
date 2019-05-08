#include <iostream>
#include <vector>
using namespace std;
struct pos {
	int r, c;
	pos(int r, int c) :r(r), c(c) {}
	pos() {}
};
char map[5][9];
bool visit[12];
vector<pos> vec;
vector<char> result;
bool found = false;

bool check() {
	if (map[0][4] - 'A' + map[1][3] - 'A' + map[2][2] - 'A' + map[3][1] - 'A' != 22) return false;
	if (map[0][4] - 'A' + map[1][5] - 'A' + map[2][6] - 'A' + map[3][7] - 'A' != 22) return false;
	if (map[1][1] - 'A' + map[1][3] - 'A' + map[1][5] - 'A' + map[1][7] - 'A' != 22) return false;
	if (map[1][1] - 'A' + map[2][2] - 'A' + map[3][3] - 'A' + map[4][4] - 'A' != 22) return false;
	if (map[4][4] - 'A' + map[3][5] - 'A' + map[2][6] - 'A' + map[1][7] - 'A' != 22) return false;
	if (map[3][1] - 'A' + map[3][3] - 'A' + map[3][5] - 'A' + map[3][7] - 'A' != 22) return false;
	return true;
}

void dfs(int cnt) {
	if (cnt == vec.size()) {
		if (check()) {
			found = true;
			for (int i = 0; i < vec.size(); i++) {
				result.push_back(map[vec[i].r][vec[i].c]);
			}
		}
		return;
	}
	for (int i = 0; i < 12 && !found; i++) {
		if (!visit[i]) {
			visit[i] = true;
			map[vec[cnt].r][vec[cnt].c] = (char)(i + 'A');
			dfs(cnt + 1);
			map[vec[cnt].r][vec[cnt].c] = 'x';
			visit[i] = false;
		}
	}
}

int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'x') {  // ºóÄ­
				vec.push_back(pos(i, j));
			}
			else if (map[i][j] >= 'A' &&map[i][j] <= 'Z') {
				visit[map[i][j] - 'A'] = true;
			}
		}
	}
	dfs(0);
	int index = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			if (map[i][j] == 'x') {
				cout << result[index++];
			}
			else {
				cout << map[i][j];
			}
		}
		cout << '\n';
	}
	return 0;
}