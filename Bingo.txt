#include <iostream>

using namespace std;

int sel_min(int arr[][5]) {

	int min = 0;
	int minX = 0, minY = 0;
	int i, j;
	
	min = arr[0][0];
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			if (min > arr[i][j]) {
				min = arr[i][j];
				minX = i;
				minY = j;
			}
		}
	}
	arr[minX][minY] = 26;
	return min;
}


void main() {

	int arr[][5] = {
		{9,20,2,18,11},
		{19,1,25,3,21},
		{8,24,10,17,7},
		{15,4,16,5,6},
		{12,13,22,23,14}
	};

	int sorted_ary[5][5] = { 0 };
	int cur_min = -1;
	int X, Y;
	int newX = 0, newY = 0;

	int dy[] = { 1,0,-1,0 };
	int dx[] = { 0,1,0,-1 };
	int dir_state = 0;

	for (int i = 0; i < 25; i++) {

		cur_min = sel_min(arr);
		X = newX;
		Y = newY;
		sorted_ary[X][Y] = cur_min;

		newX = X + dx[dir_state];
		newY = Y + dy[dir_state];

		if (sorted_ary[newX][newY] != 0 || newX > 4 || newY > 4) {
			dir_state = (dir_state + 1) % 4;
			newX = X + dx[dir_state];
			newY = Y + dy[dir_state];
		}

	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			
			cout << sorted_ary[i][j] << " ";
		}
		cout << endl;

	}

}

