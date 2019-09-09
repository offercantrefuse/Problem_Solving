#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<string> split(string s) {
	vector<string> ans;
	int pt1 = 0, pt2 = 0, key = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') pt1++;
		else pt2++;
		if (pt1 == pt2) {
			key = i;
			break;
		}
	}
	string str1 = s.substr(0, key+1);
	string str2 = s.substr(key + 1);
	ans.push_back(str1);
	ans.push_back(str2);
	return ans;
}

bool check(string s) {
	stack<int> st;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') st.push(0);
		else {
			if (st.empty()) return false;
			st.pop();
		}
	}
	if (!st.empty()) return false;
	return true;
}

string solve(string str) {
	if (str.length() == 0) return str;
	vector<string> tmp = split(str);
	if (!check(tmp[0])) {
		string u = tmp[0];
		string aa = "(";
		string bb = solve(tmp[1]);
		aa += bb;
		aa += ")";
		string cc = u.substr(1, u.length() - 2);
		for (int i = 0; i < cc.length(); i++) {
			if (cc[i] == '(')  cc[i] = ')';
			else cc[i] = '(';
		}
		aa += cc;
		return aa;
	}
	else {
		string tt = "";
		tt += tmp[0];
		tt += solve(tmp[1]);
		return tt;
	}
}

string solution(string p) {
	string answer = "";
	string s;
	if (p.length() == 0) return answer = "";
	s = solve(p);
	return answer = s;
}