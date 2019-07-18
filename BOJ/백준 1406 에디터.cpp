#include <iostream>
using namespace std;

const int MAX_SIZE = 600000;
int N;

struct NODE {
	char val;
	int prev, next;
};

struct MY_LIST {
	int HEAD = MAX_SIZE;
	int TAIL = MAX_SIZE + 2;
	int CURSOR = MAX_SIZE + 1;
	int pos;
	NODE node[MAX_SIZE + 3];

	MY_LIST() {
		pos = 0;
		node[HEAD].next = CURSOR;
		node[CURSOR].prev = HEAD;
		node[CURSOR].next = TAIL;
		node[TAIL].prev = CURSOR;
	}

	void push(char _data) {
		int prev = node[CURSOR].prev;

		node[pos].val = _data;
		node[CURSOR].prev = pos;
		node[pos].next = CURSOR;

		node[pos].prev = prev;
		node[prev].next = pos;
		pos++;
	}

	void erase() {
		int prev = node[CURSOR].prev;
		int pprev = node[prev].prev;

		if (prev == HEAD) return;

		node[pprev].next = CURSOR;
		node[CURSOR].prev = pprev;
	}

	void move_left() {
		int prev = node[CURSOR].prev;
		int next = node[CURSOR].next;

		if (prev == HEAD) return;

		int pprev = node[prev].prev;

		node[pprev].next = CURSOR;
		node[CURSOR].prev = pprev;
		node[CURSOR].next = prev;
		node[prev].prev = CURSOR;
		node[prev].next = next;
		node[next].prev = prev;
	}

	void move_right() {
		int prev = node[CURSOR].prev;
		int next = node[CURSOR].next;

		if (next == TAIL) return;

		int nnext = node[next].next;

		node[prev].next = next;
		node[next].prev = prev;
		node[next].next = CURSOR;
		node[CURSOR].prev = next;
		node[CURSOR].next = nnext;
		node[nnext].prev = CURSOR;
	}


};

MY_LIST str;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	char c[100000];
	cin >> c;
	for (int i = 0; c[i] != 0; i++) {
		str.push(c[i]);
	}
	cin >> N;
	for (int i = 0; i < N; i++) {
		char cmd;
		cin >> cmd;
		switch (cmd) {
		case 'L':
			// cursor left
			str.move_left();
			break;
		case 'D':
			// cursor right
			str.move_right();
			break;
		case 'B':
			// backspace
			str.erase();
			break;
		case 'P':
			// type 
			char ch;
			cin >> ch;
			str.push(ch);
			break;
		}
	}
	int idx = str.node[str.HEAD].next;
	while (idx != str.TAIL) {
		if (idx != str.CURSOR) cout << str.node[idx].val;
		idx = str.node[idx].next;
	}
	return 0;
}