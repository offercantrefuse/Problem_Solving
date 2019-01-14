#include <iostream>
#include <queue>
using namespace std;

int N, K, ans;
int visit[100001] = { 0, };

queue<int> q;

void bfs() {

	q.push(N);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (x == K)
			break;
		if (x - 1 >= 0 && visit[x - 1] == 0) {
			visit[x - 1] = visit[x] + 1;
			q.push(x - 1);
		}
		if (x + 1 <= 100000 && visit[x + 1] == 0) {
			visit[x + 1] = visit[x] + 1;
			q.push(x + 1);
		}
		if (x * 2 <= 100000 && visit[x * 2] == 0) {
			visit[x * 2] = visit[x] + 1;
			q.push(x * 2);
		}
	}
}

int main() {
	// ют╥б
	cin >> N >> K;
	// е╫╩Ж
	bfs();
	cout << visit[K] << '\n';
	return 0;
}
