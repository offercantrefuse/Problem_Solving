#include <iostream>
using namespace std;

const int HEAP_SIZE = 100000;
int heap[HEAP_SIZE];
int heap_size = 0;

void push(int _data) {
	int target = ++heap_size;
	while (target / 2 > 0 && heap[target / 2] > _data) {
		heap[target] = heap[target / 2];
		target = target / 2;
	}
	heap[target] = _data;
}

void pop() {
	if (heap_size == 0) {
		cout << "0\n";
		return;
	}
	cout << heap[1] << '\n';
	int parent = 1, child = 2;
	// child 두 개와 heap_size꺼 비교
	int tmp = heap[heap_size];
	while (child < heap_size) {
		if (child + 1 < heap_size && heap[child] > heap[child + 1]) {
			child++;
		}
		if (tmp <= heap[child]) break;
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = tmp;
	heap_size--;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		if (x == 0) {
			pop();
		}
		else {
			push(x);
		}
	}
	return 0;
}