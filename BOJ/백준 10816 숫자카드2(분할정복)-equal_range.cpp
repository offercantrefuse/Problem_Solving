#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int main() {
	cin >> n;	
	vector<int> a(n);
	for (int i = 0; i < n; i++) 
		scanf("%d",&a[i]);
	sort(a.begin(), a.end());
	cin >> m;
	while (m--) {
		int num;
		scanf("%d",&num);
		auto p = equal_range(a.begin(), a.end(), num);
		printf("%d ", p.second - p.first);
	}
	return 0;
}