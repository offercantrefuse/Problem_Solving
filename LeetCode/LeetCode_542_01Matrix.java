#include <queue>

int dr[] = { -1,0,1,0 };
int dc[] = { 0,-1,0,1 };

struct node {
    int r, c;
    node(int r, int c) : r(r), c(c) {}
    node() {}
};

class Solution {
public:

    int find(int row, int col, vector<vector<int>>& mat) {
        if (mat[row][col] == 0) {
            return 0;
        }
        else {
            int rSize = mat.size();
            int cSize = mat[0].size();
            int dist = 0;

            bool visit[rSize][cSize];
            memset(visit, 0, sizeof(visit));
            
            queue<node> q;
            q.push(node(row, col));
            visit[row][col] = 1;

            while (!q.empty()) {
                int qSize = q.size();
                dist++;
                for (int i = 0; i < qSize; i++) {
                    node now = q.front();
                    q.pop();
                    for (int d = 0; d < 4; d++) {
                        int nr = now.r + dr[d];
                        int nc = now.c + dc[d];

                        if (nr<0 || nc<0 || nr>rSize - 1 || nc>cSize - 1) continue;
                        if (mat[nr][nc] == 0) return dist;
                        else if (!visit[nr][nc]) {
                            q.push(node(nr, nc));
                            visit[nr][nc] = 1;
                        }
                    }           
                }            
            }
         }
        return 0;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> answer;
        vector<int> tmp;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                tmp.push_back(find(i, j, mat));
            }
            answer.push_back(tmp);
            tmp.clear();
        }
        return answer;
    }
};