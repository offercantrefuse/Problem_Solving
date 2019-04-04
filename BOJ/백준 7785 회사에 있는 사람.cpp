#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n;
const int D = 31;
const int MOD = 1e6 + 3;
const int BUCKET_SIZE = MOD;
vector<vector<string>> hash_table(BUCKET_SIZE);
vector<string> ans;

int hash_code(string s) {
	int ret = 0;
	for (int i = 0; i < s.length(); i++) {
		ret = ((ret*D) + (int)s[i]) % MOD;
	}
	return ret;
}

void _insert(string s) {
	int tmp = hash_code(s);
	hash_table[tmp].push_back(s);
}

void _delete(string s) {
	int tmp = hash_code(s);
	for (int i = 0; i < hash_table[tmp].size(); i++) {
		if (hash_table[tmp][i] == s) {
			hash_table[tmp].erase(hash_table[tmp].begin() + i);
			break;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string name, cmd;
		cin >> name >> cmd;
		if (cmd == "enter") _insert(name);
		else _delete(name);
	}
	for (int i = 0; i < hash_table.size(); i++) {
		for (int j = 0; j < hash_table[i].size(); j++) {
			ans.push_back(hash_table[i][j]);
		}
	}
	sort(ans.begin(), ans.end());
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << '\n';
	}
	return 0;
}