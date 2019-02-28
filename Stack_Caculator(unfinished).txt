#include <iostream>

using namespace std;

int testcase;
char stack[1000];
char infix[1000];
char postfix[1000];
int top = 0;

void push(char c) {
	stack[top++] = c;
}

void pop(char *a) {
	*a = stack[--top];
}


int main() {


	for (int i = 0; i < 10; i++) {
		cin >> testcase;
		for (int j = 0; j < testcase; j++) {
			cin >> infix[j];
		}

		int t = 0;
		for (int k = 0; k < testcase; k++) {
			if (infix[k] >= '0' &&infix[k] <= '9') {
				postfix[t++]=infix[k];
			}
			else if (infix[k] == '(') {
				push('(');
			}
			else if (infix[k] == ')') {
				while(stack[top]!='(') {
					postfix[t++] = stack[top];
					pop(stack);
				}
				pop(stack);
			}
			else if (infix[k] == '+') {
				if (stack[top] != '*' || stack[top] != '+') {
					push('+');
				}
				else {
					postfix[t++] = stack[top];
					pop(stack);
					push('+');
				}
			}
			else if (infix[k] == '*') {
				if (stack[top] != '*') {
					push('*');
				}
				else {
					postfix[t++] = stack[top];
					pop(stack);
					push('*');
				}
			}
			while (top) {
				postfix[t++] = stack[top];
				pop(stack);
				top--;
			}
		}

		for (int k = 0; k < top+1; k++) {
			char a, b;

			if (postfix[k] >= '0'&& postfix[k] <= '9') {
				push(postfix[k]);
			}
			else if(postfix[k]=='+'){
				stack[top] = a;

				pop(stack);
				
			}
		}



	}

	


	return 0;
}