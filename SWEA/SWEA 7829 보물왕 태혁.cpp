#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T, P;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> P;
		int num[P];
		for (int i = 0; i < P; i++) {
			cin >> num[i];
		}
		sort(num, num + P);
		cout << "#" << tc << " " << num[0] * num[P - 1] << '\n';
	}
	return 0;
}