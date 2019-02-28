#include <iostream>
#include <string>
#include <set>
#include <cmath>
#include <vector>
using namespace std;

int ston(char c) {
	if (c >= '0' && c <= '9') return c -= '0';
	else return c -= 'A' - 10;
}

int conv(string str, int leng) {
	int sum = 0;
	for (int i = 0; i < leng; i++) {
		sum += ston(str[i]) * (int)pow(16, leng - 1 - i);
	}
	return sum;
}

int main() {
	int n, k, t;
	string s;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n >> k >> s;
		string tmp;
		int length = n / 4;
		tmp = s.substr(0, length - 1);
		s.append(tmp);
		set<int> pool;
		for (int i = 0; i < n; i++) {
			pool.insert(conv(s.substr(i, length), length));
		}
		vector<int> vec;
		for (int t : pool) {
			vec.push_back(t);
		}
		cout << "#" << tc << ' ' << vec[vec.size() - k] << '\n';
	}
	return 0;
}