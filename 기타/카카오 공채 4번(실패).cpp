#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> food_times, long long k) {
	int answer = 0;
	vector<int> tmp;
	tmp = food_times;
	sort(tmp.begin(), tmp.end());
	if (food_times.size()*tmp[0] > k) {
		while (answer == 0) {
			int cnt = 0;
			for (int i = 0; i < food_times.size(); i++) {
				if (k == 0) {
					if (food_times[i] != 0) {
						answer = i + 1;
						break;
					}
					else continue;
				}
				else {
					if (food_times[i] == 0) {
						cnt++;
						continue;
					}
					else {
						food_times[i]--;
						k--;
					}
				}
			}
			if (cnt == food_times.size()) answer = -1;
		}
	}
	else {
		for (int i = 0; i < food_times.size(); i++) {
			food_times[i]-=tmp[0];
		}
		k -= food_times.size()*tmp[0];
		while (answer == 0) {
			int cnt = 0;
			for (int i = 0; i < food_times.size(); i++) {
				if (k == 0) {
					if (food_times[i] != 0) {
						answer = i + 1;
						break;
					}
					else continue;
				}
				else {
					if (food_times[i] == 0) {
						cnt++;
						continue;
					}
					else {
						food_times[i]--;
						k--;
					}
				}
			}
			if (cnt == food_times.size()) answer = -1;
		}
	}
	return answer;
}