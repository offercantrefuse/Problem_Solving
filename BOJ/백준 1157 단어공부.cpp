#include <iostream>
#include <string>
using namespace std;

int alpha[26] = { 0, };
int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (isupper(s[i])) {
			alpha[s[i] - 'A']++;
		}
		else {
			alpha[s[i] - 'a']++;
		}
	}
	int maxi = 0, idx = 0, cnt = 0;
	for (int i = 0; i < 26; i++) {
		if (maxi < alpha[i]) {
			maxi = alpha[i];
			idx = i;
		}
	}
	for (int i = 0; i < 26; i++) {  // 중복 체크
		if (alpha[i] == maxi)
			cnt++;
	}
	if (cnt > 1) cout << '?';
	else cout << char(idx + 'A');
	return 0;
}