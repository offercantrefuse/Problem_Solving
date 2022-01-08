class Solution {
    public int[] solution(int[] lottos, int[] win_nums) {
        int[] answer = {};
        int zeroCnt = 0;
        int winCnt = 0;
        for(int i=0;i<lottos.length;i++){
            if(lottos[i] == 0){
                zeroCnt++;
            }         
            for(int j=0;j<win_nums.length;j++){
                if(lottos[i] == win_nums[j]){
                    winCnt++;
                    break;
                }
            }
        }
        answer = new int[2];
        
        answer[0] = (7 - (winCnt + zeroCnt)) == 7 ? 6 : 7 - (winCnt + zeroCnt);
        answer[1] = (7 - winCnt) == 7 ? 6 : 7 - winCnt;
        return answer;
    }
}

