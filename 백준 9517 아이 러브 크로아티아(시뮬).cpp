#include <iostream>
#include <queue>
using namespace std;
struct cmd {
	int time;
	char command;
	cmd(int tt, char cc) {
		time = tt;
		command = cc;
	}
};
int k, n;
void next() {
	if (k == 8)	k = 1;
	else k++;
}
queue<cmd> c;
int main() {
	int bomb = 210;
	cin >> k >> n;
	for (int i = 0; i < n; i++) {
		int tmp1;
		char tmp2;
		cin >> tmp1 >> tmp2;
		c.push(cmd(tmp1, tmp2));
	}
	while (bomb > 0 && !c.empty()) {
		if (bomb - c.front().time <= 0) {
			break;
		}
		if (c.front().command == 'T') {
			bomb -= c.front().time;
			c.pop();
			next();
		}
		else {
			bomb -= c.front().time;
			c.pop();
		}
	}
	cout << k;
	return 0;
}