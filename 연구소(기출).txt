#include <iostream>
using namespace std;
int M, N;
int map[10][10];
int cnt_virus;
int max_zero;
int tmp[10][10];
int count_zero(int arr[10][10]) {
	int cnt_zero = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (arr[i][j] == 0) cnt_zero++;
		}
	}
	return cnt_zero;
}

int spread(int arr[][10], int m, int n) {
	if (arr[m][n] == 2) {
		if (m > 1 && arr[m - 1][n] == 0) {  // 위
				arr[m - 1][n] = 2;
				spread(arr, m - 1, n);
		}
		if (m < N  && arr[m + 1][n] == 0) { // 아래
				arr[m + 1][n] = 2;
				spread(arr, m + 1, n);
		}
		if (n > 1 && arr[m][n - 1] == 0) { // 왼
				arr[m][n - 1] = 2;
				spread(arr, m, n - 1);
		}
		if (n < M && arr[m][n + 1] == 0) { // 오른
				arr[m][n + 1] = 2;
				spread(arr, m, n + 1);
		}
	}
	return arr[10][10];
}

void dfs(int arr[][10], int cnt) {
	if (cnt == 0) {
		for (int i = 1; i <= N; i++) { 
			for (int j = 1; j <= M; j++) {
				tmp[i][j] = arr[i][j];
			}
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				spread(tmp, i, j);
			}
		}
		max_zero = (max_zero < count_zero(tmp)) ? count_zero(tmp) : max_zero;
	}
	else {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (arr[i][j] == 0) {
					arr[i][j] = 1;
					dfs(arr, --cnt);
					arr[i][j] = 0;
					++cnt;
				}
			}
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			map[i][j] = 1;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}
	cnt_virus = 0;
	max_zero = 0;
	dfs(map, 3);
	cout << max_zero << endl;
	return 0;
}