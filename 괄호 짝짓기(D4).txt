#include <iostream>
#include <string>

using namespace std;

int main() {

	int t, n, i, j;
	char par[1000];
	int top;
	char stack[1000];
	int flag;

	for (t = 1; t <= 10; t++) {
		cin >> n;
		cin >> par;

		top = 0;
		flag = 0;

		for (i = 0; i < n; i++) {
			if (par[i] == '(' || par[i] == '{' || par[i] == '[' || par[i] == '<') {
				stack[top++] = par[i];
			}
			else if (par[i] == ')') {
				if (stack[top - 1] == '(')
					top--;
				else
					break;
			}
			else if (par[i] == '}') {
				if (stack[top - 1] == '{')
					top--;
				else
					break;
			}
			else if (par[i] == ']') {
				if (stack[top - 1] == '[')
					top--;
				else
					break;
			}
			else if (par[i] == '>') {
				if (stack[top - 1] == '<')
					top--;
				else
					break;
			}
		}
		if (top == 0) {
			flag = 1;
		}
		cout << "#" << t << " " << flag << endl;
	}


	return 0;
}

/////////////////////////////////
ÀßÇÑ¾Ö

#include <iostream>
#include <stack>

using namespace std;

int n;
char ch;

bool f(stack<char> &s)
{
	cin >> n;
	while (n--) {
		cin >> ch;
		if (!s.empty()) {
			if (s.top() + 2 == ch || s.top() + 1 == ch) {
				s.pop(); continue;
			}
		}
		s.push(ch);
	}
	return s.empty() ? 1 : 0;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	for (int tc = 1; tc <= 10; tc++) {
		stack<char> s;
		cout << '#' << tc << ' ' << f(s) << '\n';
	}
	return 0;
}