#include <iostream>
using namespace std;
int N, B, C;
int A[1000001] = { 0, };

int main() {
	cin >> N;
	long long cnt = 0;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	cin >> B >> C;
	for (int i = 1; i <= N; i++) {
		if (A[i] <= B) {
			cnt++;
			continue;
		}
		else {
			int num = 0;
			if ((A[i] - B) % C == 0) num = (A[i] - B) / C + 1;
			else num = (A[i] - B) / C + 2;
			cnt += num;
			continue;
		}
	}
	cout << cnt;
	return 0;
}