class Solution {
    int[][] arr;
    
    public int move(int r1, int c1, int r2, int c2){
        int temp = 0;
        int mini = 20000;
        temp = arr[r1][c1];
        for(int i=r1;i<r2;i++){
            arr[i][c1] = arr[i+1][c1];
            mini = mini > arr[i+1][c1] ? arr[i+1][c1] : mini;
        }
        
        for(int j=c1;j<c2;j++){
            arr[r2][j] = arr[r2][j+1];
            mini = mini > arr[r2][j+1] ? arr[r2][j+1] : mini;
        }
        
        for(int i=r2;i>r1;i--){
            arr[i][c2] = arr[i-1][c2];
            mini = mini > arr[i-1][c2] ? arr[i-1][c2] : mini;
        }
        for(int j=c2;j>c1;j--){
            arr[r1][j] = arr[r1][j-1];
            mini = mini > arr[r1][j-1] ? arr[r1][j-1] : mini;
        }
        arr[r1][c1+1] = temp;
        mini = mini > temp ? temp : mini;
        
        return mini;
    }
    
    public int[] solution(int rows, int columns, int[][] queries) {
        int[] answer = new int[queries.length];
        arr = new int[rows][columns];
        int cnt = 1;
        //arr 초기화
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                arr[i][j] = cnt++;
            }
        }
        
        for(int i=0;i<queries.length;i++){
            answer[i] = move(queries[i][0]-1, queries[i][1]-1, queries[i][2]-1, queries[i][3]-1);
        }
        return answer;
    }
}
