#include <iostream>
#include <vector>
using namespace std;
struct pos {
	int x, y, energy, dir;
	pos(int x, int y, int energy, int dir) :x(x), y(y), energy(energy), dir(dir) {}
	pos() {}
};
struct node {
	int x, y;
	node(int x, int y) : x(x), y(y) {}
	node() {}
};
int T, N, K;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
vector<pos> atom;
vector<node> vis;
int visit[4001][4001];
int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			int x, y, energy, dir;
			cin >> x >> y >> dir >> energy;
			atom.push_back(pos(2 * x, 2 * y, energy, dir));
		}
		int time = 0;
		int ans = 0;
		while (time <= 8001 && !atom.empty()) {
			for (int i = 0; i < atom.size(); i++) {
				int nx = atom[i].x + dx[atom[i].dir];
				int ny = atom[i].y + dy[atom[i].dir];
				if (nx < -2000 || nx>2000 || ny < -2000 || ny>2000) {  // 범위 밖 소멸
					atom.erase(atom.begin() + i);
					i--;
					continue;
				}
				atom[i].x = nx;
				atom[i].y = ny;
				visit[ny + 2000][nx + 2000]++;
			}
			for (int i = 0; i < atom.size(); i++) {   // visit 2 이상 -> 충돌
				if (visit[atom[i].y + 2000][atom[i].x + 2000] >= 1) {
					vis.push_back(node(atom[i].x, atom[i].y));
					if (visit[atom[i].y + 2000][atom[i].x + 2000] > 1) {
						ans += atom[i].energy;
						atom.erase(atom.begin() + i);
						i--;
					}
				}
			}
			for (int i = 0; i < vis.size(); i++) {  // visit 클리어
				visit[vis[i].y + 2000][vis[i].x + 2000] = 0;
			}
			vis.clear();
			time++;
		}
		cout << '#' << tc << ' ' << ans << '\n';
		atom.clear();
	}

	return 0;
}