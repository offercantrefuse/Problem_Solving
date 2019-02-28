#include <iostream>
#include <vector>
using namespace std;

struct pos { // robot structure
	int r, c, dir;
	pos(int r, int c, int dir) : r(r), c(c), dir(dir) {}
	pos() {}
};
int A, B, N, M, prob, rnum, rnum2;
int map[101][101] = { 0, };
int dr[] = { 1,0,-1,0 };
int dc[] = { 0,1,0,-1 };
vector<pos> robot;

void simul(int num, char cmd, int rep) {
	for (int i = 0; i < rep; i++) {
		if (cmd == 'L') {
			robot[num].dir = (robot[num].dir + 3) % 4;
		}
		else if (cmd == 'R') {
			robot[num].dir = (robot[num].dir + 1) % 4;
		}
		else {
			int tmp = map[robot[num].r][robot[num].c];
			map[robot[num].r][robot[num].c] = 0;
			robot[num].r += dr[robot[num].dir];
			robot[num].c += dc[robot[num].dir];
			if (robot[num].r <1 || robot[num].r>B || robot[num].c <1 || robot[num].c>A) { // crashes wall
				prob = 1;
				rnum = num + 1;
				return;
			}
			else if (map[robot[num].r][robot[num].c] != 0) {  // crashes robot
				prob = 2;
				rnum = num + 1;
				rnum2 = map[robot[num].r][robot[num].c];
				return;
			}
			else {
				map[robot[num].r][robot[num].c] = tmp;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> A >> B >> N >> M;
	int cnt = 1;
	for (int i = 0; i < N; i++) { // 로봇 정보
		int tmpc, tmpr, tmpd;
		char d;
		cin >> tmpc >> tmpr >> d;
		if (d == 'N') tmpd = 0;
		else if (d == 'E') tmpd = 1;
		else if (d == 'S') tmpd = 2;
		else tmpd = 3;
		robot.push_back(pos(tmpr, tmpc, tmpd));
		map[tmpr][tmpc] = cnt++;
	}
	prob = 0; // 0: ok, 1: 밖으로 벗어남(벽충돌), 2:다른 로봇 충돌
	rnum = 0;
	rnum2 = 0;
	for (int i = 0; i < M; i++) {
		int num, rep;
		char cmd;
		cin >> num >> cmd >> rep;
		simul(num - 1, cmd, rep);
		if (prob != 0) break;
	}
	if (prob == 0) cout << "OK" << '\n';
	else if (prob == 1) cout << "Robot " << rnum << " crashes into the wall" << '\n';
	else cout << "Robot " << rnum << " crashes into robot " << rnum2;
	return 0;
}
