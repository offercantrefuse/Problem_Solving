#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string word, cp;
void sol(int a, int b) {
	reverse(cp.begin(), cp.begin() + a);
	reverse(cp.begin() + a, cp.begin() + b);
	reverse(cp.begin() + b, cp.end());  // end +1 ??
}
int main() {
	string ans;
	cin >> word;
	for (int i = 1; i < word.length() - 1; i++) {
		for (int j = 2; j < word.length(); j++) {
			cp = word;
			if (i == 1 && j == 2) {
				sol(i, j);
				ans = cp;
			}
			else if (i < j) {
				sol(i, j);
				ans = cp < ans ? cp : ans;
			}
		}
	}
	cout << ans;
	return 0;
}