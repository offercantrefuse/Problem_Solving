#include <iostream>
using namespace std;
int N, M;
int map[500][500] = { 0, };
int ans;

int search() {
	int tmp;
	//1
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= M - 4; j++) {
			tmp = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i][j + 3];
			if (tmp > ans) ans = tmp;
		}
	}
	//2
	for (int i = 0; i <= N - 4; i++) {
		for (int j = 0; j < M; j++) {
			tmp = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 3][j];
			if (tmp > ans) ans = tmp;
		}
	}
	//3
	for (int i = 0; i <= N - 2; i++) {
		for (int j = 0; j <= M - 2; j++) {
			tmp = map[i][j] + map[i + 1][j] + map[i][j + 1] + map[i + 1][j + 1];
			if (tmp > ans) ans = tmp;
		}
	}
	//4: 
	for (int i = 0; i <= N - 3; i++) {
		for (int j = 0; j <= M - 2; j++) {
			tmp = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 2][j + 1];
			if (tmp > ans) ans = tmp;
		}
	}
	//5
	for (int i = 0; i <= N - 3; i++) {
		for (int j = 1; j < M; j++) {
			tmp = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 2][j - 1];
			if (tmp > ans) ans = tmp;
		}
	}
	//6
	for (int i = 0; i <= N - 3; i++) {
		for (int j = 0; j <= M - 2; j++) {
			tmp = map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j + 1];
			if (tmp > ans) ans = tmp;
		}
	}
	//7
	for (int i = 0; i <= N - 3; i++) {
		for (int j = 0; j <= M - 2; j++) {
			tmp = map[i][j] + map[i][j + 1] + map[i + 1][j] + map[i + 2][j];
			if (tmp > ans) ans = tmp;
		}
	}
	//8
	for (int i = 0; i <= N - 2; i++) {
		for (int j = 0; j <= M - 3; j++) {
			tmp = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2];
			if (tmp > ans) ans = tmp;
		}
	}
	//9
	for (int i = 0; i <= N - 2; i++) {
		for (int j = 2; j <= M - 1; j++) {
			tmp = map[i][j] + map[i + 1][j] + map[i + 1][j - 1] + map[i + 1][j - 2];
			if (tmp > ans) ans = tmp;
		}
	}
	//10
	for (int i = 0; i <= N - 2; i++) {
		for (int j = 0; j <= M - 3; j++) {
			tmp = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 2];
			if (tmp > ans) ans = tmp;
		}
	}
	//11
	for (int i = 0; i <= N - 2; i++) {
		for (int j = 0; j <= M - 3; j++) {
			tmp = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j];
			if (tmp > ans) ans = tmp;
		}
	}
	//12
	for (int i = 0; i <= N - 3; i++) {
		for (int j = 0; j <= M - 2; j++) {
			tmp = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j + 1];
			if (tmp > ans) ans = tmp;
		}
	}
	//13
	for (int i = 0; i <= N - 3; i++) {
		for (int j = 1; j <= M - 1; j++) {
			tmp = map[i][j] + map[i + 1][j] + map[i + 1][j - 1] + map[i + 2][j - 1];
			if (tmp > ans) ans = tmp;
		}
	}
	//14
	for (int i = 0; i <= N - 2; i++) {
		for (int j = 0; j <= M - 3; j++) {
			tmp = map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 1][j + 2];
			if (tmp > ans) ans = tmp;
		}
	}
	//15
	for (int i = 0; i <= N - 2; i++) {
		for (int j = 1; j <= M - 2; j++) {
			tmp = map[i][j] + map[i][j + 1] + map[i + 1][j] + map[i + 1][j - 1];
			if (tmp > ans) ans = tmp;
		}
	}
	//16
	for (int i = 0; i <= N - 2; i++) {
		for (int j = 1; j <= M - 2; j++) {
			tmp = map[i][j] + map[i + 1][j] + map[i + 1][j - 1] + map[i + 1][j + 1];
			if (tmp > ans) ans = tmp;
		}
	}
	//17
	for (int i = 0; i <= N - 2; i++) {
		for (int j = 0; j <= M - 3; j++) {
			tmp = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 1];
			if (tmp > ans) ans = tmp;
		}
	}
	//18
	for (int i = 0; i <= N - 3; i++) {
		for (int j = 0; j <= M - 2; j++) {
			tmp = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 1][j + 1];
			if (tmp > ans) ans = tmp;
		}
	}
	//19
	for (int i = 0; i <= N - 3; i++) {
		for (int j = 1; j <= M - 1; j++) {
			tmp = map[i][j] + map[i + 1][j] + map[i + 1][j - 1] + map[i + 2][j];
			if (tmp > ans) ans = tmp;
		}
	}
	return ans;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	ans = 0;

	cout << search() << endl;

	return 0;
}