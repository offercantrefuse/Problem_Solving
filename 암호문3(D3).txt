#include <iostream>

using namespace std;

struct Node {
	int data;
	Node *next;
};

Node* create_node(int num) {
	Node *newNode = new Node;
	newNode->data = num;
	newNode->next = NULL;

	return newNode;
}

Node* insert_node(Node *prev, int ins) {
	Node* insNode = new Node;
	Node* nextNode = prev->next;
	prev->next = insNode;
	insNode->next = nextNode;
	insNode->data = ins;

	return insNode;
}

void delete_node(Node* prev) {
	Node* targetNode = prev->next;
	prev->next = targetNode->next;
	free(targetNode);
}

int main() {
	int tc, len, n, i, j;
	char order;
	int x, y;

	for (tc = 1; tc <= 10; tc++) {
		cin >> len;

		Node* head = create_node(NULL);
		Node* curr = head;

		for (i = 0; i < len; i++) {
			int tmp;
			cin >> tmp;
			Node* plusNode = create_node(tmp);
			curr->next = plusNode;
			curr = plusNode;
		}

		curr = head;   // ¹Ý´ë?

		cin >> n;
		for (int k = 0; k < n; k++) {
			cin >> order;

			if (order == 'I') {
				cin >> x >> y;
				for (i = 0; i < x ; i++) {
					curr = curr->next;
				}
				for (j = 0; j < y; j++) {
					int s;
					cin >> s;
					curr = insert_node(curr, s);
				}

				curr = head;
			}

			else if (order == 'D') {
				cin >> x >> y;
				for (i = 0; i < x ; i++) {
					curr = curr->next;
				}
				for (j = 0; j < y; j++) {
					delete_node(curr);
				}
				curr = head;
			}

			else if (order == 'A') {
				cin >> y ;
				while(curr->next !=NULL) {
					curr = curr->next;
				}
				for (j = 0; j < y; j++) {
					int s;
					cin >> s;
					curr = insert_node(curr, s);
				}
				curr = head;
			}

		}
		cout << "#" << tc << " ";

		for (int k = 0; k < 10; k++) {
			cout << curr->next->data << " ";
			curr = curr->next;
		}
		cout << endl;

		free(head);
	}
	return 0;
}