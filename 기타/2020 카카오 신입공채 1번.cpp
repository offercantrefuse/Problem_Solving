#include <string>
#include <vector>
#include <iostream>

using namespace std;

int cut(int len, string str) {
	string ans;
	int cnt = 1, st = 0;
	while (st < str.length()) {
		cnt = 1;
		while (st+len < str.length() && (str.substr(st, len) == str.substr(st + len, len))) {
			cnt++;
			st += len;
		}
		if (cnt == 1) ans.append(str.substr(st, len));
		else {
			ans.append(to_string(cnt));
			ans.append(str.substr(st, len));
		}
		st += len;
	}
	return ans.length();
}

int solution(string s) {
	int answer = 0;
	int max_length = s.length();
	for (int i = 1; i <= s.length(); i++) {
		int tmp = cut(i, s);
		max_length = max_length > tmp ? tmp : max_length;
	}
	answer = max_length;
	return answer;
}