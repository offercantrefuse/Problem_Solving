#include <iostream>

using namespace std;


int multi(int m, int n) {
	if (n != 0)
		return (m * multi(m, n - 1));
	else
		return 1;
}

int main() {

	int t, n, i;
	int a, b, result;

	for (t = 1; t <= 10; t++) {
		cin >> n;
		cin >> a >> b;

		result = multi(a, b);

		cout << "#" << t << " " << result << endl;
	}
	return 0;
}