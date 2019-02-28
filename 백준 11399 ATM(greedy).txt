#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a;
	//vector<int> b[1000];
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	sort(a.begin(), a.end());
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i] * (n-i);
	}
	cout << sum << '\n';	
}