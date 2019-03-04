#include <iostream>
using namespace std;

int main() {
	int n, m;
	char a[50][50];
	char b[50][50];
	int cnt = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> b[i][j];
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			if (a[i][j] != b[i][j]) {
				cnt++;
				for (int k = i; k < i + 3; k++) {
					for (int t = j; t < j + 3; t++) {
						if (a[k][t] == '0')
							a[k][t] = '1';
						else
							a[k][t] = '0';
					}
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != b[i][j]) {
				cnt = -1;
				break;
			}
		}
	}
	cout << cnt << '\n';

	return 0;
}