#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next;
}; 

Node *Merge(Node *left, Node *right) {
	Node * node = (Node*)malloc(sizeof(Node));
	Node * head = node;

	while (left&&right) {
		if (left->data < right->data) {
			node->next = left;
			left = left->next;
			node = node->next;
		}
		else {
			node->next = right;
			right = right->next;
			node = node->next;
		}
	}
	if (left) {
		node->next;
	}
	else {
		node->next = right;
	}

	node = head->next;
	free(head);
	return node;
}

Node *Devide(Node *first, int size) {
	int i;
	Node *left = first;
	Node *right = first;
	Node *prev_right = first;

	for (i = 0; i < (size / 2) - 1; i++) {
		prev_right = prev_right->next;
	}
	right = prev_right->next;
	prev_right->next = NULL;

	if (size / 2 > 1) left = Devide(left, size / 2);
	if (size - (size / 2) > 1) right = Devide(right, size - (size / 2));

	return Merge(left, right);
}

void MergeSort(int data[], int size) {
	int i;
	Node *head_unsorted = (Node*)malloc(sizeof(Node));
	Node *node = head_unsorted;

	head_unsorted->next = NULL;

	for (i = 0; i < size; i++) {
		node->next = (Node*)malloc(sizeof(Node));
		node = node->next;
		node->data = data[i];
		node->next = NULL;
	}

	node = Devide(head_unsorted->next, size);

	free(head_unsorted);

	for (i = 0; i < size; i++) {
		data[i] = node->data;
		node = node->next;
	}
	return;
}

int main() {

	int data[1000], i;
	for (i = 0; i < 1000; i++) {
		data[i] = rand() % 1000;
	}

	MergeSort(data, 1000);

	for (i = 0; i < 999; i++) {
		if (data[i] > data[i + 1]) {
			puts("error");
			break;
		}
	}

	return 0;
}
