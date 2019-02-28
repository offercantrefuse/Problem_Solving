#include <iostream>

using namespace std;

int main() {

	int data[100] = { 0 };
	int dump;
	int result[10] = { 0 };

	for (int t = 0; t < 10; t++) {
		cin >> dump;

		for (int i = 0; i < 100; i++) {
			cin >> data[i];
		}

		for (int n = 0; n < dump; n++) {
			int min, max;
			min = data[0];
			max = data[0];

			int low, high;

			for (int j = 0; j < 100; j++) {
				if (min >= data[j]) {
					min = data[j];
					low = j;
				}
				if (max <= data[j]) {
					max = data[j];
					high = j;
				}
			}
			data[low]++;
			data[high]--;
		}

		int min, max;
		min = data[0];
		max = data[0];

		int low, high;


		for (int j = 0; j < 100; j++) {
			if (min >= data[j]) {
				min = data[j];
				low = j;
			}
			if (max <= data[j]) {
				max = data[j];
				high = j;
			}
		}

		result[t] = data[high] - data[low];
		cout << result[t] << endl;
	}

	return 0;

}