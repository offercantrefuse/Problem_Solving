#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	vector<int> b(m);
	vector<int> mer;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	
	for (int i = 0; i < n; i++) {
		mer.push_back(a[i]);
	}
	for (int i = 0; i < m; i++) {
		mer.push_back(b[i]);
	}

	sort(mer.begin(), mer.end());
	for (int i = 0; i < m + n; i++)
		cout << mer[i] << ' ';
	return 0;
}