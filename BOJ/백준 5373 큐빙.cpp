#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int T, n;
char up[3][3], down[3][3], rt[3][3], lt[3][3], back[3][3], front[3][3];

void init() {
	for (int i = 0; i < 3; i++) {
		memset(up[i], 'w', sizeof(up[i]));
		memset(down[i], 'y', sizeof(down[i]));
		memset(rt[i], 'b', sizeof(rt[i]));
		memset(lt[i], 'g', sizeof(lt[i]));
		memset(back[i], 'o', sizeof(back[i]));
		memset(front[i], 'r', sizeof(front[i]));
	}
}

void turn_clock(char a[][3]) {
	char tmp;
	tmp = a[0][0];
	a[0][0] = a[2][0];
	a[2][0] = a[2][2];
	a[2][2] = a[0][2];
	a[0][2] = tmp;
	tmp = a[0][1];
	a[0][1] = a[1][0];
	a[1][0] = a[2][1];
	a[2][1] = a[1][2];
	a[1][2] = tmp;
}

void turn_counterclock(char a[][3]) {
	char tmp;
	tmp = a[0][0];
	a[0][0] = a[0][2];
	a[0][2] = a[2][2];
	a[2][2] = a[2][0];
	a[2][0] = tmp;
	tmp = a[0][1];
	a[0][1] = a[1][2];
	a[1][2] = a[2][1];
	a[2][1] = a[1][0];
	a[1][0] = tmp;
}

