#include <iostream>
using namespace std;

typedef struct {
	int k;
	int t;
}cus;

typedef struct {
	int idx;
	int k;
	int t;
}prc;

const int MAXS = 9;
const int MAXK = 1000;
int a[MAXS + 1];
int b[MAXS + 1];
cus rec[MAXS + 1];
cus rep[MAXS + 1];
cus recq[MAXK];
prc repq[MAXK];
int crp;
int pwp, prp;
int tc, T;
int N, M, K, A, B;

void _sort(cus arr[], int from, int to) {
	for (int i = from; i < to; i++) {
		for (int j = i + 1; j <= to; j++) {
			if (arr[i].t > arr[j].t || (arr[i].t == arr[j].t && arr[i].k > arr[j].k)) {
				cus temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

}

int solve(void) {
	int ans = 0;
	crp = 0;
	pwp = 0;
	prp = 0;
	_sort(recq, 0, K - 1);

	for (int cnt = 1, time = recq[0].t; cnt <= K; ++time) {
		for (int i = 1; i <= N; i++) {
			if (rec[i].t > 0) {
				if (--rec[i].t == 0) {
					repq[pwp++] = { i,rec[i].k,time };
				}
			}

			if (rec[i].t == 0) {
				if (crp < K && recq[crp].t <= time) {
					cus customer = recq[crp++];
					rec[i] = { customer.k,a[i] };
				}
			}
		}

		for (int i = 1; i <= M; i++) {
			if (rep[i].t > 0) {
				if (--rep[i].t == 0) {
					++cnt;
				}
			}

			if (rep[i].t == 0) {
				if (prp < pwp) {
					prc prc = repq[prp++];
					rep[i] = { prc.k,b[i] };
					if (prc.idx == A && i == B) ans += prc.k;
				}
			}
		}
	}
	if (ans == 0)
		return -1;
	else
		return ans;
}

int main(void) {
	cin >> T;
	for (tc = 1; tc <= T; tc++) {
		cin >> N >> M >> K >> A >> B;
		for (int i = 1; i <= N; i++) {
			cin >> a[i];
		}
		for (int i = 1; i <= M; i++) {
			cin >> b[i];
		}
		for (int i = 0; i < K; i++) {
			cin >> recq[i].t;
			recq[i].k = i + 1;
		}
		cout << "#" << tc << ' ' << solve() << endl;
	}
	return 0;
}