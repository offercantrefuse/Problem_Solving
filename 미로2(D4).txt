#include <iostream>
#include <string>

using namespace std;

int arr[100][100];
int init_x, init_y;
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
int flag;

int dfs(int m, int n) {
	arr[m][n] = 1;
	for (int k = 0; k < 4; k++) {
		if (arr[m + dy[k]][n + dx[k]] == 0) {
			dfs(m + dy[k], n + dx[k]);
		}
		else if (arr[m + dy[k]][n + dx[k]] == 3) {
			flag = 1;
		}
	}
	return flag;
}


int main() {
	int tc, n, i, j;
	string s;
	for (tc = 1; tc <= 10; tc++) {
		flag = 0;
		cin >> n;
		for (i = 0; i < 100; i++) {
			cin >> s;
			for (j = 0; j < 100; j++) {
				arr[i][j] = s.at(j) - '0';
				if (arr[i][j] == 2) {
					init_x = i;
					init_y = j;
				}
			}
		}
		cout << "#" << tc << " " << dfs(init_x, init_y) << endl;
	}
}