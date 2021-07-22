class Solution {
    public int partitionDisjoint(int[] nums) {
        int startNum = nums[0];
        int leftMax = nums[0];
        int maxNum = nums[0];
        int endIdx = 0;
        for(int i=1;i<nums.length;i++){
            if(leftMax>nums[i]){
                leftMax = maxNum;
                endIdx = i;
            }
            else{
                if(maxNum < nums[i]) 
                    maxNum = nums[i];                    
            }
        }
        return endIdx+1;
    }
}