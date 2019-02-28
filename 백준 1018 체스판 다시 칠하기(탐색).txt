#include <iostream>
using namespace std;
char chess[50][50];
int  n, m;
char matA[8][8] = { {'W','B','W','B','W','B','W','B'},{'B','W','B','W','B','W','B','W'},{ 'W','B','W','B','W','B','W','B' },{ 'B','W','B','W','B','W','B','W' },{ 'W','B','W','B','W','B','W','B' },{ 'B','W','B','W','B','W','B','W' },{ 'W','B','W','B','W','B','W','B' },{ 'B','W','B','W','B','W','B','W' } };
char matB[8][8] = { { 'B','W','B','W','B','W','B','W' } ,{ 'W','B','W','B','W','B','W','B' },{ 'B','W','B','W','B','W','B','W' },{ 'W','B','W','B','W','B','W','B' },{ 'B','W','B','W','B','W','B','W' } ,{ 'W','B','W','B','W','B','W','B' },{ 'B','W','B','W','B','W','B','W' },{ 'W','B','W','B','W','B','W','B' } };

int check(int r, int c) {
	int cntA = 0, cntB = 0;
	// AÇü
	for (int i = r; i < r + 8; i++)
		for (int j = c; j < c + 8; j++)
			if (chess[i][j] != matA[i - r][j - c]) cntA++;
	// BÇü
	for (int i = r; i < r + 8; i++)
		for (int j = c; j < c + 8; j++)
			if (chess[i][j] != matB[i - r][j - c]) cntB++;
	return cntA > cntB ? cntB : cntA;
}

int main() {
	int ans = 100000000;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> chess[i][j];
	for (int i = 0; i < n - 7; i++)
		for (int j = 0; j < m - 7; j++)
			ans = (ans > check(i, j)) ? check(i, j) : ans;
	cout << ans;
	return 0;
}