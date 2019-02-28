#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
struct pos {
	int r, c;
	pos(int r, int c) : r(r), c(c) {}
	pos() {}
};
int N, time = 0, ans = 0, shark, fish;
int map[20][20] = { 0, };
int visit[20][20] = { 0, };
int dr[] = { -1,0,1,0 };
int dc[] = { 0,-1,0,1 };
queue<pos> q;
vector<pos> vec;

bool cmp(pos a, pos b) {
	if (a.r == b.r) return a.c < b.c;
	else return a.r < b.r;
}

void bfs() {
	while (!q.empty()) {
		int size = q.size();
		bool found = false;
		time++;
		for (int t = 0; t < size; t++) {
			int rr = q.front().r;
			int cc = q.front().c;
			visit[rr][cc] = 1;
			q.pop();
			for (int d = 0; d < 4; d++) {
				int nr = rr + dr[d];
				int nc = cc + dc[d];
				if (nr<0 || nr>N - 1 || nc<0 || nc>N - 1 || visit[nr][nc] == 1) continue;
				if (map[nr][nc] == 0) {  // 빈 공간
					visit[nr][nc] = 1;
					q.push(pos(nr, nc));
				}
				else {
					if (shark > map[nr][nc]) { // 잡아먹을 수 있을때
						visit[nr][nc] = 1;
						vec.push_back(pos(nr, nc));
						q.push(pos(nr, nc));
						found = true;
					}
					else if (shark == map[nr][nc]) { // 크기 같을때
						visit[nr][nc] = 1;
						q.push(pos(nr, nc));
					}
				}
			}
		}
		if (found) { // 찾았을 때
			ans = time; // 시간 추가
			sort(vec.begin(), vec.end(), cmp);  // r 작은순 -> c 작은순 정렬
			while (!q.empty()) q.pop(); // q 클리어
			if (fish == shark) { // 상어 크기 = 고기 수
				shark++; // 상어 증량
				fish = 1;
			}
			else fish++;
			map[vec[0].r][vec[0].c] = 0; // map 0 으로
			q.push(pos(vec[0].r, vec[0].c));
			vec.clear();
			memset(visit, 0, sizeof(visit));
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				q.push(pos(i, j));
				map[i][j] = 0;
			}
		}
	}
	shark = 2;
	fish = 1;
	bfs();
	cout << ans;
	return 0;
}