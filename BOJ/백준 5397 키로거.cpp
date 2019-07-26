#include <iostream>
using namespace std;

const int MAX_SIZE = 1000000;

struct NODE {
	char val;
	int prev, next;
};

struct MY_LIST {
	int HEAD = MAX_SIZE;
	int CURSOR = MAX_SIZE + 1;
	int TAIL = MAX_SIZE + 2;
	NODE node[MAX_SIZE + 3];
	int pos;

	MY_LIST() {
		pos = 0;
		node[HEAD].next = CURSOR;
		node[CURSOR].prev = HEAD;
		node[CURSOR].next = TAIL;
		node[TAIL].prev = CURSOR;
	}

	void init() {
		pos = 0;
		node[HEAD].next = CURSOR;
		node[CURSOR].prev = HEAD;
		node[CURSOR].next = TAIL;
		node[TAIL].prev = CURSOR;
	}


	void insert(char  _data) {
		int prev = node[CURSOR].prev;
		int next = node[prev].next;

		node[pos].val = _data;
		node[pos].prev = prev;
		node[prev].next = pos;
		node[pos].next = next;
		node[next].prev = pos;

		pos++;
	}

	void left() {
		if (node[CURSOR].prev == HEAD) return;
		int prev = node[CURSOR].prev;
		int pprev = node[prev].prev;
		int next = node[CURSOR].next;

		node[pprev].next = CURSOR;
		node[CURSOR].prev = pprev;
		node[CURSOR].next = prev;
		node[prev].prev = CURSOR;
		node[prev].next = next;
		node[next].prev = prev;

	}

	void right() {
		if (node[CURSOR].next == TAIL) return;
		int prev = node[CURSOR].prev;
		int next = node[CURSOR].next;
		int nnext = node[next].next;

		node[prev].next = next;
		node[next].prev = prev;
		node[next].next = CURSOR;
		node[CURSOR].prev = next;
		node[CURSOR].next = nnext;
		node[nnext].prev = CURSOR;

	}

	void backspace() {
		if (node[CURSOR].prev == HEAD) return;
		int prev = node[CURSOR].prev;
		int pprev = node[prev].prev;
		int next = node[prev].next;

		node[pprev].next = next;
		node[next].prev = pprev;
	}
};


MY_LIST list;
int T;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	char str[1000000];
	for (int i = 0; i < T; i++) {
		cin >> str;
		list.init();
		for (int i = 0; str[i] != 0; i++) {
			if (str[i] == '<') {
				list.left();
			}
			else if (str[i] == '>') {
				list.right();
			}
			else if (str[i] == '-') {  // backspace
				list.backspace();
			}
			else { // ¹®ÀÚ
				list.insert(str[i]);
			}
		}
		int idx = list.node[list.HEAD].next;
		for (int i = idx; i != list.TAIL; i = list.node[i].next) {
			if (list.node[i].val != '>' && list.node[i].val != '<' && list.node[i].val != '-' && list.node[i].val != '\0') {
				cout << list.node[i].val;
			}
		}
		cout << '\n';
	}

	return 0;
}