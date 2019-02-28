#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int N, K;
int L;
int map[101][101] = { 0, };   // º® 0 , ¹ì ²¿¸® 0
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int time;
queue<pair<int, char>> que;

int play(int y, int x, int direc) {
	queue<pair<int, int>> loc;
	while (que.size()) {
		int num;
		num = que.front().first;
		char dir;
		dir = que.front().second;
		que.pop();
		while (time != num) {
			if (que.size() == 0) {
				num = 9999999;
			}
			time++;
			pair<int, int> p(y, x);
			loc.push(p);
			int nx, ny;
			nx = x + dx[direc];
			ny = y + dy[direc];
			if (map[ny][nx] == 0) {
				return time;
			}
			map[y][x] = 0;
			if (map[ny][nx] == 2) {
				map[ny][nx] = 1;
				x = nx;
				y = ny;
				for (int i = 1; i <= N; i++) {
					for (int j = 1; j <= N; j++) {
						cout << map[i][j] << ' ';
					}
					cout << endl;
				}
				continue;
			}
			else if (map[ny][nx] == 3) {
				map[ny][nx] = 1;
				map[loc.front().first][loc.front().second] = 3;
				loc.pop();
				x = nx;
				y = ny;
				for (int i = 1; i <= N; i++) {
					for (int j = 1; j <= N; j++) {
						cout << map[i][j] << ' ';
					}
					cout << endl;
				}
			}
		}
		if (dir == 'L')
			direc = (direc + 3) % 4;
		else
			direc = (direc + 1) % 4;
	}
}



int main() {
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			map[i][j] = 3;  // ¸Ê  3
		}
	}
	map[1][1] = 1; // ¹ì ¸Ó¸® 1

	for (int i = 0; i < K; i++) {  // »ç°ú ¹èÄ¡
		int tmpx, tmpy;
		cin >> tmpy >> tmpx;
		map[tmpy][tmpx] = 2;  // »ç°ú 2
	}

	cin >> L;
	for (int i = 0; i < L; i++) {
		pair<int, char> dir;
		cin >> dir.first >> dir.second;
		que.push(dir);
	}

	time = 0;
	cout << play(1, 1, 0) << endl;

	return 0;
}