#include <iostream>
using namespace std;
int v, top, cnt;
int par[10000];

struct node {
	int left;
	int right;
	int num;
}node[10000];

void find_parent(int k) {
	for (int i = 0; i <= v; i++) {
		if (node[i].left == k || node[i].right == k) {
			par[++top] = i;
			if (i == 1)
				break;
			find_parent(i);
			break;
		}
	}
}

void subcnt(int k) {
	if (node[k].left != 0) {
		cnt++;
		subcnt(node[k].left);
	}
	if (node[k].right != 0) {
		cnt++;
		subcnt(node[k].right);
	}
}

int main() {
	int tc, e;
	int x, y;

	cin >> tc;
	for (int t = 0; t < tc; t++) {
		cin >> v;
		cin >> e;
		cin >> x >> y;

		for (int i = 0; i <= v; i++) {
			node[i].num = i;
		}
		for (int i = 0; i < e; i++) {
			int parent, child;;
			cin >> parent >> child;
			if (node[parent].left == 0)
				node[parent].left = child;
			else
				node[parent].right = child;
		}

		/*for (int i = 0; i <= v; i++) {
			cout << node[i].left << ' ';
		}*/

		top = -1;
		par[++top] = x;
		find_parent(x);
		int parx[10000] = { 0, };
		int topx = -1;
		while (top!=-1) {
			parx[++topx] = par[top];
			par[top--] = 0;
		}

		par[++top] = y;
		find_parent(y);
		int pary[10000] = { 0, };
		int topy = -1;
		while (top!=-1) {
			pary[++topy] = par[top];
			par[top--] = 0;
		}

		int ans = 0;

		for (int i = 0; i <= topx; i++) {
			for (int j = 0; j <= topy; j++) {
				if (parx[i] == pary[j]) {
					ans = parx[i];
				}
			}
		}
		
		cnt = 1;
		subcnt(ans);

		for (int i = 0; i <= v; i++) {
			node[i].num = 0;
			node[i].left = 0;
			node[i].right = 0;
		}

		cout << "#" << t + 1 << ' ' << ans << ' ' << cnt << endl;
	}
	return 0;
}