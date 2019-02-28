#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int num[11] = { 0, };
int n;
int act(int a,int b, int c) {
	if (c == 0) return a + b;
	if (c == 1) return a - b;
	if (c == 2) return a * b;
	if (c == 3) return a / b;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> num[i];	
	vector<int> op;
	for (int i = 0; i < 4; i++) {
		int tmp;
		cin >> tmp;
		for (int j = 0; j < tmp; j++) op.push_back(i);
	}
	int maxi = -1000000000;
	int mini = 1000000000;
	do { 
		int cnt = num[0];
		for (int i = 0; i < n-1; i++) {
			cnt = act(cnt, num[i + 1], op[i]);
		}
		maxi = maxi > cnt ? maxi : cnt;
		mini = mini < cnt ? mini : cnt;
	} while (next_permutation(op.begin(),op.end()));
	cout << maxi << '\n' << mini;
	return 0;
}