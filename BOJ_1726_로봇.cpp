#include <iostream>
#include <queue>
using namespace std;
int M, N;
int map[101][101] = { 0, };
int visit[4][101][101] = { 0, };
int sr, sc, sd, er, ec, ed;
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };

struct pos {
	int r, c, d, cnt;
	pos(int rr, int cc, int dd, int ccnt) {
		r = rr;
		c = cc;
		d = dd;
		cnt = ccnt;
	}
	pos() {}
};

int turn_left(int dir) {
	if (dir == 1) return dir - 1;
	else if (dir == 2) return dir + 1;
	else if (dir == 3) return dir - 2;
	else return dir + 2;
}

int turn_right(int dir) {
	if (dir == 1) return dir + 2;
	else if (dir == 2) return dir - 2;
	else if (dir == 3) return dir - 1;
	else return dir + 1;
}

queue<pos> q;

int bfs() {
	q.push(pos(sr, sc, sd % 4, 0));

	visit[q.front().d][q.front().r][q.front().c] = 1;

	while (!q.empty()) {

		int rr = q.front().r;
		int cc = q.front().c;
		int dd = q.front().d;
		int cnt = q.front().cnt;
		q.pop();
		if (rr == er && cc == ec && dd == ed) {
			return cnt;
		}
		//turn right
		int nd = turn_right(dd);
		if (visit[nd][rr][cc] == 0) {
			visit[nd][rr][cc] = 1;
			q.push(pos(rr, cc, nd, cnt + 1));
		}
		// turn left
		nd = turn_left(dd);
		if (visit[nd][rr][cc] == 0) {
			visit[nd][rr][cc] = 1;
			q.push(pos(rr, cc, nd, cnt + 1));
		}
		if (dd == 1) { // 우
			for (int j = cc + 1; j <= cc + 3; j++) {  // go k
				if (j > N) break;
				if (map[rr][j] == 1)
					break;
				if (visit[dd][rr][j] == 1) continue;
				visit[dd][rr][j] = 1;
				q.push(pos(rr, j, dd, cnt + 1));
			}
		}
		else if (dd == 2) { // 좌
			for (int j = cc - 1; j >= cc - 3; j--) { // go k
				if (j < 1) break;
				if (map[rr][j] == 1)
					break;
				if (visit[dd][rr][j] == 1) continue;
				visit[dd][rr][j] = 1;
				q.push(pos(rr, j, dd, cnt + 1));
			}
		}
		else if (dd == 3) { // 하
			for (int j = rr + 1; j <= rr + 3; j++) { // go k
				if (j > M) break;
				if (map[j][cc] == 1) break;
				if (visit[dd][j][cc] == 1) continue;
				visit[dd][j][cc] = 1;
				q.push(pos(j, cc, dd, cnt + 1));
			}
		}
		else { // 상
			for (int j = rr - 1; j >= rr - 3; j--) { // go k
				if (j < 1) break;
				if (map[j][cc] == 1) break;
				if (visit[dd][j][cc] == 1) continue;
				visit[dd][j][cc] = 1;
				q.push(pos(j, cc, dd, cnt + 1));
			}
		}
	}
}

int main() {
	// M 세로 , N 가로
	cin >> M >> N;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
	cin >> sr >> sc >> sd >> er >> ec >> ed;
	ed = ed % 4;

	cout << bfs() << '\n';

	return 0;
}
