import java.util.*;

class Solution {
    public int solution(int n, int k) {
        int answer = 0;
        StringBuffer sb = new StringBuffer();
        
        while(n>0){
            sb.append(n%k);
            n/=k;
        }
        String convertedStr = sb.reverse().toString();
        
        List<Long> cand = new ArrayList<Long>();
        
        int idx = 0;
        int newIdx;
        newIdx = convertedStr.indexOf("0", idx);
        while( (newIdx = convertedStr.indexOf("0", idx)) != -1){
            if(idx!=newIdx){
                long tmp = Long.parseLong(convertedStr.substring(idx, newIdx));
                if(tmp!=0)
                    cand.add(tmp);
            }
            idx = newIdx+1;
        }
        if(idx<convertedStr.length())
            cand.add(Long.parseLong(convertedStr.substring(idx)));
        
        for(long num:cand){
            if(isPrime3(num)){
                answer++;
            }
        }
        return answer;
    }
    
    public static boolean isPrime3(long num) {
        if(num==1) return false;
        if(num==2) return true;
        for (long i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) return false;
        }

        return true;
    }
}
