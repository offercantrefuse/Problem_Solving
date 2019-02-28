#include <iostream>
#include <stack>

using namespace std;

int a[100] = { 0, }, b[100] = { 0, };
stack<int> s;
int visited[100] = { 0, };
int flag;

int dfs(int v) {
	s.push(v);
	visited[v] = 1;
	if (visited[a[v]] == 0 && a[v] != 0) {
		dfs(a[v]);
	}
	if (visited[b[v]] == 0 && b[v] != 0) {
		dfs(b[v]);
	}
	if (s.top() == 99)
		flag = 1;
	s.pop();
	return flag;
}

int main()
{
	int tc, n, w, c, d, i;

	for (tc = 1; tc <= 10; tc++) {
		cin >> n >> w;
		flag = 0;

		for (i = 0; i < w; i++) {
			cin >> c >> d;
			if (a[c] == 0)
				a[c] = d;
			else
				b[c] = d;
		}

		cout << "#" << tc << " " << dfs(0) << endl;

		for (i = 0; i < 100; i++) {
			a[i] = 0;
			b[i] = 0;
			visited[i] = 0;
		}
		while (!s.empty()) s.pop();
	}
	return 0;
}