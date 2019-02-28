#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
int visit[201][201] = { 0, };
int a, b, c, sum = 0;
int na, nb, nc = 0;
struct node {
	int a, b;
	node(int aa, int bb) {
		a = aa;
		b = bb;
	}
};
queue<node> q;
set<int> ans;
int main() {
	cin >> a >> b >> c;
	sum = c;
	q.push(node(0, 0));
	while (!q.empty()) {
		na = q.front().a;
		nb = q.front().b;
		nc = sum - na - nb;
		if (na == 0) ans.insert(nc);
		visit[na][nb] = 1;
		q.pop();
		int x = na, y = nb, z= nc;
		// a->b
		if (x != 0) {
			if (x <= b - y) {
				y += x;
				x = 0;
			}
			else {
				x -= b - y;
				y = b;
			}
			if (visit[x][y] == 0) {
				q.push(node(x, y));
			}
		}
		// b->a
		x = na, y = nb, z = nc;
		if (y != 0) {
			if (y <= a - x) {
				x += y;
				y = 0;
			}
			else {
				y -= a - x;
				x = a;
			}
			if (visit[x][y] == 0) {
				q.push(node(x, y));
			}
		}
		// a->c
		x = na, y = nb, z = nc;
		if (x != 0) {
			if (x <= c - z) {
				z += x;
				x = 0;
			}
			else {
				x -= c - z;
				z = c;
			}
			if (visit[x][y] == 0) {
				q.push(node(x, y));
			}
		}
		// c->a
		x = na, y = nb, z = nc;
		if (z != 0) {
			if (z <= a - x) {
				x += z;
				z = 0;
			}
			else {
				z -= a - x;
				x = a;
			}
			if (visit[x][y] == 0) {
				q.push(node(x, y));
			}
		}
		// b->c
		x = na, y = nb, z = nc;
		if (y != 0) {
			if (y <= c - z) {
				z += y;
				y = 0;
			}
			else {
				y -= c - z;
				z = c;
			}
			if (visit[x][y] == 0) {
				q.push(node(x, y));
			}
		}
		// c->b
		x = na, y = nb, z = nc;
		if (z != 0) {
			if (z <= b - y) {
				y += z;
				z = 0;
			}
			else {
				z -= b - y;
				y = b;
			}
			if (visit[x][y] == 0) {
				q.push(node(x, y));
			}
		}
	}
	for (auto t : ans) {
		cout << t << ' ';
	}
	return 0;
}