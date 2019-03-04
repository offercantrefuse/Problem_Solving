#include <iostream>
using namespace std;
int dice[7] = { 0, };
int map[20][20] = { 0, };
int N, M, x, y, k;

void move(int dir) {
	int tmp;
	switch (dir) {
	case 1:
		tmp = dice[1];
		dice[1] = dice[4];
		dice[4] = dice[6];
		dice[6] = dice[3];
		dice[3] = tmp;
		break;
	case 2:
		tmp = dice[1];
		dice[1] = dice[3];
		dice[3] = dice[6];
		dice[6] = dice[4];
		dice[4] = tmp;
		break;
	case 3:
		tmp = dice[1];
		dice[1] = dice[5];
		dice[5] = dice[6];
		dice[6] = dice[2];
		dice[2] = tmp;
		break;
	case 4:
		tmp = dice[1];
		dice[1] = dice[2];
		dice[2] = dice[6];
		dice[6] = dice[5];
		dice[5] = tmp;
		break;
	}
}

void work(int nowx, int nowy, int dir) {
	switch (dir) {
	case 1:
		if (nowy + 1 <= M - 1) {
			move(1);
			if (map[nowx][nowy + 1] == 0) {
				map[nowx][nowy + 1] = dice[6];
			}
			else {
				dice[6] = map[nowx][nowy + 1];
				map[nowx][nowy + 1] = 0;
			}
		}
		break;
	case 2:
		if (nowy - 1 >= 0) {
			move(2);
			if (map[nowx][nowy - 1] == 0) {
				map[nowx][nowy - 1] = dice[6];
			}
			else {
				dice[6] = map[nowx][nowy - 1];
				map[nowx][nowy - 1] = 0;
			}
		}
		break;
	case 3:
		if (nowx - 1 >= 0) {
			move(3);
			if (map[nowx - 1][nowy] == 0) {
				map[nowx - 1][nowy] = dice[6];
			}
			else {
				dice[6] = map[nowx - 1][nowy];
				map[nowx - 1][nowy] = 0;
			}
		}
		break;
	case 4:
		if (nowx + 1 <= N - 1) {
			move(4);
			if (map[nowx + 1][nowy] == 0) {
				map[nowx + 1][nowy] = dice[6];
			}
			else {
				dice[6] = map[nowx + 1][nowy];
				map[nowx + 1][nowy] = 0;
			}
		}
		break;
	}
}

int main() {
	cin >> N >> M >> x >> y >> k;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		int command;
		cin >> command;

		work(x, y, command);
		switch (command) {
		case 1:
			if (y + 1 <= M - 1) {
				y++;
				cout << dice[1] << endl;
			}
			break;
		case 2:
			if (y - 1 >= 0) {
				y--;
				cout << dice[1] << endl;
			}
			break;
		case 3:
			if (x - 1 >= 0) {
				x--;
				cout << dice[1] << endl;
			}
			break;
		case 4:
			if (x + 1 <= N - 1) {
				x++;
				cout << dice[1] << endl;
			}
			break;
		}
	}
	return 0;
}