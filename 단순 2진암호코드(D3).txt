#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int main() {
	int t, tc, n, m, i, j;
	int tmpi, tmpj;
	int pwd[8];

	char c[50][100];

	cin >> tc;
	for (t = 1; t <= tc; t++) {
		cin >> n >> m;

		tmpi = 0;
		tmpj = 0;

		for (i = 0; i < n; i++) {
			scanf("%s", &c[i]);
		}
		
		for (i = n - 1; i >= 0; i--) {
			for (j = m - 1; j >= 0; j--) {
				if (c[i][j] == '1') {
					tmpi = i;
					tmpj = j - 55;
					break;
				}
			}
		}

		for (i = 0; i < 8; i++) {
			pwd[i] = 0;
		}

		for (i = 0; i < 8; i++) {
			string str;
			str.clear();
			for (j = tmpj + 7 * i; j < tmpj + 7 * (i + 1); j++) {
				str.insert(str.end(), c[tmpi][j]);
			}
			if (str == "0001101")
				pwd[i] = 0;
			else if (str == "0011001")
				pwd[i] = 1;
			else if (str == "0010011")
				pwd[i] = 2;
			else if (str == "0111101")
				pwd[i] = 3;
			else if (str == "0100011")
				pwd[i] = 4;
			else if (str == "0110001")
				pwd[i] = 5;
			else if (str == "0101111")
				pwd[i] = 6;
			else if (str == "0111011")
				pwd[i] = 7;
			else if (str == "0110111")
				pwd[i] = 8;
			else if (str == "0001011")
				pwd[i] = 9;
		}
				
		if ((((pwd[0] + pwd[2] + pwd[4] + pwd[6]) * 3 + (pwd[1] + pwd[3] + pwd[5]) + pwd[7])) % 10 == 0) {
		cout << "#" << t << " " << pwd[0] + pwd[1] + pwd[2] + pwd[3] + pwd[4] + pwd[5] + pwd[6] + pwd[7] << endl;
		}
		else
		cout << "#" << t << " " << "0" << endl;
	}
	return 0;
}