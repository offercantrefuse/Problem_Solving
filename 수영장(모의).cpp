#include <iostream>
using namespace std;
int mini = 1 << 30;
int cost_table[4] = { 0, };
int plan[13] = { 0, };

void Search(int month, int cost) {
	if (month >= 12) {
		if (cost < mini)
			mini = cost;
		return;
	}
	Search(month + 1, cost + cost_table[0] * plan[month]);
	Search(month + 1, cost + cost_table[1]);
	Search(month + 3, cost + cost_table[2]);
	Search(month + 12, cost + cost_table[3]);
}

int main() {
	int t = 0;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		mini = 1 << 30;

		for (int j = 0; j < 4; j++)
			cin >> cost_table[j];
		for (int j = 0; j < 12; j++)
			cin >> plan[j];
		Search(0, 0);
		cout << "#" << tc << ' ' << mini << endl;
	}
	return 0;
}

