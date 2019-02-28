#include <iostream>
#include <string>

using namespace std;

struct Node {
	int val;
	string str;
	int left;
	int right;
}node[1001];

int calc(int v) {
	if (node[v].left > 0)
		calc(node[v].left);
	if (node[v].right > 0)
		calc(node[v].right);
	if (node[v].str == "+") {
		node[v].val = node[node[v].left].val + node[node[v].right].val;
	}
	else if (node[v].str == "-") {
		node[v].val = node[node[v].left].val - node[node[v].right].val;
	}
	else if (node[v].str == "*") {
		node[v].val = node[node[v].left].val * node[node[v].right].val;
	}
	else if (node[v].str == "/") {
		node[v].val = node[node[v].left].val / node[node[v].right].val;
	}
	return node[v].val;
}

int main() {
	int tc, n, i, num;

	for (tc = 1; tc <= 10; tc++) {
		cin >> n;
		for (i = 1; i <= n; i++) {
			cin >> num;
			cin >> node[num].str;

			node[num].left = 0;
			node[num].right = 0;

			if (node[num].str == "+" || node[num].str == "-" || node[num].str == "*" || node[num].str == "/") {
				cin >> node[num].left >> node[num].right;
			}
			else
				node[num].val = stoi(node[num].str);
		}
		cout << "#" << tc << " ";
		cout << calc(1);
		cout << endl;
	}
	return 0;
}