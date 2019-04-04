#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node {
	int r, c, len;
	Node(int r, int c, int len) : r(r), c(c), len(len) {}
	Node() {}
};
int T, N, scnt, pcnt, map[10][10], ans;
Node people[10];
Node stairs[2];
int arr[10];

int simul(vector<int> vec, int length) {
	vector<int> tmp = vec;
	vector<int> use;
	int time = 0;
	if (tmp.size() == 0)
		return 0;
	while (1) {
		// tmp에 아무것도 없으면 종료
		if (tmp.size() == 0)
			break;
		// time 1씩 증가
		time++;
		// use 확인하면서 -1씩 해주고 0되면 erase
		for (int i = 0; i < use.size(); i++) {
			use[i]--;
			if (use[i] == 0) {
				use.erase(use.begin() + i);
				i--;
			}
		}
		for (int i = 0; i < tmp.size(); i++) {
			// tmp 확인하면서 -1 씩 해주고 
			if (tmp[i] > 0) {
				tmp[i]--;
			}
			// 0인 값들은 앞에서 부터 빼면서 use.size() < 3 일때 tmp에서 빼고 넣어주기
			if (tmp[i] == 0) {
				if (use.size() < 3) {
					tmp.erase(tmp.begin() + i);
					i--;
					use.push_back(length);
				}
			}
		}
	}
	return time + length;
}

void lunch() {
	vector<int> f1;
	vector<int> f2;
	for (int i = 0; i < pcnt; i++) {
		if (arr[i] == 0) f1.push_back(abs(people[i].r - stairs[0].r) + abs(people[i].c - stairs[0].c));
		else f2.push_back(abs(people[i].r - stairs[1].r) + abs(people[i].c - stairs[1].c));
	}
	sort(f1.begin(), f1.end());
	sort(f2.begin(), f2.end());
	int time1 = simul(f1, stairs[0].len);
	int time2 = simul(f2, stairs[1].len);
	int maxi = max(time1, time2);
	ans = ans > maxi ? maxi : ans;
}

void dfs(int idx) {
	if (idx == pcnt) {
		lunch();
		return;
	}
	for (int i = 0; i < 2; i++) {
		arr[idx] = i;
		dfs(idx + 1);
	}
}

int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		scnt = 0;
		pcnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				if (map[i][j] == 1)
					people[pcnt++] = Node(i, j, 0);
				else if (map[i][j] > 1) {
					stairs[scnt++] = Node(i, j, map[i][j]);
				}
			}
		}
		ans = 999999999;
		dfs(0);
		cout << '#' << tc << ' ' << ans + 1 << '\n';
	}
	return 0;
}