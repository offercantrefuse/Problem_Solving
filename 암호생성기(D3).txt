#include <iostream>
#include <queue>

using namespace std;

void pull(queue<int> &Q) { 
	int t = Q.front();
	Q.pop(); 
	Q.push(t);
}

int main() {
	int tc, n, i, j, tmp;
	queue <int> q;

	for (tc = 1; tc <= 10; tc++) {
		cin >> n;
		for (i = 0; i < 8; i++) {
			cin >> tmp;
			q.push(tmp);
		}
		j = 1;
		while (1) {
			q.front() -= j++;
			pull(q);


			if (j == 6)
				j = 1;
			if (q.back() <= 0) {
				q.back() = 0;
				break;
			}
		}
		cout << "#" << tc << " ";
		for (int k = 0; k < 8; k++) {
			cout << q.front() << " ";
			q.pop();
		}
		cout << endl;
	}

	return 0;
}