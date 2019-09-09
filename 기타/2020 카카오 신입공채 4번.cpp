#include <string>
#include <vector>

using namespace std;

bool check(string s1, string s2) {
	// length check
	if (s1.length() != s2.length()) return false;
	// spell check
	int start = 0, end = s2.length() - 1;
	for (int i = 0; i < s2.length(); i++) {
		if (s2[i] == '?') {
			start = i;
			break;
		}
	}
	for (int i = s2.length() - 1; i >= 0; i--) {
		if (s2[i] == '?') {
			end = i;
			break;
		}
	}
	if (start == 0 && end == s2.length() - 1) {
		return true;
	}
	else if (start == 0) {
		if (s1.substr(end + 1, s2.length() - (end - start + 1)) == s2.substr(end + 1, s2.length() - (end - start + 1))) return true;
		else return false;
	}
	else if (end == s2.length() - 1) {
		if (s1.substr(0, s2.length() - (end - start + 1)) == s2.substr(0, s2.length() - (end - start + 1))) return true;
		else return false;
	}
}

vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer(queries.size());
	for (int i = 0; i < words.size(); i++) {
		for (int j = 0; j < queries.size(); j++) {
			if (check(words[i], queries[j]))
				answer[j]++;
		}
	}
	return answer;
}