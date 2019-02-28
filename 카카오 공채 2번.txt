#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<double, int> a, pair<double, int> b) {
	if (a.first == b.first) return a.second < b.second;
	else return a.first > b.first;
}
vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<double> failure(N + 1);
	for (int i = 0; i <= N; i++) failure[i] = 0;
	for (int i = 1; i <= N; i++) {
		double cnt = 0;
		double fail_cnt = 0;
		for (int j = 0; j < stages.size(); j++) {
			if (stages[j] >= i) {
				cnt++;
			}
			if (stages[j] == i) {
				fail_cnt++;
			}
		}
		if (cnt == 0) failure[i] = 0;
		else { failure[i] = fail_cnt / cnt; }
	}
	vector<pair<double, int>> sol(N + 1);
	for (int i = 1; i <= N; i++) {
		sol[i].first = failure[i];
		sol[i].second = i;
	}
	sort(sol.begin() + 1, sol.end(), cmp);
	for (int i = 1; i <= N; i++) {
		answer.push_back(sol[i].second);
	}
	return answer;
}
