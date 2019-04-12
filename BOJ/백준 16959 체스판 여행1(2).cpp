#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node {
	int r, c, mal;
	node(int r, int c, int mal) : r(r), c(c), mal(mal) {}
	node() {}
};

struct node2 {
	int r, c, mal, cnt;
	node2(int r, int c, int mal, int cnt) : r(r), c(c), mal(mal), cnt(cnt) {}
	node2() {}
};
int N, sr, sc, endr, endc;
int map[10][10] = { 0, };
int visit[10][10][3] = { 0, };
int dkr[] = { -2,-1,1,2,2,1,-1,-2 };
int dkc[] = { 1,2,2,1,-1,-2,-2,-1 };
bool flag = false;
queue<node> q;
vector<node2> vec;

int maxi(int x, int y, int z) {
	int maximum = x;
	if (y > maximum)
		maximum = y;
	if (z > maximum)
		maximum = z;
	return maximum;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				sr = i;
				sc = j;
			}
			if (map[i][j] == N * N) {
				endr = i;
				endc = j;
			}
		}
	}
	for (int i = 0; i < 3; i++)
		visit[sr][sc][i] = 1;
	q.push(node(sr, sc, 0));
	q.push(node(sr, sc, 1));
	q.push(node(sr, sc, 2));

	int target = 2;
	while (target <= N * N) {
		// target 도달 했었을때
		if (flag) {
			// q에 clear후 vec 넣기
			while (!q.empty()) q.pop();
			for (int i = 0; i < vec.size(); i++)
				q.push(node(vec[i].r, vec[i].c, vec[i].mal));
			// visit 초기화 후 현재 visit 1
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					for (int k = 0; k < 3; k++) {
						visit[i][j][k] = 0;
					}
				}
			}
			// visit check
			for (int i = 0; i < vec.size(); i++) {
				if (visit[vec[i].r][vec[i].c][vec[i].mal] == 0)
					visit[vec[i].r][vec[i].c][vec[i].mal] = vec[i].cnt;
			}
			vec.clear();
			flag = false;
			target++;
			continue;
		}

		int qsize = q.size();
		for (int t = 0; t < qsize; t++) {
			int rr = q.front().r;
			int cc = q.front().c;
			int mmal = q.front().mal;
			q.pop();
			// target 들어왔는지 check
			if (map[rr][cc] == target) {
				flag = true;
				vec.push_back(node2(rr, cc, mmal, visit[rr][cc][mmal]));
				continue;
			}
			if (mmal == 0) { // 나이트
				// 말 바꾸기
				for (int i = 1; i <= 2; i++) {
					if (visit[rr][cc][(mmal + i) % 3] == 0) {
						visit[rr][cc][(mmal + i) % 3] = visit[rr][cc][mmal] + 1;
						q.push(node(rr, cc, (mmal + i) % 3));
					}
				}
				// 이동
				for (int d = 0; d < 8; d++) {
					int nr = rr + dkr[d];
					int nc = cc + dkc[d];
					if (nr<0 || nc<0 || nr>N - 1 || nc>N - 1) continue;
					if (visit[nr][nc][mmal] == 0 || visit[nr][nc][mmal] > visit[rr][cc][mmal] + 1) {
						visit[nr][nc][mmal] = visit[rr][cc][mmal] + 1;
						q.push(node(nr, nc, mmal));
					}
				}
			}
			else if (mmal == 1) { // 비숍
				// 말 바꾸기
				for (int i = 1; i <= 2; i++) {
					if (visit[rr][cc][(mmal + i) % 3] == 0 || visit[rr][cc][(mmal + i) % 3] > visit[rr][cc][mmal] + 1) {
						visit[rr][cc][(mmal + i) % 3] = visit[rr][cc][mmal] + 1;
						q.push(node(rr, cc, (mmal + i) % 3));
					}
				}
				// 이동
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < N; j++) {
						if (i - j == rr - cc || i + j == rr + cc) {
							if (visit[i][j][mmal] == 0 || visit[i][j][mmal] > visit[rr][cc][mmal] + 1) {
								visit[i][j][mmal] = visit[rr][cc][mmal] + 1;
								q.push(node(i, j, mmal));
							}
						}
					}
				}
			}
			else if (mmal == 2) { // 룩
				// 말 바꾸기
				for (int i = 1; i <= 2; i++) {
					if (visit[rr][cc][(mmal + i) % 3] == 0 || visit[rr][cc][(mmal + i) % 3] > visit[rr][cc][mmal] + 1) {
						visit[rr][cc][(mmal + i) % 3] = visit[rr][cc][mmal] + 1;
						q.push(node(rr, cc, (mmal + i) % 3));
					}
				}
				// 이동
				for (int i = rr - 1; i >= 0; i--) { // up
					if (visit[i][cc][mmal] == 0) {
						visit[i][cc][mmal] = visit[rr][cc][mmal] + 1;
						q.push(node(i, cc, mmal));
					}
				}
				for (int j = cc - 1; j >= 0; j--) { // left
					if (visit[rr][j][mmal] == 0) {
						visit[rr][j][mmal] = visit[rr][cc][mmal] + 1;
						q.push(node(rr, j, mmal));
					}
				}
				for (int i = rr + 1; i < N; i++) { // down
					if (visit[i][cc][mmal] == 0) {
						visit[i][cc][mmal] = visit[rr][cc][mmal] + 1;
						q.push(node(i, cc, mmal));
					}
				}
				for (int j = cc + 1; j < N; j++) { // right
					if (visit[rr][j][mmal] == 0) {
						visit[rr][j][mmal] = visit[rr][cc][mmal] + 1;
						q.push(node(rr, j, mmal));
					}
				}
			}
		}
	}
	cout << maxi(visit[endr][endc][0], visit[endr][endc][1], visit[endr][endc][2]) - 1;
	return 0;
}