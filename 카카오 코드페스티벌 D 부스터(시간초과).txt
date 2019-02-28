#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define mini(a,b) ((a<b)?a:b)
using namespace std;
int n, q;
vector<pair<int, int>> check;
int visited[250000] = { 0, };
bool flag = false;

double dist(int a, int b) {
	return sqrt((check[a].first - check[b].first)*(check[a].first - check[b].first) - (check[a].second - check[b].second)*(check[a].second - check[b].second));
}

bool cango(int from, int to, int hp) {
	if ((check[from].first - check[to].first) == 0 || check[from].second - check[to].second == 0) {
		return true;
	}
	else {
		if (mini(abs(check[from].first - check[to].first), abs(check[from].second - check[to].second)) <= hp) {
			return true;
		}
		else
			return false;
	}
}

void find(int from, int to, int hp) {
	if (from == to) {
		flag = true;
		return;
	}
	visited[from] = 1;
	for (int i = 0; i < n; i++) {
		if (visited[i] == 0) {
			if (cango(from, i, hp)) {
				find(i, to, hp);
			}
		}
	}
}

int main() {
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		check.push_back(make_pair(x, y));
	}
	for (int i = 0; i < q; i++) {
		int checkA, checkB, HP;
		cin >> checkA >> checkB >> HP;
		flag = false;
		find(checkA - 1, checkB - 1, HP);
		if (flag) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
		for (int j = 0; j < 250000; j++) {
			visited[i] = 0;
		}
	}
	return 0;
}