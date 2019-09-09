#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
struct pos {
	int dir, r, c;
	pos(int dir, int r, int c) : dir(dir), r(r), c(c) {}
	pos() {}
};

int ans = 0;
queue<pos> q;
int visit[100][100][4] = { 0, };


void bfs(vector<vector<int>> bb) {
	ans = 0;
	int N = bb[0].size();
	while (!q.empty()) {
		int qsize = q.size();
		for (int t = 0; t < qsize; t++) {
			int dd = q.front().dir;
			int rr = q.front().r;
			int cc = q.front().c;
			q.pop();
			if (dd == 0) {
				if ((rr == N - 1 && cc == N - 1) || (rr == N - 1 && cc - 1 == N - 1)) return;
				if (cc - 2 >= 0 && bb[rr][cc - 2] == 0 && visit[rr][cc - 1][0] == 0 && visit[rr][cc - 2][2] == 0) {
					q.push(pos(0, rr, cc - 1));
					q.push(pos(2, rr, cc - 2));
					visit[rr][cc - 1][0] = 1;
					visit[rr][cc - 2][2] = 1;
				}
				if (cc + 1 <= N - 1 && bb[rr][cc + 1] == 0 && visit[rr][cc + 1][0] == 0 && visit[rr][cc][2] == 0) {
					q.push(pos(0, rr, cc + 1));
					q.push(pos(2, rr, cc));
					visit[rr][cc][2] = 1;
					visit[rr][cc + 1][0] = 1;
				}
				if (rr - 1 >= 0 && bb[rr - 1][cc - 1] == 0 && bb[rr - 1][cc] == 0 && visit[rr][cc][1] == 0 && visit[rr - 1][cc][3] == 0) {
					q.push(pos(1, rr, cc));
					q.push(pos(3, rr - 1, cc));
					visit[rr - 1][cc][3] = 1;
					visit[rr][cc][1] = 1;
				}
				if (rr + 1 <= N - 1 && bb[rr + 1][cc - 1] == 0 && bb[rr + 1][cc] == 0 && visit[rr][cc][3] == 0 && visit[rr + 1][cc][1] == 0) {
					q.push(pos(3, rr, cc));
					q.push(pos(1, rr + 1, cc));
					visit[rr + 1][cc][1] = 1;
					visit[rr][cc][3] = 1;
				}
				if (rr - 1 >= 0 && bb[rr - 1][cc - 1] == 0 && bb[rr - 1][cc] == 0 && visit[rr - 1][cc][0] == 0 && visit[rr - 1][cc - 1][2] == 0) {
					q.push(pos(0, rr - 1, cc));
					q.push(pos(2, rr - 1, cc - 1));
					visit[rr - 1][cc - 1][2] = 1;
					visit[rr - 1][cc][0] = 1;
				}
				if (rr + 1 <= N - 1 && bb[rr + 1][cc - 1] == 0 && bb[rr + 1][cc] == 0 && visit[rr + 1][cc][0] == 0 && visit[rr + 1][cc - 1][2] == 0) {
					q.push(pos(0, rr + 1, cc));
					q.push(pos(2, rr + 1, cc - 1));
					visit[rr + 1][cc - 1][2] = 1;
					visit[rr + 1][cc][0] = 1;
				}
			}
			else if (dd == 1) {
				if ((rr == N - 1 && cc == N - 1) || (rr - 1 == N - 1 && cc == N - 1)) return;
				if (rr - 2 >= 0 && bb[rr - 2][cc] == 0 && visit[rr - 1][cc][1] == 0 && visit[rr - 2][cc][3] == 0) {
					q.push(pos(1, rr - 1, cc));
					q.push(pos(3, rr - 2, cc));
					visit[rr - 2][cc][3] = 1;
					visit[rr - 1][cc][1] = 1;
				}
				if (rr + 1 <= N - 1 && bb[rr + 1][cc] == 0 && visit[rr + 1][cc][1] == 0 && visit[rr][cc][3] == 0) {
					q.push(pos(1, rr + 1, cc));
					q.push(pos(3, rr, cc));
					visit[rr][cc][3] = 1;
					visit[rr + 1][cc][1] = 1;
				}
				if (cc + 1 <= N - 1 && bb[rr - 1][cc + 1] == 0 && bb[rr][cc + 1] == 0 && visit[rr][cc][2] == 0 && visit[rr][cc + 1][0] == 0) {
					q.push(pos(2, rr, cc));
					q.push(pos(0, rr, cc + 1));
					visit[rr][cc + 1][0] = 1;
					visit[rr][cc][2] = 1;
				}
				if (cc - 1 >= 0 && bb[rr - 1][cc - 1] == 0 && bb[rr][cc - 1] == 0 && visit[rr][cc][0] == 0 && visit[rr][cc - 1][2] == 0) {
					q.push(pos(0, rr, cc));
					q.push(pos(2, rr, cc - 1));
					visit[2][rr][cc - 1] = 1;
					visit[rr][cc][0] = 1;
				}
				if (cc - 1 >= 0 && bb[rr - 1][cc - 1] == 0 && bb[rr][cc - 1] == 0 && visit[rr][cc - 1][1] == 0 && visit[rr - 1][cc - 1][3] == 0) {
					q.push(pos(1, rr, cc - 1));
					q.push(pos(3, rr - 1, cc - 1));
					visit[rr - 1][cc - 1][3] = 1;
					visit[rr][cc - 1][1] = 1;
				}
				if (cc + 1 <= N - 1 && bb[rr - 1][cc + 1] == 0 && bb[rr][cc + 1] == 0 && visit[rr][cc + 1][1] == 0 && visit[rr - 1][cc + 1][3] == 0) {
					q.push(pos(1, rr, cc + 1));
					q.push(pos(3, rr - 1, cc + 1));
					visit[rr - 1][cc + 1][3] = 1;
					visit[rr][cc + 1][1] = 1;
				}
			}
			else if (dd == 2) {
				if ((rr == N - 1 && cc == N - 1) || (rr == N - 1 && cc + 1 == N - 1)) return;
				if (cc - 1 >= 0 && bb[rr][cc - 1] == 0 && visit[rr][cc - 1][2] == 0 && visit[rr][cc][0] == 0) {
					q.push(pos(2, rr, cc - 1));
					q.push(pos(0, rr, cc));
					visit[rr][cc][0] = 1;
					visit[rr][cc - 1][2] = 1;
				}
				if (cc + 2 <= N - 1 && bb[rr][cc + 2] == 0 && visit[rr][cc + 1][2] == 0 && visit[rr][cc + 2][0] == 0) {
					q.push(pos(2, rr, cc + 1));
					q.push(pos(0, rr, cc + 2));
					visit[rr][cc + 2][0] = 1;
					visit[rr][cc + 1][2] = 1;
				}
				if (rr - 1 >= 0 && bb[rr - 1][cc + 1] == 0 && bb[rr - 1][cc] == 0 && visit[rr][cc][1] == 0 && visit[rr - 1][cc][3] == 0) {
					q.push(pos(1, rr, cc));
					q.push(pos(3, rr - 1, cc));
					visit[rr - 1][cc][3] = 1;
					visit[rr][cc][1] = 1;
				}
				if (rr + 1 <= N - 1 && bb[rr + 1][cc + 1] == 0 && bb[rr + 1][cc] == 0 && visit[rr][cc][3] == 0 && visit[rr + 1][cc][1] == 0) {
					q.push(pos(3, rr, cc));
					q.push(pos(1, rr + 1, cc));
					visit[rr + 1][cc][1] = 1;
					visit[rr][cc][3] = 1;
				}
				if (rr - 1 >= 0 && bb[rr - 1][cc + 1] == 0 && bb[rr - 1][cc] == 0 && visit[rr - 1][cc][2] == 0 && visit[rr - 1][cc + 1][0] == 0) {
					q.push(pos(2, rr - 1, cc));
					q.push(pos(0, rr - 1, cc + 1));
					visit[rr - 1][cc + 1][0] = 1;
					visit[rr - 1][cc][2] = 1;
				}
				if (rr + 1 <= N - 1 && bb[rr + 1][cc + 1] == 0 && bb[rr + 1][cc] == 0 && visit[rr + 1][cc][2] == 0 && visit[rr + 1][cc + 1][0] == 0) {
					q.push(pos(2, rr + 1, cc));
					q.push(pos(0, rr + 1, cc + 1));
					visit[rr + 1][cc + 1][0] = 1;
					visit[rr + 1][cc][2] = 1;
				}
			}
			else {
				if ((rr == N - 1 && cc == N - 1) || (rr + 1 == N - 1 && cc == N - 1)) return;
				if (rr - 1 >= 0 && bb[rr - 1][cc] == 0 && visit[rr - 1][cc][3] == 0 && visit[rr][cc][1] == 0) {
					q.push(pos(3, rr - 1, cc));
					q.push(pos(1, rr, cc));
					visit[rr][cc][1] = 1;
					visit[rr - 1][cc][3] = 1;
				}
				if (rr + 2 <= N - 1 && bb[rr + 2][cc] == 0 && visit[rr + 1][cc][3] == 0 && visit[rr + 2][cc][1] == 0) {
					q.push(pos(3, rr + 1, cc));
					q.push(pos(1, rr + 2, cc));
					visit[rr + 2][cc][1] = 1;
					visit[rr + 1][cc][3] = 1;
				}
				if (cc - 1 >= 0 && bb[rr + 1][cc - 1] == 0 && bb[rr][cc - 1] == 0 && visit[rr][cc][0] == 0 && visit[rr][cc - 1][2] == 0) {
					q.push(pos(0, rr, cc));
					q.push(pos(2, rr, cc - 1));
					visit[rr][cc - 1][2] == 1;
					visit[rr][cc][0] = 1;
				}
				if (cc + 1 <= N - 1 && bb[rr + 1][cc + 1] == 0 && bb[rr][cc + 1] == 0 && visit[rr][cc][2] == 0 && visit[rr][cc + 1][0] == 0) {
					q.push(pos(2, rr, cc));
					q.push(pos(0, rr, cc + 1));
					visit[rr][cc + 1][0] = 1;
					visit[rr][cc][2] = 1;
				}
				if (cc - 1 >= 0 && bb[rr + 1][cc - 1] == 0 && bb[rr][cc - 1] == 0 && visit[rr][cc - 1][3] == 0 && visit[rr + 1][cc - 1][1] == 0) {
					q.push(pos(3, rr, cc - 1));
					q.push(pos(1, rr + 1, cc - 1));
					visit[rr + 1][cc - 1][1] = 1;
					visit[rr][cc - 1][3] = 1;
				}
				if (cc + 1 <= N - 1 && bb[rr + 1][cc + 1] == 0 && bb[rr][cc + 1] == 0 && visit[rr][cc + 1][3] == 0 && visit[rr + 1][cc + 1][1] == 0) {
					q.push(pos(3, rr, cc + 1));
					q.push(pos(1, rr + 1, cc + 1));
					visit[rr + 1][cc + 1][1] = 1;
					visit[rr][cc + 1][3] = 1;
				}
			}
		}
		ans++;
	}
}

int solution(vector<vector<int>> board) {
	int answer = 0;
	q.push(pos(2, 0, 0));
	q.push(pos(0, 0, 1));
	visit[0][0][2] = 1;
	visit[0][1][0] = 1;
	bfs(board);
	return answer = ans;
}