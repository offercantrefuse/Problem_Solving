#include <iostream>
#include <queue>
using namespace std;

struct node {
	int r, c, mal, target, cnt;
	node(int r, int c, int mal, int target, int cnt) : r(r), c(c), mal(mal), target(target), cnt(cnt) {}
	node() {}
};

int N, sr, sc, endr, endc, ans = 0;
int map[10][10] = { 0, };
int visit[10][10][3][101] = { 0, };
int dkr[] = { -2,-1,1,2,2,1,-1,-2 };
int dkc[] = { 1,2,2,1,-1,-2,-2,-1 };
int dr[] = { -1,0,1,0 };
int dc[] = { 0,-1,0,1 };
queue<node> q;

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
		visit[sr][sc][i][2] = 1;
	q.push(node(sr, sc, 0, 2, 0));
	q.push(node(sr, sc, 1, 2, 0));
	q.push(node(sr, sc, 2, 2, 0));

	while (!q.empty()) {
		int rr = q.front().r;
		int cc = q.front().c;
		int mmal = q.front().mal;
		int ttarget = q.front().target;
		int ccnt = q.front().cnt;
		q.pop();

		if (rr == endr && cc == endc && ttarget == N * N + 1 && map[rr][cc] == N * N) {
			ans = ccnt;
			break;
		}

		if (mmal == 0) { // 나이트
			// 말 바꾸기
			for (int i = 1; i <= 2; i++) {
				if (visit[rr][cc][(mmal + i) % 3][ttarget] == 0) {
					visit[rr][cc][(mmal + i) % 3][ttarget] = 1;
					int tmp;
					tmp = (map[rr][cc] == ttarget) ? ttarget + 1 : ttarget;
					q.push(node(rr, cc, (mmal + i) % 3, tmp, ccnt + 1));
				}
			}
			// 이동
			for (int d = 0; d < 8; d++) {
				int nr = rr + dkr[d];
				int nc = cc + dkc[d];
				if (nr<0 || nc<0 || nr>N - 1 || nc>N - 1) continue;
				if (visit[nr][nc][mmal][ttarget] == 0) {
					visit[nr][nc][mmal][ttarget] = 1;
					int tmp;
					tmp = (map[nr][nc] == ttarget) ? ttarget + 1 : ttarget;
					q.push(node(nr, nc, mmal, tmp, ccnt + 1));
				}
			}
		}
		else if (mmal == 1) { // 비숍
			// 말 바꾸기
			for (int i = 1; i <= 2; i++) {
				if (visit[rr][cc][(mmal + i) % 3][ttarget] == 0) {
					visit[rr][cc][(mmal + i) % 3][ttarget] = 1;
					int tmp;
					tmp = (map[rr][cc] == ttarget) ? ttarget + 1 : ttarget;
					q.push(node(rr, cc, (mmal + i) % 3, tmp, ccnt + 1));
				}
			}
			// 이동
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (i - j == rr - cc || i + j == rr + cc) {
						if (visit[i][j][mmal][ttarget] == 0) {
							visit[i][j][mmal][ttarget] = 1;
							int tmp;
							tmp = (map[i][j] == ttarget) ? ttarget + 1 : ttarget;
							q.push(node(i, j, mmal, tmp, ccnt + 1));
						}
					}
				}
			}
		}
		else if (mmal == 2) { // 룩
			// 말 바꾸기
			for (int i = 1; i <= 2; i++) {
				if (visit[rr][cc][(mmal + i) % 3][ttarget] == 0) {
					visit[rr][cc][(mmal + i) % 3][ttarget] = 1;
					int tmp;
					tmp = (map[rr][cc] == ttarget) ? ttarget + 1 : ttarget;
					q.push(node(rr, cc, (mmal + i) % 3, tmp, ccnt + 1));
				}
			}
			// 이동
			for (int i = rr - 1; i >= 0; i--) { // up
				if (visit[i][cc][mmal][ttarget] == 0) {
					visit[i][cc][mmal][ttarget] = 1;
					int tmp;
					tmp = (map[i][cc] == ttarget) ? ttarget + 1 : ttarget;
					q.push(node(i, cc, mmal, tmp, ccnt + 1));
				}
			}
			for (int j = cc - 1; j >= 0; j--) { // left
				if (visit[rr][j][mmal][ttarget] == 0) {
					visit[rr][j][mmal][ttarget] = 1;
					int tmp;
					tmp = (map[rr][j] == ttarget) ? ttarget + 1 : ttarget;
					q.push(node(rr, j, mmal, tmp, ccnt + 1));
				}
			}
			for (int i = rr + 1; i < N; i++) { // down
				if (visit[i][cc][mmal][ttarget] == 0) {
					visit[i][cc][mmal][ttarget] = 1;
					int tmp;
					tmp = (map[i][cc] == ttarget) ? ttarget + 1 : ttarget;
					q.push(node(i, cc, mmal, tmp, ccnt + 1));
				}
			}
			for (int j = cc + 1; j < N; j++) { // right
				if (visit[rr][j][mmal][ttarget] == 0) {
					visit[rr][j][mmal][ttarget] = 1;
					int tmp;
					tmp = (map[rr][j] == ttarget) ? ttarget + 1 : ttarget;
					q.push(node(rr, j, mmal, tmp, ccnt + 1));
				}
			}
		}
	}
	cout << ans;
	return 0;
}