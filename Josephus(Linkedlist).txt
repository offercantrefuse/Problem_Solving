#include <iostream>

using namespace std;

struct Node {
	int num;
	Node* link;
};

int main() {
	Node* delete_node;
	Node* head = (Node*)malloc(sizeof(Node));
	Node* node = head;

	int n, k;
	
	cout << "병사 수,건너뛸 수 입력: ";
	cin >> n >> k;

	for (int i = 0; i < n; i++){
		node->link = (Node*)malloc(sizeof(Node));
		node = node->link;
		node->num = i+1;
	}

	node->link = head;
	node = node->link;

	for (int i = 0; i < n - 1; i++) {
		// node를 k-1만큼 이동
		for (int j = 0; j < k; k++) {
			node = node->link;
		}
		// node의 다음 node 지움
		delete_node = node->link;
		node->link = delete_node->link;

		free(delete_node);

		node = node->link;
	}

	cout << node->num << endl;

	return 0;
}