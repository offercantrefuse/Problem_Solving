#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int N, K;
int map[10][10] = { 0, };
int rsp[4][20] = { 0, }; // [1] :Áö¿ì , [2]:°æÈñ, [3]:¹ÎÈ£
int cnt[4] = { 0, };
int win[4] = { 0, };
vector<vector<int>> vec;

bool can_win(int idx) {
	bool found = false;
	int p1 = 1, p2 = 2;
	for (int i = 0; i < N; i++) {
		rsp[1][i] = vec[idx][i];
	}
	while (win[1] < K && win[2] < K && win[3] < K && cnt[2] < 20 && cnt[3] < 20 && cnt[1] < N) {
		if (map[rsp[p1][cnt[p1]]][rsp[p2][cnt[p2]]] == 2) { // p1 ½Â¸®
			win[p1]++;
			cnt[p1]++;
			cnt[p2]++;
			p2 = 6 - p1 - p2; // p1 ±×´ë·Î p2 ³ª¸ÓÁö
		}
		else if (map[rsp[p1][cnt[p1]]][rsp[p2][cnt[p2]]] == 1) { // ºñ±è
			if (p1 > p2) { // p1 ½Â¸®
				win[p1]++;
				cnt[p1]++;
				cnt[p2]++;
				p2 = 6 - p1 - p2; // p1 ±×´ë·Î p2 ³ª¸ÓÁö
			}
			else { // p2 ½Â¸®
				win[p2]++;
				cnt[p1]++;
				cnt[p2]++;
				int tmp = p1;
				p1 = p2;
				p2 = 6 - tmp - p2;
			}
		}
		else { // p2 ½Â¸®
			win[p2]++;
			cnt[p1]++;
			cnt[p2]++;
			int tmp = p1;
			p1 = p2;
			p2 = 6 - tmp - p2;
		}
	}
	if (win[1] == K) return true;
	else return false;
}

int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < 20; i++)  // °æÈñ
		cin >> rsp[2][i];
	for (int i = 0; i < 20; i++)  // ¹ÎÈ£
		cin >> rsp[3][i];

	vector<int> all;	// 1~N ±îÁö ¼ö
	for (int i = 1; i <= N; i++)
		all.push_back(i);

	do {
		vec.push_back(all);  // ¼ø¿­ ´Ù ´ëÀÔ
	} while (next_permutation(all.begin(), all.end()));

	int ans = 0;
	for (int i = 0; i < vec.size(); i++) {
		if (can_win(i)) {
			ans = 1;
			break;
		}
		memset(cnt, 0, sizeof(cnt));
		memset(win, 0, sizeof(win));
	}
	cout << ans;
	return 0;
}