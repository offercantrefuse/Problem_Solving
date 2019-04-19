#include <iostream>
#include <vector>
using namespace std;
struct pos {
	int x, y;
	pos(int x, int y) : x(x), y(y) {}
	pos() {}
};
int N, M, D, ans, cnt;
bool visit[15];
int arr[3] = { 0, };
int copied[15][15] = { 0, };
int sniper[3] = { 0, };
int map[15][15] = { 0, };

void map_copy() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			copied[i][j] = map[i][j];
		}
	}
}

void simul() {
	cnt = 0;
	int yy = N;
	vector<pos> vec;
	for (int tt = 0; tt < N; tt++) {  // row 수만큼
		for (int k = 0; k < 3; k++) {
			bool found = false;
			int xx = arr[k];
			for (int d = 1; d <= D && !found; d++) {
				for (int i = yy - 1; i >= yy - d && i >= 0 && !found; i--) {   // 거리 d 에 따라 왼쪽부터 오른쪽 위로 올라감
					if (xx - (d - (yy - i)) < 0) continue;
					if (copied[i][xx - (d - (yy - i))] == 1) {  // 찾으면 2로 바꿈
						copied[i][xx - (d - (yy - i))] = 2;
						cnt++;
						found = true;
						vec.push_back(pos(xx - (d - (yy - i)), i));   // 찾은 좌표 vector에 넣어줌
					}
					else if (copied[i][xx - (d - (yy - i))] == 2) {
						found = true;
					}
				}
				if (found) break;   // 이미 찾았으면 break
				for (int i = yy - d + 1; i <= yy - 1 && !found; i++) {  // 거리 d에 따라 위쪽부터 오른쪽 아래로 내려옴 
					if (i < 0) continue;
					if (xx + (d - (yy - i)) > M - 1) continue;
					if (copied[i][xx + (d - (yy - i))] == 1) {
						copied[i][xx + (d - (yy - i))] = 2;
						cnt++;
						found = true;
						vec.push_back(pos(xx + (d - (yy - i)), i));  // 찾은 좌표 vector에 넣어줌
					}
					else if (copied[i][xx + (d - (yy - i))] == 2) {
						found = true;
					}
				}

			}
		}
		for (auto v : vec) {  // 2로 바꿔줬던 좌표들 0으로
			copied[v.y][v.x] = 0;
		}
		vec.clear();
		yy--;
	}
}


void dfs(int idx, int num) {
	if (idx == 3) {
		map_copy();
		simul();
		ans = ans < cnt ? cnt : ans;
		return;
	}
	for (int i = num; i < M; i++) {
		if (!visit[i]) {
			visit[i] = true;
			arr[idx] = i;
			dfs(idx + 1, i);
			visit[i] = false;
		}
	}
}

int main() {
	cin >> N >> M >> D;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	ans = 0;
	dfs(0, 0);
	cout << ans << '\n';
	return 0;
}