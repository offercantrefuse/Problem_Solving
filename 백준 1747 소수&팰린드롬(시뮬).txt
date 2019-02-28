#include <iostream>
#include <vector>
using namespace std;

bool check_prime(int num) {
	if (num == 1) {
		return false;
	}
	int tmp = num - 1;
	while (tmp != 1) {
		if (num%tmp == 0) {
			return false;
		}
		tmp--;
	}
	return true;
}

bool check_pelin(int num) {
	vector<int> tmp;
	while (num) {
		tmp.push_back(num % 10);
		num /= 10;
	}
	for (int i = 0; i < tmp.size() / 2; i++) {
		if (tmp[i] == tmp[tmp.size() - i - 1])
			continue;
		return false;
	}
	return true;
}
int main() {
	int a;
	cin >> a;
	while (true) {
		if (check_pelin(a) && check_prime(a)) {
			cout << a << '\n';
			break;
		}
		a++;
	}
	return 0;
}