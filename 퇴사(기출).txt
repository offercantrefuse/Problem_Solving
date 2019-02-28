#include <iostream>
using namespace std;
int N;
int maxi;
int T[16] = { 0, }, P[16] = { 0, };

int search(int day, int cost) {
	if (day > N) {
		maxi = (cost > maxi) ? cost : maxi;
		return maxi;
	}
	if (day + T[day] <= N+1)
		search(day + T[day], cost + P[day]);
	search(day + 1, cost);
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
	}
	maxi = 0;
	cout << search(1, 0) << endl;

	return 0;
}