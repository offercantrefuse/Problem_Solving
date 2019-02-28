#include <iostream>
#include <queue>

using namespace std;

int main() {
	int tc, len, i, j, k,n,t;
	char order;
	int x, y;
	queue<int> q_old;
	queue<int> q_new;
	queue<int> q_ins;

	for (tc = 1; tc <= 10; tc++) {
		cin >> len;
		for (i = 0; i < len; i++) {
			int tmp;
			cin >> tmp;
			q_old.push(tmp);
		}
		cin >> n;
		for (j = 0; j < n; j++) {
			cin >> order;
			cin >> x >> y;
			for (k = 0; k < y; k++) {
				int temp;
				cin >> temp;
				q_ins.push(temp);
			}
			for (t = 0; t < x;t++) {
				q_new.push(q_old.front());
				q_old.pop();
			}
			while (!q_ins.empty()) {
				q_new.push(q_ins.front());
				q_ins.pop();
			}
			while (!q_old.empty()) {
				q_new.push(q_old.front());
				q_old.pop();
			}
			while (!q_new.empty()) {
				q_old.push(q_new.front());
				q_new.pop();
			}
		}
		
		cout << "#" << tc << " ";
		for (int p = 0; p < 10;p++) {
			cout << q_old.front() << " ";
			q_old.pop();
		}
		cout << endl;
		while (!q_old.empty()) q_old.pop();
		
	}
	return 0;
}