#include <iostream>
// #include <cstdio>  // uncomment to use scanf/printf instead of cin/cout
#include <string>
#include <vector>
using namespace std;
int a, b;
char before = 'B';
vector< vector<string> > arr;
vector< vector<int> > visit;
void move(int x, int y) {
	if (before == 'F') {
		if (arr[x][y].at(0) == 'F') {
			for (int i = 0; i < arr[x][y].at(1) - '0'; i++) b--;
			before = 'F';
		}
		else if (arr[x][y].at(0) == 'R') {
			for (int i = 0; i < arr[x][y].at(1) - '0'; i++) a++;
			before = 'R';
		}
		else if (arr[x][y].at(0) == 'L') {
			for (int i = 0; i < arr[x][y].at(1) - '0'; i++) a--;
			before = 'L';
		}
		else if (arr[x][y].at(0) == 'B') {
			for (int i = 0; i < arr[x][y].at(1) - '0'; i++) b++;
			before = 'B';
		}
	}
	else if (before == 'R') {
		if (arr[x][y].at(0) == 'F') {
			for (int i = 0; i < arr[x][y].at(1) - '0'; i++) a++;
			before = 'R';
		}
		else if (arr[x][y].at(0) == 'R') {
			for (int i = 0; i < arr[x][y].at(1) - '0'; i++) b++;
			before = 'B';
		}
		else if (arr[x][y].at(0) == 'L') {
			for (int i = 0; i < arr[x][y].at(1) - '0'; i++) b--;
			before = 'F';
		}
		else if (arr[x][y].at(0) == 'B') {
			for (int i = 0; i < arr[x][y].at(1) - '0'; i++) a--;
			before = 'L';
		}
	}
	else if (before == 'L') {
		if (arr[x][y].at(0) == 'F') {
			for (int i = 0; i < arr[x][y].at(1) - '0'; i++) a--;
			before = 'L';
		}
		else if (arr[x][y].at(0) == 'R') {
			for (int i = 0; i < arr[x][y].at(1) - '0'; i++) b--;
			before = 'F';
		}
		else if (arr[x][y].at(0) == 'L') {
			for (int i = 0; i < arr[x][y].at(1) - '0'; i++) b++;
			before = 'B';
		}
		else if (arr[x][y].at(0) == 'B') {
			for (int i = 0; i < arr[x][y].at(1) - '0'; i++) a++;
			before = 'R';
		}
	}
	else if (before == 'B') {
		if (arr[x][y].at(0) == 'F') {
			for (int i = 0; i < arr[x][y].at(1) - '0'; i++) b++;
			before = 'B';
		}
		else if (arr[x][y].at(0) == 'R') {
			for (int i = 0; i < arr[x][y].at(1) - '0'; i++) a--;
			before = 'L';
		}
		else if (arr[x][y].at(0) == 'L') {
			for (int i = 0; i < arr[x][y].at(1) - '0'; i++) a++;
			before = 'R';
		}
		else if (arr[x][y].at(0) == 'B') {
			for (int i = 0; i < arr[x][y].at(1) - '0'; i++) b--;
			before = 'F';
		}
	}

}
int main() {
	int n;
	int ansx, ansy;
	cin >> n;
	for (int i = 0; i < n; i++) {
		vector<string> a(n);
		arr.push_back(a);
		vector<int> b(n);
		visit.push_back(b);
	}
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < n; ++y) {
			string node;
			cin >> node;
			arr[y][x] = node;
			visit[x][y] = 0;
		}
	}
	a = 0;
	b = 0;
	while (1) {
		if (visit[a][b] == 1) {
			ansx = a;
			ansy = b;
			break;
		}
		visit[a][b] = 1;
		move(a, b);
	}
	cout << ansx << ' ' << ansy;
	cout << endl;
	return 0;
}
