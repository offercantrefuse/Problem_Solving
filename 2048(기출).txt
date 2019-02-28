#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N;
int map[5][20][20] = { 0, };
int ans;

void move(int br, int dir) { // 0 up 1 right 2 under 3 left
	if (dir == 0) {
		for (int j = 0; j < N; j++) {
			queue<int> tmp;
			vector<int> vec;
			vector<int> res;
			for (int i = 0; i < N; i++) {
				tmp.push(map[br][i][j]);
			}
			for (int i = 0; i < N; i++) {
				if (tmp.front() == 0) {
					tmp.pop();
				}
				else {
					vec.push_back(tmp.front());
					tmp.pop();
				}
			}
			int save;
			for (int i = 0; i < vec.size(); i++) {
				save = vec.at(i);
				if (i != vec.size() - 1) {
					if (vec.at(i + 1) == save) {
						res.push_back(2 * save);
						i++;
						continue;
					}
				}
				res.push_back(save);
			}
			for (int a = 0; a < N; a++) {
				map[br + 1][a][j] = 0;
			}
			for (int i = 0; i < res.size(); i++) {
				map[br + 1][i][j] = res.at(i);
			}
			while (!tmp.empty()) tmp.pop();
			vec.clear();
			res.clear();
		}
	}
	else if (dir == 1) {
		for (int i = 0; i < N; i++) {
			queue<int> tmp;
			vector<int> vec;
			vector<int> res;
			for (int j = N - 1; j >= 0; j--) {
				tmp.push(map[br][i][j]);
			}
			for (int i = 0; i < N; i++) {
				if (tmp.front() == 0) {
					tmp.pop();
				}
				else {
					vec.push_back(tmp.front());
					tmp.pop();
				}
			}
			int save;
			for (int i = 0; i < vec.size(); i++) {
				save = vec.at(i);
				if (i != vec.size() - 1) {
					if (vec.at(i + 1) == save) {
						res.push_back(2 * save);
						i++;
						continue;
					}
				}
				res.push_back(save);
			}
			for (int b = 0; b < N; b++) {
				map[br+1][i][b] = 0;
			}
			int cnt = N - 1;
			for (int j = 0; j < res.size(); j++) {
				map[br+1][i][cnt--] = res.at(j);
			}
			while (!tmp.empty()) tmp.pop();
			vec.clear();
			res.clear();
		}
	}
	else if (dir == 2) {
		for (int j = 0; j < N; j++) {
			queue<int> tmp;
			vector<int> vec;
			vector<int> res;
			for (int i = N - 1; i >= 0; i--) {
				tmp.push(map[br][i][j]);
			}
			for (int i = 0; i < N; i++) {
				if (tmp.front() == 0) {
					tmp.pop();
				}
				else {
					vec.push_back(tmp.front());
					tmp.pop();
				}
			}
			int save;
			for (int i = 0; i < vec.size(); i++) {
				save = vec.at(i);
				if (i != vec.size() - 1) {
					if (vec.at(i + 1) == save) {
						res.push_back(2 * save);
						i++;
						continue;
					}
				}
				res.push_back(save);
			}
			for (int a = 0; a < N; a++) {
				map[br + 1][a][j] = 0;
			}
			int cnt = N - 1;
			for (int i = 0; i < res.size(); i++) {
				map[br + 1][cnt--][j] = res.at(i);
			}
			while (!tmp.empty()) tmp.pop();
			vec.clear();
			res.clear();
		}
	}
	else if (dir == 3) {
		for (int i = 0; i < N; i++) {
			queue<int> tmp;
			vector<int> vec;
			vector<int> res;
			for (int j = 0; j < N; j++) {
				tmp.push(map[br][i][j]);
			}
			for (int i = 0; i < N; i++) {
				if (tmp.front() == 0) {
					tmp.pop();
				}
				else {
					vec.push_back(tmp.front());
					tmp.pop();
				}
			}
			int save;
			for (int i = 0; i < vec.size(); i++) {
				save = vec.at(i);
				if (i != vec.size() - 1) {
					if (vec.at(i + 1) == save) {
						res.push_back(2 * save);
						i++;
						continue;
					}
				}
				res.push_back(save);
			}
			for (int b = 0; b < N; b++) {
				map[br + 1][i][b] = 0;
			}
			for (int j = 0; j < res.size(); j++) {
				map[br + 1][i][j] = res.at(j);
			}
			while (!tmp.empty()) tmp.pop();
			vec.clear();
			res.clear();
		}
	}
}

void dfs(int pos, int cnt) {
	if (cnt == 0) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ans = (map[pos][i][j] > ans) ? map[pos][i][j] : ans;
			}
		}
	}
	else {
		for (int k = 0; k < 4; k++) {
			move(pos++, k);      // È¸Àü
			dfs(pos, --cnt);
			pos--;
			++cnt;
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[0][i][j];
		}
	}

	ans = 0;
	dfs(0,5);

	cout << ans << endl;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[0][i][j] = 0;
		}
	}
	return 0;
}