#include <iostream>
using namespace std;

int atom[1000][4];
int visit[4005][4005];
bool collided[4005][4005];

void remove_atom(int n, int *pnSize) {
	int nLastIndex = (*pnSize) - 1;
	atom[n][0] = atom[nLastIndex][0];
	atom[n][1] = atom[nLastIndex][1];
	atom[n][2] = atom[nLastIndex][2];
	atom[n][3] = atom[nLastIndex][3];
	(*pnSize)--;
}
int solution(int N) {
	int nRest = N;
	int ans = 0;

	for (int j = 0; j < nRest; j++) {
		atom[j][0] = atom[j][0] * 2;
		atom[j][1] = atom[j][1] * 2;
		visit[atom[j][0]][atom[j][1]]++;
	}

	int nMaxLoop = 4002;
	for (int i = 0; i < nMaxLoop; i++) {
		for (int j = 0; j < nRest; j++) {
			int &x = atom[j][0];
			int &y = atom[j][1];
			int d = atom[j][2];
			visit[x][y]--;
			if (d == 0) y++;
			else if (d == 1) y--;
			else if (d == 2) x--;
			else if (d == 3) x++;

			if (atom[j][0] < 0 || atom[j][0] > 4000 || atom[j][1] < 0 || atom[j][1] > 4000) {
				remove_atom(j, &nRest);
				j--;
			}
			else {
				visit[x][y]++;
				if (visit[x][y] >= 2) collided[x][y] = true;
			}
		}
		for (int j = 0; j < nRest; j++) {
			int x = atom[j][0]; 
			int y = atom[j][1];
			if (collided[x][y] == 1) {
				if (visit[x][y] == 1) collided[x][y] = false;
				visit[x][y]--;
				ans += atom[j][3];
				remove_atom(j, &nRest);
				j--;			
			}
		}
		if (nRest == 0) break;
	}
	return ans;
}

int main() {
	int T, N;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> atom[i][0] >> atom[i][1] >> atom[i][2] >> atom[i][3];
			atom[i][0] += 1000;
			atom[i][1] += 1000;
		}
		int nRes = solution(N);
		cout << "#" << tc << ' ' << nRes << '\n';
	}
	return 0;
}