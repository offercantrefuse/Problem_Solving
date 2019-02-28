#include <iostream>

using namespace std;

struct Node {
	char c;
	int left;
	int right;
}node[101];

void infix(int v) {
	if (node[v].left > 0)
		infix(node[v].left);
	cout << node[v].c;
	if (node[v].right > 0)
		infix(node[v].right);
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
		cout << "#" << tc << " ";
		infix(1);
		cout << endl;

	}
}