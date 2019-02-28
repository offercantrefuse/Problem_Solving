#include <iostream>
using namespace std;
int T, M, A;
int user_move[2][100];
int cnt = 0;

struct {
	int x, y;
} user[2];

struct {
	int x, y, p, c, u;
} ap[8];
int dx[] = { 0,0,1,0,-1 };
int dy[] = { 0,-1,0,1,0 };
void init() {
	user[0].x = 1;
	user[0].y = 1;
	user[1].x = 10;
	user[1].y = 10;

	for (int i = 0; i < 8; i++) ap[i].u = 0;
}

inline int abs(int a) {
	return a > 0 ? a : -a;
}
inline int maxi(int a, int b) {
	return a > b ? a : b;
}
bool check(int a, int b) {
	int dist = abs(user[a].x - ap[b].x) + abs(user[a].y - ap[b].y);
	if (dist <= ap[b].c) return true;
	else return false;
}

void find(int uu, int sum) {
	if (uu == 2) {
		if (cnt < sum) cnt = sum;
		return;
	}
	for (int i = 0; i < A; i++) {
		if (check(uu, i)) {
			if (ap[i].u == 1) {
				find(uu + 1, sum);
			}
			else {
				ap[i].u = 1;
				find(uu + 1, sum + ap[i].p);
				ap[i].u = 0;
			}
		}
		find(uu + 1, sum);
	}
}

int solve() {
	int sum = 0;
	cnt = 0;
	find(0, 0);
	sum += cnt;
	for (int i = 0; i < M; i++) {
		user[0].x += dx[user_move[0][i]];
		user[0].y += dy[user_move[0][i]];
		user[1].x += dx[user_move[1][i]];
		user[1].y += dy[user_move[1][i]];
		cnt = 0;
		find(0, 0);
		sum += cnt;
	}
	return sum;
}

int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> M >> A;
		init();
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < M; j++) {
				cin >> user_move[i][j];
			}
		}
		for (int i = 0; i < A; i++) {
			cin >> ap[i].x >> ap[i].y >> ap[i].c >> ap[i].p;
		}
		cout << "#" << tc << ' ' << solve() << '\n';
	}
	return 0;
}