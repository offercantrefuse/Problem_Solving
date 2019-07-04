#include <iostream>
#include <cstring>
using namespace std;

bool cmp(int a[26], int b[26]) {
	for (int i = 0; i < 26; i++) {
		if (a[i] != b[i]) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		string s1, s2;
		int ans = 0;
		cin >> s1 >> s2;
		int c[26] = { 0, };
		for (auto ch : s1) {
			c[ch - 'a']++;
		}
		int tmp[26] = { 0, };
		for (int i = 0; i < s1.length(); i++) {
			tmp[s2[i] - 'a']++;
		}
		if (cmp(c, tmp)) ans++;
		int pt1 = 0;
		for (int i = s1.length(); i < s2.length(); i++) {
			tmp[s2[pt1++] - 'a']--;
			tmp[s2[i] - 'a']++;
			if (cmp(c, tmp)) ans++;
		}
		cout << "#" << tc << " " << ans << '\n';
	}

	return 0;
}