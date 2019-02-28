#include <iostream>

using namespace std;

int flag;

struct Node {
	char c;
	int left;
	int right;
}node[201];

void test(int v) {
	if (node[v].left > 0) {
		if (node[v].c >= '0' && node[v].c <= '9') {
			flag = 0;
			return;
		}
		test(node[v].left);
	}
	else {
		if (!(node[v].c >= '0' && node[v].c <= '9')) {
			flag = 0;
			return;
		}
	}
	if (node[v].right > 0)
		test(node[v].right);
}

int main() {
	int tc, n, i, j, num;

	for (tc = 1; tc <= 10; tc++) {
		cin >> n;
		for (i = 1; i <= n; i++) {
			cin >> num;
			cin >> node[i].c;

			node[num].left = 0;
			node[num].right = 0;

			if (2 * num <= n) {
				cin >> node[i].left;
				if (2 * num + 1 <= n) {
					cin >> node[i].right;
				}
			}
		}
		flag = 1;

		cout << "#" << tc << " ";
		test(1);
		cout << flag << endl;
	}
}