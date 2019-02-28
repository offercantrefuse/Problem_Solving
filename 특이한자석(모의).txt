#include <iostream>
using namespace std;

struct mag {
	int arr[8];
}mag[4];

void rot(int m, int d) {
	if (d == 1) {
		int tmp1 = mag[m].arr[7];
		for (int i = 7; i >= 1; i--) {
			mag[m].arr[i] = mag[m].arr[i - 1];
		}
		mag[m].arr[0] = tmp1;
	}
	else if (d == -1) {
		int tmp2 = mag[m].arr[0];
		for (int i = 0; i <= 6; i++) {
			mag[m].arr[i] = mag[m].arr[i + 1];
		}
		mag[m].arr[7] = tmp2;
	}
}

int main() {
	int tc, k;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		cin >> k;

		for (int i = 0; i < 8; i++)
			cin >> mag[0].arr[i];
		for (int i = 0; i < 8; i++)
			cin >> mag[1].arr[i];
		for (int i = 0; i < 8; i++)
			cin >> mag[2].arr[i];
		for (int i = 0; i < 8; i++)
			cin >> mag[3].arr[i];

		for (int i = 0; i < k; i++) {
			int num;
			int dir;
			cin >> num >> dir;
			num -= 1;
	
			switch (num) {
			case 0:
				if (mag[0].arr[2] != mag[1].arr[6]) {
					if (mag[1].arr[2] != mag[2].arr[6]) {
						if (mag[2].arr[2] != mag[3].arr[6]) {
							rot(0, dir);
							rot(1, -dir);
							rot(2, dir);
							rot(3, -dir);
						}
						else {
							rot(0, dir);
							rot(1, -dir);
							rot(2, dir);
						}
					}
					else {
						rot(0, dir);
						rot(1, -dir);
					}
				}
				else {
					rot(0, dir);
				}
				break;
			case 1:
				if (mag[0].arr[2] != mag[1].arr[6]) {
					if (mag[1].arr[2] != mag[2].arr[6]) {
						if (mag[2].arr[2] != mag[3].arr[6]) {
							rot(1, dir);
							rot(0, -dir);
							rot(2, -dir);
							rot(3, dir);
						}
						else {
							rot(1, dir);
							rot(0, -dir);
							rot(2, -dir);
						}
					}
					else {
						rot(1, dir);
						rot(0, -dir);
					}
				}
				else {
					if (mag[1].arr[2] != mag[2].arr[6]) {
						if (mag[2].arr[2] != mag[3].arr[6]) {
							rot(1, dir);
							rot(2, -dir);
							rot(3, dir);
						}
						else {
							rot(1, dir);
							rot(2, -dir);
						}
					}
					else {
						rot(1, dir);
					}
				}
				break;
			case 2:
				if (mag[2].arr[2] != mag[3].arr[6]) {
					if (mag[2].arr[6] != mag[1].arr[2]) {
						if (mag[1].arr[6] != mag[0].arr[2]) {
							rot(2, dir);
							rot(3, -dir);
							rot(1, -dir);
							rot(0, dir);
						}
						else {
							rot(2, dir);
							rot(3, -dir);
							rot(1, -dir);
						}
					}
					else {
						rot(2, dir);
						rot(3, -dir);
					}
				}
				else {
					if (mag[2].arr[6] != mag[1].arr[2]) {
						if (mag[1].arr[6] != mag[0].arr[2]) {
							rot(2, dir);
							rot(1, -dir);
							rot(0, dir);
						}
						else {
							rot(2, dir);
							rot(1, -dir);
						}
					}
					else {
						rot(2, dir);
					}
				}
				break;
			case 3:
				if (mag[3].arr[6] != mag[2].arr[2]) {
					if (mag[2].arr[6] != mag[1].arr[2]) {
						if (mag[1].arr[6] != mag[0].arr[2]) {
							rot(3, dir);
							rot(2, -dir);
							rot(1, dir);
							rot(0, -dir);
						}
						else {
							rot(3, dir);
							rot(2, -dir);
							rot(1, dir);
						}
					}
					else {
						rot(3, dir);
						rot(2, -dir);
					}
				}
				else {
					rot(3, dir);
				}
				break;
			}
		}

		int cnt = 0;
		if (mag[0].arr[0] == 1) cnt += 1;
		if (mag[1].arr[0] == 1) cnt += 2;
		if (mag[2].arr[0] == 1) cnt += 4;
		if (mag[3].arr[0] == 1) cnt += 8;

		
		cout << "#" << t << ' ' << cnt << endl;
	}
		return 0;
}
