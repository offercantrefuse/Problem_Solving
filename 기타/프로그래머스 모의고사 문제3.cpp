#include <vector>
using namespace std;
struct pos{
    int r,c;
    pos(int r, int c): r(r),c(c){}
    pos(){}
};
pos visit[250001];
int bingorow[501] = {0,};
int bingocol[501] = {0,};
int bingodia1 = 0;
int bingodia2 = 0;
int solution(vector<vector<int>> board, vector<int> nums) {
    int answer = 0;
    int size = board.size();
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            visit[board[i][j]]= pos(i,j);
        }
    }
    for(int i=0;i<nums.size();i++){
        bingorow[visit[nums[i]].r]++;
        bingocol[visit[nums[i]].c]++;
        if(visit[nums[i]].r == visit[nums[i]].c) bingodia1++;
        if((visit[nums[i]].r+visit[nums[i]].c)==size-1) bingodia2++;
    }
    for(int i=0;i<size;i++){  // 가로 세로
        if(bingorow[i]==size) answer++;
        if(bingocol[i]==size) answer++;
    }
    if(bingodia1 == size) answer++;
    if(bingodia2 == size) answer++;
    
    return answer;
}