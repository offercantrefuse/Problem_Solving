#include <string>
#include <vector>
#include <set>

using namespace std;

bool check(int c, vector<int> a, vector<vector<string>> rel) {
	// unique
	int csize = rel[0].size();
	int rsize = rel.size();

	vector<string> tmp(rsize, "");
	set<string> uni;

	for (int j = 0; j < csize; j++) {
		if (c&(1 << j)) {
			for (int i = 0; i < rsize; i++) {
				tmp[i] += rel[i][j];
			}
		}
	}
	for (int i = 0; i < rsize; i++) {
		uni.insert(tmp[i]);
	}
	if (uni.size() != rsize) return false;
	else {
		// minimality
		for (int i = 0; i < a.size(); i++) {
			if ((a[i] & c) == a[i]) return false;
		}
	}
	return true;
}
int solution(vector<vector<string>> relation) {
	int answer = 0;
	int csize = relation[0].size();
	vector<int> ans;

	for (int i = 1; i < (1 << csize); i++) {
		if (check(i, ans, relation)) {
			ans.push_back(i);
		}
	}
	answer = ans.size();
	return answer;
}