#include <iostream>

using namespace std;

int queue[10001];
int front;
int rear;

int isEmpty();
int isFull();
void enQueue(int item);
int deQueue();
void createQueue();
int Qpeek();

int t;
int n, m, i, j, a, b;

int adjacent[10001][10001];
int visited[10001];
int visitingVertex;

int main() {
	cin >> t;

	while (t--) {
		for (i = 1; i <= n; i++) {
			visited[i] = 0;
			for (j = 1; j <= n; j++) {
				adjacent[i][j] = 0;
			}
		}

		cin >> n >> m;

		for (i = 0; i < m; i++) {
			cin >> a >> b;
			adjacent[a][b] = 1;
			adjacent[b][a] = 1;
		}

		createQueue();

		enQueue(1);
		visited[1] = 1;

		while (isEmpty() == 0) {
			visitingVertex = deQueue();
			cout << visitingVertex;
			for (i = 1; i <= n; i++) {
				if (adjacent[visitingVertex][i] == 1 && visited[i] == 0) {
					enQueue(i);
					visited[i] = 1;
				}
			}
		}
		cout << endl;
	}
	return 0;
}

int isEmpty() {
	if (front == rear) return true;
	else return false;
}

int isFull() {
	if (rear == 10000) return true;
	else return false; 
}

void enQueue(int item) {
	if (isFull()) cout << "Full" << endl;
	else {
		rear++;
		queue[rear] = item;
	}
}

int deQueue() {
	if (isEmpty()) cout << "Empty" << endl;
	else {
		front++;
		return queue[front];
	}
}

void createQueue() {
	front = 0;
	rear = 0;
}

int Qpeek() {
	if (isEmpty()) cout << "Empty" << endl;
	else {
		return queue[front+1];
	}
}