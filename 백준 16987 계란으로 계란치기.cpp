#include <iostream>
#include <vector>
using namespace std;
struct egg {
	int dd, ww; // 0: ¾È±úÁü , 1: ±úÁü
	egg(int dd, int ww) : dd(dd), ww(ww) {}
	egg() {}
};
int N, ans;
vector<egg> vec;

void dfs(int idx) {
	if (idx == vec.size()) {
		int cnt = 0;
		for (int i = 0; i < vec.size(); i++) {
			if (vec[i].dd <= 0) cnt++;
		}
		ans = ans < cnt ? cnt : ans;
		return;
	}
	if (vec[idx].dd <= 0) {
		dfs(idx + 1);
		return;
	}
	int num = 0;
	for (int i = 0; i < vec.size(); i++) {
		if (i == idx || vec[i].dd <= 0) {
			num++;
			continue;
		}
		vec[idx].dd -= vec[i].ww;
		vec[i].dd -= vec[idx].ww;
		dfs(idx + 1);
		vec[idx].dd += vec[i].ww;
		vec[i].dd += vec[idx].ww;
	}
	if (num == vec.size()) dfs(idx + 1);
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int duration, weight;
		cin >> duration >> weight;
		vec.push_back(egg(duration, weight));
	}
	ans = 0;
	dfs(0);
	cout << ans;
	return 0;
}