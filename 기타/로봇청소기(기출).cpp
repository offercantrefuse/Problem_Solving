#include <iostream>
using namespace std;
int map[50][50];
int clean;
int search_num;

int search(int m, int n, int dir) {
	if (map[m][n] == 0) {
		map[m][n] = 2;
		clean++;
	}
	switch (dir) {
	case 0:
		if (map[m][n - 1] == 0) {
			dir = (dir + 3) % 4;
			search_num = 0;
			search(m, n - 1, dir);
		}
		else {
			if (search_num != 4) {
				dir = (dir + 3) % 4;
				search_num++;
				search(m, n, dir);
			}
			else if (map[m + 1][n] == 2) {
				search_num = 0;
				search(m + 1, n, dir);
			}
			else if (map[m + 1][n] == 1) {
				search_num = 0;
				return clean;
			}
		}
		break;
	case 1:
		if (map[m - 1][n] == 0) {
			dir = (dir + 3) % 4;
			search_num = 0;
			search(m - 1, n, dir);
		}
		else {
			if (search_num != 4) {
				dir = (dir + 3) % 4;
				search_num++;
				search(m, n, dir);
			}
			else if (map[m][n - 1] == 2) {
				search_num = 0;
				search(m, n - 1, dir);
			}
			else if (map[m][n - 1] == 1) {
				search_num = 0;
				return clean;
			}
		}
		break;
	case 2:
		if (map[m][n + 1] == 0) {
			dir = (dir + 3) % 4;
			search_num = 0;
			search(m, n + 1, dir);
		}
		else {
			if (search_num != 4) {
				dir = (dir + 3) % 4;
				search_num++;
				search(m, n, dir);
			}
			else if (map[m - 1][n] == 2) {
				search_num = 0;
				search(m - 1, n, dir);
			}
			else if (map[m - 1][n] == 1) {
				search_num = 0;
				return clean;
			}
		}
		break;
	case 3:
		if (map[m + 1][n] == 0) {
			dir = (dir + 3) % 4;
			search_num = 0;
			search(m + 1, n, dir);
		}
		else {
			if (search_num != 4) {
				dir = (dir + 3) % 4;
				search_num++;
				search(m, n, dir);
			}
			else if (map[m][n + 1] == 2) {
				search_num = 0;
				search(m, n + 1, dir);
			}
			else if (map[m][n + 1] == 1) {
				search_num = 0;
				return clean;
			}
		}
		break;
	}
	return clean;
}

int main() {
	int N, M;
	int r, c, d;
	cin >> N >> M;
	cin >> r >> c >> d;

	for (int i = 0; i < 50; i++) {  // 벽 
		for (int j = 0; j < 50; j++) {
			map[i][j] = 1;
		}
	}

	for (int i = 0; i < N; i++) {  // 지도 입력
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	clean = 0;
	search_num = 0;

	search(r, c, d);
	cout << clean << endl;
}