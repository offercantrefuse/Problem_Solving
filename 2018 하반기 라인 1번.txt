#include <iostream>
// #include <cstdio>  // uncomment to use scanf/printf instead of cin/cout
#include <sstream>
#include <string>

using namespace std;

int main() {
	string line;
	int money = 20000;
	getline(cin, line);
	stringstream ss(line);
	for (int distance; !(ss >> distance).fail(); ) {
		if (distance > 178 || distance < 4) break;
		if (distance <= 40) {
			if (money - 720 >= 0) money -= 720;
			else break;
		}
		else if (distance > 40) {
			int tmp = distance - 40;
			if (tmp % 8 == 0) tmp = tmp/8;
			else tmp = tmp / 8 + 1;
			if (money - (720 + tmp * 80) >= 0) money -= 720 + tmp * 80;
			else break;
		}
	}
	cout << money;
	cout << endl;
	return 0;
}
