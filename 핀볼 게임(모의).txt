#include <iostream>
using namespace std;
int T, N;
bool flag;
struct pos {
	int r, c;
	pos(int rr, int cc) {
		r = rr;
		c = cc;
	}
	pos() {}
};

struct node {
	int r, c, dir;
	node(int rr, int cc, int ddir) {
		r = rr;
		c = cc;
		dir = ddir;
	}
};

inline int maxi(int a, int b) {
	return a > b ? a : b;
}

int map[100][100] = { 0, };
int dc[] = { -1,0,1,0 };
int dr[] = { 0,-1,0,1 };
pos worm6[2], worm7[2], worm8[2], worm9[2], worm10[2];
pos endpos;

int go(node nn) {
	int cnt = 0;
	node now = node(nn.r, nn.c, nn.dir);
	while (1) {
		if (flag && now.r == endpos.r && now.c == endpos.c) {
			break;
		}
		flag = true;
		int new_r = now.r + dr[now.dir];
		int new_c = now.c + dc[now.dir];
		if (new_r<0 || new_r>N - 1 || new_c<0 || new_c>N - 1) {
			cnt++;
			now.dir = (now.dir + 2) % 4;
			now.r = new_r;
			now.c = new_c;
		}
		else if (map[new_r][new_c] == 0) {
			now.r = new_r;
			now.c = new_c;
		}
		else if (map[new_r][new_c] == 1) {
			cnt++;
			now.r = new_r;
			now.c = new_c;
			switch (now.dir) {
			case 0: now.dir = 1;
				break;
			case 1: now.dir = 3;
				break;
			case 2: now.dir = 0;
				break;
			case 3: now.dir = 2;
			}
		}
		else if (map[new_r][new_c] == 2) {
			cnt++;
			now.r = new_r;
			now.c = new_c;
			switch (now.dir) {
			case 0: now.dir = 3;
				break;
			case 1: now.dir = 2;
				break;
			case 2: now.dir = 0;
				break;
			case 3: now.dir = 1;
			}
		}
		else if (map[new_r][new_c] == 3) {
			cnt++;
			now.r = new_r;
			now.c = new_c;
			switch (now.dir) {
			case 0: now.dir = 2;
				break;
			case 1: now.dir = 0;
				break;
			case 2: now.dir = 3;
				break;
			case 3: now.dir = 1;
			}
		}
		else if (map[new_r][new_c] == 4) {
			cnt++;
			now.r = new_r;
			now.c = new_c;
			switch (now.dir) {
			case 0: now.dir = 2;
				break;
			case 1: now.dir = 3;
				break;
			case 2: now.dir = 1;
				break;
			case 3: now.dir = 0;
			}
		}
		else if (map[new_r][new_c] == 5) {
			cnt++;
			now.r = new_r;
			now.c = new_c;
			now.dir = (now.dir + 2) % 4;
		}
		else if (map[new_r][new_c] == 6) {
			if (worm6[0].r == new_r && worm6[0].c == new_c) {
				now.r = worm6[1].r;
				now.c = worm6[1].c;
			}
			else {
				now.r = worm6[0].r;
				now.c = worm6[0].c;
			}
		}
		else if (map[new_r][new_c] == 7) {
			if (worm7[0].r == new_r && worm7[0].c == new_c) {
				now.r = worm7[1].r;
				now.c = worm7[1].c;
			}
			else {
				now.r = worm7[0].r;
				now.c = worm7[0].c;
			}
		}
		else if (map[new_r][new_c] == 8) {
			if (worm8[0].r == new_r && worm8[0].c == new_c) {
				now.r = worm8[1].r;
				now.c = worm8[1].c;
			}
			else {
				now.r = worm8[0].r;
				now.c = worm8[0].c;
			}
		}
		else if (map[new_r][new_c] == 9) {
			if (worm9[0].r == new_r && worm9[0].c == new_c) {
				now.r = worm9[1].r;
				now.c = worm9[1].c;
			}
			else {
				now.r = worm9[0].r;
				now.c = worm9[0].c;
			}
		}
		else if (map[new_r][new_c] == 10) {
			if (worm10[0].r == new_r && worm10[0].c == new_c) {
				now.r = worm10[1].r;
				now.c = worm10[1].c;
			}
			else {
				now.r = worm10[0].r;
				now.c = worm10[0].c;
			}
		}
		else if (map[new_r][new_c] == -1) {
			break;
		}
	}
	return cnt;
}


int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		int score = 0;
		int six = 0, seven = 0, eight = 0, nine = 0, ten = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				if (map[i][j] == 6) {
					worm6[six++] = pos(i, j);
				}
				else if (map[i][j] == 7) {
					worm7[seven++] = pos(i, j);
				}
				else if (map[i][j] == 8) {
					worm8[eight++] = pos(i, j);
				}
				else if (map[i][j] == 9) {
					worm9[nine++] = pos(i, j);
				}
				else if (map[i][j] == 10) {
					worm10[ten++] = pos(i, j);
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 0) {
					endpos = pos(i, j);
					for (int d = 0; d < 4; d++) {
						flag = false;
						score = maxi(score, go(node(i, j, d)));
					}
				}
			}
		}
		cout << "#" << tc << ' ' << score << '\n';
	}
	return 0;
}
