#include <iostream>
#include <vector>
#include <string>
using namespace std;
int N1, N2, T;
string ant_tmp, ant_left, ant_right;
struct node {
	char s;
	int dir;  // 오 이동: -1, 왼 이동: 1
	node(char s, int dir) : s(s), dir(dir) {}
	node() {}
};
vector<node> left_node;
vector<node> right_node;
vector<node> ant;

void swap(int a, int b) {
	node tmp = ant[a];
	ant[a] = ant[b];
	ant[b] = tmp;
}

int main() {
	cin >> N1 >> N2 >> ant_left >> ant_right >> T;
	int head = ant_left.length() - 1;
	for (int i = ant_left.length() - 1; i >= 0; i--)
		left_node.push_back(node(ant_left[i], -1));
	for (int i = 0; i < ant_right.length(); i++)
		right_node.push_back(node(ant_right[i], 1));
	// ant 에 합치기
	ant.reserve(left_node.size() + right_node.size());
	ant.insert(ant.end(), left_node.begin(), left_node.end());
	ant.insert(ant.end(), right_node.begin(), right_node.end());

	for (int tc = 0; tc < T; tc++) { // T번 시행
		for (int i = 0; i < ant.size() - 1; i++) {
			if (ant[i].dir == -1 && ant[i + 1].dir == 1) {
				swap(i, i + 1);
				i++;
			}
		}
	}

	for (auto ans : ant) {
		cout << ans.s;
	}
	return 0;
}