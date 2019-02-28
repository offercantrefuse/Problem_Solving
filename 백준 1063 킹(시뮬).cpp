#include <iostream>
#include <string>
using namespace std;
int kc, kr, sc, sr;
void move(string a) {
	if (a == "L") {
		if (sc == kc - 1 && sr == kr) {
			if (sc != 1) {
				sc--;
				kc--;
			}
		}
		else {
			if (kc != 1)
				kc--;
		}
	}
	else if (a == "LT") {
		if (sc == kc - 1 && sr == kr + 1) {
			if (sc != 1 && sr != 8) {
				sc--;
				sr++;
				kc--;
				kr++;
			}
		}
		else {
			if (kc != 1 && kr != 8) {
				kc--;
				kr++;
			}
		}
	}
	else if (a == "T") {
		if (sr == kr + 1 && sc == kc) {
			if (sr != 8) {
				sr++;
				kr++;
			}
		}
		else {
			if (kr != 8) {
				kr++;
			}
		}
	}
	else if (a == "RT") {
		if (sc == kc + 1 && sr == kr + 1) {
			if (sc != 8 && sr != 8) {
				sc++;
				sr++;
				kc++;
				kr++;
			}
		}
		else {
			if (kc != 8 && kr != 8) {
				kc++;
				kr++;
			}
		}
	}
	else if (a == "R") {
		if (sc == kc + 1 && sr == kr) {
			if (sc != 8) {
				sc++;
				kc++;
			}
		}
		else {
			if (kc != 8) {
				kc++;
			}
		}
	}
	else if (a == "RB") {
		if (sc == kc + 1 && sr == kr - 1) {
			if (sc != 8 && sr != 1) {
				sc++;
				sr--;
				kc++;
				kr--;
			}
		}
		else {
			if (kc != 8 && kr != 1) {
				kc++;
				kr--;
			}
		}
	}
	else if (a == "B") {
		if (sr == kr - 1 && sc == kc) {
			if (sr != 1) {
				sr--;
				kr--;
			}
		}
		else {
			if (kr != 1) {
				kr--;
			}
		}
	}
	else if (a == "LB") {
		if (sc == kc - 1 && sr == kr - 1) {
			if (sc != 1 && sr != 1) {
				sc--;
				sr--;
				kc--;
				kr--;
			}
		}
		else {
			if (kc != 1 && kr != 1) {
				kc--;
				kr--;
			}
		}
	}
}

int main() {
	int n;
	int row;
	char col;
	cin >> col >> row;
	kc = col - 'A' + 1;
	kr = row;
	cin >> col >> row;
	sc = col - 'A' + 1;
	sr = row;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		move(s);
	}
	char k = kc + 'A' - 1, s = sc + 'A' - 1;
	cout << k << kr << '\n' << s << sr;
	return 0;
}