#include <iostream>
#define DSIZE 13
#define WSIZE 20
using namespace std;

int D, W, K;

int film[DSIZE][WSIZE];
int minchemicalCnt;
int chemical[DSIZE];

void solve(int curD, int chemicalCnt, int prevContinuum[WSIZE], int prevMaxContinuum[WSIZE]) {
	if (chemicalCnt >= minchemicalCnt) return;
	if (curD == D) {
		bool isSatisfied = true;
		for (int i = 0; i < W; i++) {
			if (prevMaxContinuum[i] < K) {
				isSatisfied = false;
				break;
			}
		}
		if (isSatisfied &&  chemicalCnt < minchemicalCnt)
			minchemicalCnt = chemicalCnt;
		return;
	}
	int continuum[WSIZE], maxContinuum[WSIZE];
	int prev, cur;

	for (int i = 2; i >= 0; i--) {
		chemical[curD] = i;
		for (int j = 0; j < W; j++) {
			cur = chemical[curD] == 2 ? film[curD][j] : chemical[curD];
			prev = chemical[curD - 1] == 2 ? film[curD - 1][j] : chemical[curD - 1];
			continuum[j] = cur == prev ? prevContinuum[j] + 1 : 1;

			if (continuum[j] > prevMaxContinuum[j]) maxContinuum[j] = continuum[j];
			else maxContinuum[j] = prevMaxContinuum[j];
		}
		solve(curD + 1, chemicalCnt + (i == 2 ? 0 : 1), continuum, maxContinuum);
	}
}

int main() {
	int tc;
	cin >> tc;
	for (int T = 1; T <= tc; T++) {
		cin >> D >> W >> K;
		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				cin >> film[i][j];
			}
		}

		minchemicalCnt = K;

		int continuum[WSIZE], maxContinuum[WSIZE];
		for (int i = 0; i < W; i++) {
			continuum[i] = maxContinuum[i] = 1;
		}

		chemical[0] = 2;
		solve(1, 0, continuum, maxContinuum);

		chemical[0] = 0;
		solve(1, 1, continuum, maxContinuum);

		chemical[0] = 1;
		solve(1, 1, continuum, maxContinuum);

		cout << "#" << T << ' ' << minchemicalCnt << endl;
	}
	return 0;
}

