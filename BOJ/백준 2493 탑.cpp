#include <iostream>
#include <stack>
using namespace std;
struct node {
	int idx;
	long num;
	node(int idx, long num) :idx(idx), num(num) {}
	node() {}
};
int N;
long h[500000] = { 0, };
stack<node> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> h[i];
		if (st.size() == 0) {  // stack에 아무것도 없을 때
			cout << "0 ";
			st.push(node(i, h[i]));
		}
		else if (st.top().num >= h[i]) {
			cout << st.top().idx + 1 << ' ';
			st.push(node(i, h[i]));
		}
		else {
			while (st.size() != 0 && st.top().num < h[i]) {
				st.pop();
			}
			if (st.size() == 0) {
				cout << "0 ";
			}
			else {
				cout << st.top().idx + 1 << ' ';
			}
			st.push(node(i, h[i]));
		}
	}
	return 0;
}