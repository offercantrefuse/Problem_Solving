#include <iostream>

using namespace std;

int main() {

	int i,j;
	int arr[] = { -7,-3,-2,5,8 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int sum;

	int ret = 0;
	for (i = 1; i < (1 << (n)); i++) {
		sum = 0;
		for (j = 0; j < n; j++) {
			if (i&(1 << j)) {
				sum += arr[j];
			}
		}
		if (sum == 0) {
			ret = 1;
			break;
		}
	}
	ret ? cout << "True" : cout << "False" << endl;


	return 0;
}
	
	