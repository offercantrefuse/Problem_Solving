#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int N, a, num1, num2;
char a2[10000];

struct Node {
	int value;
	char opp;
	int left;
	int right;
} node[10001];

void input() {

	scanf("%d %s", &a, a2);

	if (a2[0] >= '0' && a2[0] <= '9') {
		a2[0] = a2[0] - '0';
		node[a].value = a2[0];
		node[a].left = 0; node[a].right = 0;
	}
	else {
		scanf("%d %d", &num1, &num2);
		node[a].opp = a2[0];
		node[a].left = num1;
		node[a].right = num2;
	}
}

// 후위 순회
void solve(int v) {
	if (node[v].left > 0) {
		solve(node[v].left);
	}
	if (node[v].right > 0) {
		solve(node[v].right);
	}

	// 현재 정점이 연산자일 경우 왼쪽과 오른쪽 서브트리 연산
	if (node[v].opp == '+')
		node[v].value = node[node[v].left].value + node[node[v].right].value;
	else if (node[v].opp == '-')
		node[v].value = node[node[v].left].value - node[node[v].right].value;
	else if (node[v].opp == '*')
		node[v].value = node[node[v].left].value * node[node[v].right].value;
	else if (node[v].opp == '/')
		node[v].value = node[node[v].left].value / node[node[v].right].value;
}

int main() {
	int t, i;

	for (t = 1; t <= 10; t++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			input();
		}
		solve(1);
		printf("#%d %d\n", t, node[1].value);

		for (i = 1; i <= N; i++) {
			node[i].left = 0, node[i].right = 0, node[i].value = 0, node[i].opp = ' ';
		}
	}
	return 0;
}
