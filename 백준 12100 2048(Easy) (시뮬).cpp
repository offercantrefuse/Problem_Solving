#include <iostream>
#include <deque>
using namespace std;
int N, ans = 0;
int map[20][20] = { 0, };
int tmp[20][20] = { 0, };
int move_dir[5] = { 0, };

inline int maxi(int a, int b) {
	return a > b ? a : b;
}

void copy() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			tmp[i][j] = map[i][j];
		}
	}
}

void hori(int row, int dir) {
	if (dir == 0) { //right
		deque<int> st;
		int now = -1;
		for (int i = N - 1; i >= 0; i--) {
			if (tmp[row][i] == 0) continue;
			else {
				if (tmp[row][i] == now) {
					st.pop_back();
					st.push_back(now * 2);
					now = -1;
				}
				else {
					now = tmp[row][i];
					st.push_back(tmp[row][i]);
				}
			}
		}
		for (int i = N - 1; i >= 0; i--) {
			if (st.empty()) tmp[row][i] = 0;
			else {
				tmp[row][i] = st.front();
				st.pop_front();
			}
		}
	}
	else if (dir == 2) { //left
		deque<int> st;
		int now = -1;
		for (int i = 0; i < N; i++) {
			if (tmp[row][i] == 0) continue;
			else {
				if (tmp[row][i] == now) {
					st.pop_back();
					st.push_back(now * 2);
					now = -1;
				}
				else {
					now = tmp[row][i];
					st.push_back(tmp[row][i]);
				}
			}
		}
		for (int i = 0; i < N; i++) {
			if (st.empty()) tmp[row][i] = 0;
			else {
				tmp[row][i] = st.front();
				st.pop_front();
			}
		}
	}
}

void verti(int col, int dir) {
	if (dir == 1) { // up
		deque<int> st;
		int now = -1;
		for (int i = 0; i < N; i++) {
			if (tmp[i][col] == 0) continue;
			else {
				if (tmp[i][col] == now) {
					st.pop_back();
					st.push_back(now * 2);
					now = -1;
				}
				else {
					now = tmp[i][col];
					st.push_back(tmp[i][col]);
				}
			}
		}
		for (int i = 0; i < N; i++) {
			if (st.empty()) tmp[i][col] = 0;
			else {
				tmp[i][col] = st.front();
				st.pop_front();
			}
		}
	}
	else if (dir == 3) {  // down
		deque<int> st;
		int now = -1;
		for (int i = N - 1; i >= 0; i--) {
			if (tmp[i][col] == 0) continue;
			else {
				if (tmp[i][col] == now) {
					st.pop_back();
					st.push_back(now * 2);
					now = -1;
				}
				else {
					now = tmp[i][col];
					st.push_back(tmp[i][col]);
				}
			}
		}
		for (int i = N - 1; i >= 0; i--) {
			if (st.empty()) tmp[i][col] = 0;
			else {
				tmp[i][col] = st.front();
				st.pop_front();
			}
		}
	}
}

void move(int dir) {
	if (dir == 0) {
		for (int i = 0; i < N; i++) hori(i, 0);
	}
	else if (dir == 1) {
		for (int j = 0; j < N; j++) verti(j, 1);
	}
	else if (dir == 2) {
		for (int i = 0; i < N; i++) hori(i, 2);
	}
	else if (dir == 3) {
		for (int j = 0; j < N; j++) verti(j, 3);
	}
}

int count() {
	int maxnum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			maxnum = maxi(maxnum, tmp[i][j]);
		}
	}
	return maxnum;
}

void dfs(int idx) {
	if (idx == 5) {
		copy();
		for (int i = 0; i < 5; i++) move(move_dir[i]);
		ans = maxi(ans, count());
		return;
	}
	for (int i = 0; i < 4; i++) {
		move_dir[idx] = i;
		dfs(idx + 1);
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	dfs(0);
	cout << ans;
	return 0;
}