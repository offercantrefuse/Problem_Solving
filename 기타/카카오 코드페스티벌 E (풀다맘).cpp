#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, k, j;
int cnt;
int t, p, s;
int singer[100001] = { 0, };
int ans[100001] = { 0, };
struct node {
	int num;
	int singer_num;
	int left;
	int right;
};

int go(vector<node> &tree, int num) {
	if (tree[num].left) {
		go(tree, tree[num].left);
		cnt++;
	}
	if (tree[num].right) {
		go(tree, tree[num].right);
		cnt++;
	}
	return cnt;
}

void give(vector<node> &tree, int num) {
	singer[num] += (s/go(tree,num));
	if (tree[num].left) {
		give(tree, tree[num].left);
	}
	if (tree[num].right) {
		give(tree, tree[num].right);
	}
}

int main() {
	cin >> n >> k >> j;
	vector<node> tree(n+1);
	for (int i = 2; i < n+1; i++) {
		int tmp;
		cin >> tmp;
		if (tree[tmp].left) {
			tree[tmp].left = i;
		}
		else {
			tree[tmp].right = i;
		}
	}
	for (int i = 1; i <= n; i++) {
		cin >> tree[i].singer_num;
	}
	for (int i = 0; i < 100001; i++) {
		ans[i] = -1;
	}
	for (int i = 0; i < k; i++) {
		cnt = 1;
		cin >> t >> p >> s;
		give(tree, p);
		for (int h = 1; h < n + 1; h++) {
			if (singer[tree[h].singer_num] >= j) {
				ans[h] = t;
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		cout << ans[i]<<'\n';
	}
	return 0;
}