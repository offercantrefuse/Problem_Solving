#include <iostream>
using namespace std;

int main() {
	int M, now = 1;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		if (a == now) now = b;
		else if (b == now) now = a;
	}
	cout << now;
	return 0;
}