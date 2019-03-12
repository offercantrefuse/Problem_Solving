#include <iostream>
#include <string>
using namespace std;
int n, s;
char letter[24][13];
char word[120][230];
void alpha(int num, char ch) {
	if (ch == '1') {
		for (int i = 1; i <= num; i++)
			letter[i][num + 1] = '|';
		for (int i = num + 2; i <= 2 * num + 1; i++)
			letter[i][num + 1] = '|';
	}
	else if (ch == '2') {
		for (int i = 1; i <= num; i++) {
			letter[0][i] = '-';
			letter[num + 1][i] = '-';
			letter[2 * num + 2][i] = '-';
		}
		for (int i = 1; i <= num; i++)
			letter[i][num + 1] = '|';
		for (int i = num + 2; i <= 2 * num + 1; i++)
			letter[i][0] = '|';
	}
	else if (ch == '3') {
		for (int i = 1; i <= num; i++) {
			letter[0][i] = '-';
			letter[num + 1][i] = '-';
			letter[2 * num + 2][i] = '-';
		}
		for (int i = 1; i <= num; i++)
			letter[i][num + 1] = '|';
		for (int i = num + 2; i <= 2 * num + 1; i++)
			letter[i][num + 1] = '|';
	}
	else if (ch == '4') {
		for (int i = 1; i <= num; i++) {
			letter[i][num + 1] = '|';
			letter[i][0] = '|';
		}
		for (int i = 1; i <= num; i++)
			letter[num + 1][i] = '-';
		for (int i = num + 2; i <= 2 * num + 1; i++)
			letter[i][num + 1] = '|';
	}
	else if (ch == '5') {
		for (int i = 1; i <= num; i++) {
			letter[0][i] = '-';
			letter[num + 1][i] = '-';
			letter[2 * num + 2][i] = '-';
		}
		for (int i = 1; i <= num; i++)
			letter[i][0] = '|';
		for (int i = num + 2; i <= 2 * num + 1; i++)
			letter[i][num + 1] = '|';
	}
	else if (ch == '6') {
		for (int i = 1; i <= num; i++) {
			letter[0][i] = '-';
			letter[num + 1][i] = '-';
			letter[2 * num + 2][i] = '-';
		}
		for (int i = 1; i <= num; i++)
			letter[i][0] = '|';
		for (int i = num + 2; i <= 2 * num + 1; i++) {
			letter[i][num + 1] = '|';
			letter[i][0] = '|';
		}
	}
	else if (ch == '7') {
		for (int i = 1; i <= num; i++)
			letter[0][i] = '-';
		for (int i = 1; i <= num; i++)
			letter[i][num + 1] = '|';
		for (int i = num + 2; i <= 2 * num + 1; i++)
			letter[i][num + 1] = '|';
	}
	else if (ch == '8') {
		for (int i = 1; i <= num; i++) {
			letter[0][i] = '-';
			letter[num + 1][i] = '-';
			letter[2 * num + 2][i] = '-';
		}
		for (int i = 1; i <= num; i++) {
			letter[i][0] = '|';
			letter[i][num + 1] = '|';
		}
		for (int i = num + 2; i <= 2 * num + 1; i++) {
			letter[i][num + 1] = '|';
			letter[i][0] = '|';
		}
	}
	else if (ch == '9') {
		for (int i = 1; i <= num; i++) {
			letter[0][i] = '-';
			letter[num + 1][i] = '-';
			letter[2 * num + 2][i] = '-';
		}
		for (int i = 1; i <= num; i++) {
			letter[i][0] = '|';
			letter[i][num + 1] = '|';
		}
		for (int i = num + 2; i <= 2 * num + 1; i++)
			letter[i][num + 1] = '|';
	}
	else if (ch == '0') {
		for (int i = 1; i <= num; i++) {
			letter[0][i] = '-';
			letter[2 * num + 2][i] = '-';
		}
		for (int i = 1; i <= num; i++) {
			letter[i][0] = '|';
			letter[i][num + 1] = '|';
		}
		for (int i = num + 2; i <= 2 * num + 1; i++) {
			letter[i][num + 1] = '|';
			letter[i][0] = '|';
		}
	}
}
int main() {
	string s;
	cin >> n >> s;
	int cnt = 0;
	for (int t = 0; t < s.length(); t++) {
		for (int i = 0; i < 24; i++)
			for (int j = 0; j < 14; j++)
				letter[i][j] = ' ';
		alpha(n, s[t]);
		for (int i = 0; i < 2 * n + 3; i++) {
			for (int j = 0; j < n + 2; j++) {
				word[i][j + cnt] = letter[i][j];
			}
		}
		cnt += n + 2;
	}
	for (int i = 0; i < 2 * n + 3; i++) {
		for (int k = 1; k <= s.length(); k++) {
			for (int j = (n + 2)*(k - 1); j < (n + 2)*k; j++) {
				cout << word[i][j];
			}
			cout << ' ';
		}
		cout << '\n';
	}

	return 0;
}