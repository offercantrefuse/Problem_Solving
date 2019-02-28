#include <iostream>

using namespace std;

int main() {

	int testcase;
	int arr[100] = { 0 };
	int card[100][10] = { 0 };

	cin >> testcase;

	for (int T = 0; T < testcase; T++) {
		cin >> arr[T];
	}

	for (int i = 0; i < testcase; i++) {
		for (int j = 0; j < 6; j++) {
			card[i][arr[i] % 10]++;
			arr[i] /= 10;
		}

	}
	
	for (int i = 0; i < testcase; i++) {
		int tri = 0;
		int run = 0;
		for (int j = 0; j < 10; j++) {
			if (card[i][j] >= 3) {
				card[i][j] -= 3;
				tri++;
				j--;
			}
			if ((card[i][j] == 1 || card[i][j] == 2) && (card[i][j + 1] == 1 || card[i][j + 1] == 2) && (card[i][j + 2] == 1 || card[i][j + 2] == 2)) {
				card[i][j]--;
				card[i][j + 1]--;
				card[i][j + 2]--;
				run++;
				j--;
			}
		}
		if (run + tri == 2)
			cout << "BabyGin" << endl;
		else
			cout << "Lose" << endl;
	}
	
	return 0;
}
	
	