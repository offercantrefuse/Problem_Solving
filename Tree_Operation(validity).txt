#include <stdio.h>
#include <malloc.h>


struct _Node {
	int value;
	char opp;
	int left;
	int right;
}node[1001];

int N, a;  // 정점 개수, 정점 번호
char a2[20];  // 한 줄 단위
int state = 1; // 결과

// 입력 값 받기
void input() {
	int b[3] = { 0, }, top = 0;
	int i;
	scanf_s("%d\n", &a); // 정점 번호
	gets(a2); // 그 다음 한줄 읽기

	int t = 1;
	for (i = 0; a2[i]; i++) {
		// 숫자
		if (a2[i] >= '0' && a2[i] <= '9') {
			a2[i] = a2[i] - '0';
			b[top] = b[top] * t + a2[i];
			t = 10;
		}
		// 연산자
		else if (a2[i] != ' ') {
			if (top == 0)
				node[a].opp = a2[i];
			else if (top == 1)
				node[a].left = a2[i];
			else
				node[a].right = a2[i];
			b[top] = -1, top++;
			t = 1;
			continue;
		}
		// 띄어쓰기 또는 한 줄이 끝났을 경우
		if (a2[i + 1] == ' ' || a2[i + 1] == '\0') {
			if (b[top] != -1) {
				if (top == 0)
					node[a].value = b[top];
				else if (top == 1)
					node[a].left = b[top];
				else
					node[a].right = b[top];
			}
			top++;
			t = 1; // continue
		}
	}
}

// 중위 순회
void solve(int v) {
	if (node[v].left > 0)
		solve(node[v].left);

	// 연산자인 경우, 두 개의 자손 노드가 존재해야함
	if (node[v].opp >= 42 && node[v].opp <= 47) {
		if (node[v].left == 0 || node[v].right == 0) {
			state = 0;
		}
	}
	// 숫자인 경우, 두 개의 자손 노드가 존재하면 안된다
	else if (node[v].value > 0) {
		if (!(node[v].left == 0 && node[v].right == 0)) {
			state = 0;
		}
	}

	if (node[v].right > 0)
		solve(node[v].right);
}

int main() {
	int testcase, i;
	for (testcase = 1; testcase <= 10; testcase++) {
		scanf_s("%d", &N);
		for (i = 0; i < N; i++) {
			input();
		}
		state = 1;
		solve(1); // 중위 순회

		// 결과
		printf("#%d ", testcase);
		if (state) printf("1\n");
		else printf("0\n");
		
		// 초기화
		for (i = 0; i < 1001; i++) {
			node[i].left = 0, node[i].right = 0, node[i].opp = ' ', node[i].value = 0;
		}
	}
	return 0;
}

