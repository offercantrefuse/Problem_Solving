#include <iostream>

using namespace std;

int main() {

	// ют╥б
	int T, N, M;
	int H[100] = { 0 };
	int max = 0;

	cin >> T;

	for (int i = 0; i < T; i++) {

		cin >> N;
		cin >> M;

		for (int i = 0; i < N; i++) {
			cin >> H[i];
		}

		int arr[100][100] = { 0 };
		for (int j = 0; j < N; j++) {
			for (int i = 0; i < H[j]; i++) {
				arr[i][j] = 1;
			}
		}
		
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				int cnt = 0;
				if (arr[i][j] == 1) {
					for (int k = j + 1; k < N; k++) {
						if (arr[i][k] == 0) {
							cnt++;
						}
					}
					if (max < cnt) {
						max = cnt;
					}
					break;
				}
			}
		}

		cout << max << endl;
		return 0;
	}
}