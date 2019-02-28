#include <iostream>
#define swap(a,b) {int t;t=a;a=b;b=t;}
using namespace std;

struct Node {
	int data;
	Node *next;
}; 

void add_node(Node *prev,Node *p_new){
	p_new->next = prev->next;
	prev->next = p_new;
}

Node* delete_node(Node *prev) {
	Node *target_node = prev->next;
	prev->next = target_node->next;
	return target_node;
	
}

void insertionSort(int data[], int size) {
	int i;
	Node *head_unsorted = (Node*)malloc(sizeof(Node));
	Node *head_sorted = (Node*)malloc(sizeof(Node));
	Node *node = head_unsorted;
	Node *prev, *curr;

	head_unsorted->next = NULL;
	head_sorted->next = NULL;

	for (i = 0; i < size; i++) {
		node->next = (Node*)malloc(sizeof(Node));
		node = node->next;
		node->data = data[i];
		node->next = NULL;
	}

	while (head_unsorted->next) {
		node = delete_node(head_unsorted);

		prev = head_sorted;
		curr = head_sorted->next;
		while (curr && curr->data < node->data) {
			prev = prev->next;
			curr = curr->next;
		}
		add_node(prev, node);
	}
	free(head_unsorted);

	node = head_sorted->next;
	free(head_sorted);
	size = 0;

	while (node) {
		data[size] = node->data;
		size++;
		prev = node;
		node = node->next;
		free(prev);
	}
	return;
}

int main() {

	int data[1000], i;
	for (i = 0; i < 1000; i++) {
		data[i] = rand() % 1000;
	}

	insertionSort(data, 1000);

	for (i = 0; i < 999; i++) {
		if (data[i] > data[i + 1]) {
			puts("error");
			break;
		}
	}

	return 0;
}
