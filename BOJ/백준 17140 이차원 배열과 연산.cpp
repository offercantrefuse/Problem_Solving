#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
struct node {
	int nnum, ccnt;
	node(int nnum, int ccnt) : nnum(nnum), ccnt(ccnt) {}
	node() {}
};
int r, c, k, rlen, clen, ttt;
int map[101][101];
int cnt[101];

bool cmp(node a, node b) {
	if (a.ccnt == b.ccnt) return a.nnum < b.nnum;
	return a.ccnt < b.ccnt;
}

void go(int tmp, int num) {
	if (num == 0) {
		vector<node> vec;
		for (int j = 0; j < clen; j++) {
			if (map[tmp][j] > 0) {
				cnt[map[tmp][j]]++;
				map[tmp][j] = 0;
			}
		}
		for (int k = 1; k <= 100; k++) {
			if (cnt[k] > 0)
				vec.push_back(node(k, cnt[k]));
		}
		sort(vec.begin(), vec.end(), cmp);
		int idx = 0;
		if (ttt < vec.size() * 2) ttt = vec.size() * 2;
		for (int k = 0; k < vec.size(); k++) {
			map[tmp][idx++] = vec[k].nnum;
			map[tmp][idx++] = vec[k].ccnt;
		}

	}
	else {
		vector<node> vec;
		for (int j = 0; j < rlen; j++) {
			if (map[j][tmp] > 0) {
				cnt[map[j][tmp]]++;
				map[j][tmp] = 0;
			}
		}
		for (int k = 1; k <= 100; k++) {
			if (cnt[k] > 0)
				vec.push_back(node(k, cnt[k]));
		}
		sort(vec.begin(), vec.end(), cmp);
		int idx = 0;
		if (ttt < vec.size() * 2) ttt = vec.size() * 2;
		for (int k = 0; k < vec.size(); k++) {
			map[idx++][tmp] = vec[k].nnum;
			map[idx++][tmp] = vec[k].ccnt;
		}

	}


}

void simul(int num) {
	if (num == 0) {
		for (int i = 0; i < rlen; i++) {
			memset(cnt, 0, sizeof(cnt));
			go(i, 0);
		}
	}
	else {
		for (int i = 0; i < clen; i++) {
			memset(cnt, 0, sizeof(cnt));
			go(i, 1);
		}
	}
}
int main() {
	cin >> r >> c >> k;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> map[i][j];
		}
	}
	rlen = clen = 3;
	int tt = 0;
	if (map[r - 1][c - 1] == k) {
		cout << '0';
		return 0;
	}
	while (tt <= 100) {
		if (rlen >= clen) { // 가로확장
			ttt = 0;
			simul(0);
			clen = ttt;
		}
		else {  // 세로확장
			ttt = 0;
			simul(1);
			rlen = ttt;
		}
		if (map[r - 1][c - 1] == k)
			break;
		tt++;
	}
	if (tt > 100) cout << "-1";
	else cout << tt + 1;
	return 0;
}