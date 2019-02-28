#include <iostream>
using namespace std;

int main() {
	int mush[10] = { 0, };
	for (int i = 0; i < 10; i++)
		cin >> mush[i];
	int cnt = 0, num = 0, ans = 0;
	bool flag = false;
	for (int i = 0; i < 10; i++) {
		cnt += mush[i];
		if (cnt > 100) {
			flag = true;
			num = i;
			cnt -= mush[i];
			break;
		}
	}
	if (flag) {
		if (100 - cnt < cnt + mush[num] - 100) cout<<cnt;
		else cout << cnt + mush[num];
	}
	else {
		cout << cnt;
	}
	return 0;
}