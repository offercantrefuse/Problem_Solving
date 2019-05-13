#include <iostream>
using namespace std;
int N, M, sum = 0, cnt;
bool visit[1001];
int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int tmp, cnt = 1;
		cin >> tmp;
		while (tmp*cnt <= N) {
			if (!visit[tmp*cnt]) {
				sum += tmp * cnt;
				visit[tmp*cnt] = true;
			}
			cnt++;
		}
	}
	cout << sum << '\n';
	return 0;
}