void simul(string s) {
	char tmp[3];
	if (s == "L-") {
		// 왼쪽 줄
		for (int i = 0; i < 3; i++)
			tmp[i] = up[i][0];
		for (int i = 0; i < 3; i++)
			up[i][0] = front[i][0];
		for (int i = 0; i < 3; i++)
			front[i][0] = down[i][0];
		for (int i = 0; i < 3; i++)
			down[i][0] = back[i][0];
		for (int i = 0; i < 3; i++)
			back[i][0] = tmp[i];

		// 왼쪽 면 
		turn_counterclock(lt);
	}
	else if (s == "L+") {
		// 왼쪽 줄
		for (int i = 0; i < 3; i++)
			tmp[i] = up[i][0];
		for (int i = 0; i < 3; i++)
			up[i][0] = back[i][0];
		for (int i = 0; i < 3; i++)
			back[i][0] = down[i][0];
		for (int i = 0; i < 3; i++)
			down[i][0] = front[i][0];
		for (int i = 0; i < 3; i++)
			front[i][0] = tmp[i];
		// 왼쪽 면
		turn_clock(lt);
	}
	else if (s == "R-") {
		// 오른쪽 줄
		for (int i = 0; i < 3; i++)
			tmp[i] = up[i][2];
		for (int i = 0; i < 3; i++)
			up[i][2] = back[i][2];
		for (int i = 0; i < 3; i++)
			back[i][2] = down[i][2];
		for (int i = 0; i < 3; i++)
			down[i][2] = front[i][2];
		for (int i = 0; i < 3; i++)
			front[i][2] = tmp[i];
		// 오른쪽 면
		turn_counterclock(rt);
	}
	else if (s == "R+") {
		// 오른쪽 줄
		for (int i = 0; i < 3; i++)
			tmp[i] = up[i][2];
		for (int i = 0; i < 3; i++)
			up[i][2] = front[i][2];
		for (int i = 0; i < 3; i++)
			front[i][2] = down[i][2];
		for (int i = 0; i < 3; i++)
			down[i][2] = back[i][2];
		for (int i = 0; i < 3; i++)
			back[i][2] = tmp[i];
		// 오른쪽 면
		turn_clock(rt);
	}
	else if (s == "U-") {
		// 위쪽 줄
		for (int i = 0; i < 3; i++)
			tmp[i] = front[0][i];
		for (int i = 0; i < 3; i++)
			front[0][i] = lt[0][i];
		for (int i = 0; i < 3; i++)
			lt[0][i] = back[2][2 - i];
		for (int i = 0; i < 3; i++)
			back[2][i] = rt[0][2 - i];
		for (int i = 0; i < 3; i++)
			rt[0][i] = tmp[i];
		// 위쪽 면
		turn_counterclock(up);
	}
	else if (s == "U+") {
		// 위쪽 줄
		for (int i = 0; i < 3; i++)
			tmp[i] = front[0][i];
		for (int i = 0; i < 3; i++)
			front[0][i] = rt[0][i];
		for (int i = 0; i < 3; i++)
			rt[0][i] = back[2][2 - i];
		for (int i = 0; i < 3; i++)
			back[2][2 - i] = lt[0][i];
		for (int i = 0; i < 3; i++)
			lt[0][i] = tmp[i];
		// 위쪽 면
		turn_clock(up);
	}
	else if (s == "D-") {
		// 아래 줄
		for (int i = 0; i < 3; i++)
			tmp[i] = front[2][i];
		for (int i = 0; i < 3; i++)
			front[2][i] = rt[2][i];
		for (int i = 0; i < 3; i++)
			rt[2][i] = back[0][2 - i];
		for (int i = 0; i < 3; i++)
			back[0][2 - i] = lt[2][i];
		for (int i = 0; i < 3; i++)
			lt[2][i] = tmp[i];
		// 아래 면
		turn_counterclock(down);
	}
	else if (s == "D+") {
		// 아래 줄
		for (int i = 0; i < 3; i++)
			tmp[i] = front[2][i];
		for (int i = 0; i < 3; i++)
			front[2][i] = lt[2][i];
		for (int i = 0; i < 3; i++)
			lt[2][i] = back[0][2 - i];
		for (int i = 0; i < 3; i++)
			back[0][2 - i] = rt[2][i];
		for (int i = 0; i < 3; i++)
			rt[2][i] = tmp[i];
		// 아래 면
		turn_clock(down);
	}
	else if (s == "B-") {
		// 뒷 줄
		for (int i = 0; i < 3; i++)
			tmp[i] = up[0][i];
		for (int i = 0; i < 3; i++)
			up[0][i] = lt[2 - i][0];
		for (int i = 0; i < 3; i++)
			lt[i][0] = down[2][i];
		for (int i = 0; i < 3; i++)
			down[2][i] = rt[2 - i][2];
		for (int i = 0; i < 3; i++)
			rt[i][2] = tmp[i];
		// 뒷 면
		turn_counterclock(back);
	}
	else if (s == "B+") {
		// 뒷 줄
		for (int i = 0; i < 3; i++)
			tmp[i] = up[0][i];
		for (int i = 0; i < 3; i++)
			up[0][i] = rt[i][2];
		for (int i = 0; i < 3; i++)
			rt[i][2] = down[2][2 - i];
		for (int i = 0; i < 3; i++)
			down[2][i] = lt[i][0];
		for (int i = 0; i < 3; i++)
			lt[i][0] = tmp[2 - i];
		// 뒷 면
		turn_clock(back);
	}
	else if (s == "F-") {
		// 앞 줄
		for (int i = 0; i < 3; i++)
			tmp[i] = up[2][i];
		for (int i = 0; i < 3; i++)
			up[2][i] = rt[i][0];
		for (int i = 0; i < 3; i++)
			rt[i][0] = down[0][2 - i];
		for (int i = 0; i < 3; i++)
			down[0][i] = lt[i][2];
		for (int i = 0; i < 3; i++)
			lt[i][2] = tmp[2 - i];
		// 앞 면
		turn_counterclock(front);
	}
	else if (s == "F+") {
		// 앞 줄
		for (int i = 0; i < 3; i++)
			tmp[i] = up[2][i];
		for (int i = 0; i < 3; i++)
			up[2][i] = lt[2 - i][2];
		for (int i = 0; i < 3; i++)
			lt[i][2] = down[0][i];
		for (int i = 0; i < 3; i++)
			down[0][i] = rt[2 - i][0];
		for (int i = 0; i < 3; i++)
			rt[i][0] = tmp[i];
		// 앞 면
		turn_clock(front);
	}
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> n;
		init();
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			simul(s);
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << up[i][j];
			}
			cout << '\n';
		}
	}
	return 0;
}