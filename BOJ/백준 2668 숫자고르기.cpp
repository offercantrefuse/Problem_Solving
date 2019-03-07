#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int N, cnt, target, ans = 0;
bool unable;
int map[101] = { 0, };
int visit[101] = { 0, };
int checked[101] = { 0, };
vector<int> vec;
vector<int> same;
set<int> last;

void check(int idx) {  // 연결되는 node 판별
	if (checked[idx] == 1) {  // index와 같은 수는 불가
		unable = true;
		return;
	}
	vec.push_back(idx);
	visit[idx] = 1;
	if (visit[map[idx]] == 0) {
		check(map[idx]);
	}
	else if (visit[map[idx]] == 1 && map[idx] == target) { // 타겟 만나면
		return;
	}
	else if (visit[map[idx]] == 1 && map[idx] != target) { // 타겟이 아닌 다른 node 방문
		unable = true;
		return;
	}
}

int main() {
	cin >> N;
	int pp = 0;
	for (int i = 1; i <= N; i++) {
		cin >> map[i];
		if (i == map[i]) { // 번호와 같은 수 + , check 해주기
			pp++;
			same.push_back(i);
			checked[i] = 1;
		}
	}
	for (int i = 1; i <= N; i++) {
		target = i;
		cnt = 0;
		unable = false;
		memset(visit, 0, sizeof(visit));
		check(i);
		if (unable) {  // 연결 불가
			vec.clear();
			continue;
		}
		else {
			for (int i = 0; i < vec.size(); i++) {  // 연결되는 node
				last.insert(vec[i]);  // set 사용 중복제거
			}
			vec.clear();
		}
	}
	for (int i = 0; i < same.size(); i++) {
		last.insert(same[i]);
	}
	cout << last.size() << "\n";
	for (auto it = last.begin(); it != last.end(); it++) {
		cout << *it << '\n';
	}
	return 0;
}