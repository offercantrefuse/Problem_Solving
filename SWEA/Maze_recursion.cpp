#include <iostream>

using namespace std;

int testcase;
int w, h;

int maze[100][100] = { 0, };
int dy[] = { -1,0,0,1 };
int dx[] = { 0,-1,1,0 };

int good;



void dfs(int m, int n) {
	maze[m][n] = 1;

	for (int i = 0; i < 4; i++) {
		if (maze[m + dy[i]][n + dx[i]] == 0) {
			dfs(m + dy[i], n + dx[i]);
		}
		else if (maze[m + dy[i]][n + dx[i]] == 3) {
			good = 1;
			break;
		}
	}
}

int main() {


	cin >> testcase;

	for (int t = 0; t < testcase; t++) {
		cout << "가로, 세로입력: ";
		cin >> w >> h;

		good = 0;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> maze[i][j];
			}
		}

		dfs(1, 1);

		cout << good << endl;
	}

	return 0;
}