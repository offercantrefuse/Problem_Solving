#include <iostream>
using namespace std;

int N;
int map[20][20];
bool visit[101];
int result;

void visitClear() {
	for (int j = 0; j <= 101; j++) {
		visit[j] = false;
	}
}

void init() {
	visitClear();
	result = -1;
}

void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int a = 1; a < N; a++) {
				for (int b = 1; b < N; b++) {
					if (j + a <= N - 1 && i + a + b <= N - 1 && j - b >= 0 && (a + b) * 2 > result) {
						visitClear();
						bool isAble = true;
						int curi = i, curj = j;

						for (int n = 0; n < a; n++) {
							curi++; curj++;
							if (!visit[map[curi][curj]]) {
								visit[map[curi][curj]] = true;
							}
							else {
								isAble = false;
								break;
							}
						}
						if (!isAble) continue;

						for (int n = 0; n < b; n++) {
							curi++; curj--;
							if (!visit[map[curi][curj]]) {
								visit[map[curi][curj]] = true;
							}
							else {
								isAble = false;
								break;
							}
						}
						if (!isAble) continue;


						for (int n = 0; n < a; n++) {
							curi--; curj--;
							if (!visit[map[curi][curj]]) {
								visit[map[curi][curj]] = true;
							}
							else {
								isAble = false;
								break;
							}
						}
						if (!isAble) continue;

						for (int n = 0; n < b; n++) {
							curi--; curj++;
							if (!visit[map[curi][curj]]) {
								visit[map[curi][curj]] = true;
							}
							else {
								isAble = false;
								break;
							}
						}
						if (!isAble) continue;

						result = 2 * (a + b);
					}
				}
			}
		}
	}
}

int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		init();

		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		solve();

		cout << "#" << t << ' ' << result << endl;
	}
	return 0;
}
