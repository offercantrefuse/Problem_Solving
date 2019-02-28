#include <iostream>
#include <string>
using namespace std;

int kingr, kingc, rockr, rockc, num;

void move(string str) {
	// 왕 움직이는거 -> 돌 움직이는거
	if (str == "T") {
		if (kingr + 1 > 8) return; // 킹 밖
		else {
			if (kingr + 1 == rockr && kingc == rockc) { // 킹 돌 만남
				if (rockr + 1 > 8) { // 돌 밖
					return;
				}
				else {
					rockr++;
					kingr++;
				}
			}
			else { // 안만남
				kingr++;
			}
		}
	}
	else if (str == "RT") {
		if (kingr + 1 > 8 || kingc + 1 > 8) return; // 킹 밖
		else {
			if (kingr + 1 == rockr && kingc + 1 == rockc) { // 킹 돌 만남
				if (rockr + 1 > 8 || rockc + 1 > 8) { // 돌 밖
					return;
				}
				else {
					rockr++;
					rockc++;
					kingr++;
					kingc++;
				}
			}
			else { // 안만남
				kingr++;
				kingc++;
			}
		}
	}
	else if (str == "R") {
		if (kingc + 1 > 8) return; // 킹 밖
		else {
			if (kingc + 1 == rockc && kingr == rockr) { // 킹 돌 만남
				if (rockc + 1 > 8) { // 돌 밖
					return;
				}
				else {
					rockc++;
					kingc++;
				}
			}
			else { // 안만남
				kingc++;
			}
		}
	}
	else if (str == "RB") {
		if (kingc + 1 > 8 || kingr - 1 < 1) return; // 킹 밖
		else {
			if (kingc + 1 == rockc && kingr - 1 == rockr) { // 킹 돌 만남
				if (rockc + 1 > 8 || rockr - 1 < 1) { // 돌 밖
					return;
				}
				else {
					rockc++;
					rockr--;
					kingc++;
					kingr--;
				}
			}
			else { // 안만남
				kingc++;
				kingr--;
			}
		}
	}
	else if (str == "B") {
		if (kingr - 1 < 1) return; // 킹 밖
		else {
			if (kingr - 1 == rockr && kingc == rockc) { // 킹 돌 만남
				if (rockr - 1 < 1) { // 돌 밖
					return;
				}
				else {
					rockr--;
					kingr--;
				}
			}
			else { // 안만남
				kingr--;
			}
		}
	}
	else if (str == "LB") {
		if (kingr - 1 < 1 || kingc - 1 < 1) return; // 킹 밖
		else {
			if (kingr - 1 == rockr && kingc - 1 == rockc) { // 킹 돌 만남
				if (rockr - 1 < 1 || rockc - 1 < 1) { // 돌 밖
					return;
				}
				else {
					rockr--;
					rockc--;
					kingr--;
					kingc--;
				}
			}
			else { // 안만남
				kingr--;
				kingc--;
			}
		}
	}
	else if (str == "L") {
		if (kingc - 1 < 1) return; // 킹 밖
		else {
			if (kingc - 1 == rockc && kingr == rockr) { // 킹 돌 만남
				if (rockc - 1 < 1) { // 돌 밖
					return;
				}
				else {
					rockc--;
					kingc--;
				}
			}
			else { // 안만남
				kingc--;
			}
		}
	}
	else if (str == "LT") {
		if (kingc - 1 < 1 || kingr + 1 > 8) return; // 킹 밖
		else {
			if (kingc - 1 == rockc && kingr + 1 == rockr) { // 킹 돌 만남
				if (rockc - 1 < 1 || rockr + 1 > 8) { // 돌 밖
					return;
				}
				else {
					rockc--;
					rockr++;
					kingc--;
					kingr++;
				}
			}
			else { // 안만남
				kingc--;
				kingr++;
			}
		}
	}
}


int main() {
	string s;
	cin >> s;
	kingc = s[0] - 'A' + 1;
	kingr = s[1] - '0';
	cin >> s;
	rockc = s[0] - 'A' + 1;
	rockr = s[1] - '0';
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> s;
		move(s);
	}
	char c1 = kingc - 1 + 'A', c2 = rockc - 1 + 'A';

	cout << c1 << kingr << '\n' << c2 << rockr << '\n';
	return 0;
}