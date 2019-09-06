#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
	int idx;
	double fail;
	node(int idx, double fail) : idx(idx), fail(fail) {}
	node() {}
};

bool cmp(node a, node b) {
	if (a.fail == b.fail) {
		return a.idx < b.idx;
	}
	return a.fail > b.fail;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<node> failure(N);
	int total = stages.size();
	//double info[200001] = { 0, };
	double info[N + 1];
	info[N] = 0.0;
	int tmp = 0;
	for (int i = 0; i < N; i++) {
		failure[i].idx = i;
		info[i] = 0.0;
	}
	for (int i = 0; i < total; i++) {
		info[stages[i] - 1]++;
	}
	for (int i = 0; i < N; i++) {
		int sum = total - tmp;
		if (sum == 0) failure[i].fail = 0;
		else failure[i].fail = info[i] / sum;
		tmp += info[i];
	}
	sort(failure.begin(), failure.end(), cmp);
	for (auto tt : failure) {
		answer.push_back(tt.idx + 1);
	}
	return answer;
}