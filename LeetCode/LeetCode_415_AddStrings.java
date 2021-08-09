class Solution {
    public String addStrings(String num1, String num2) {
        int leng1 = num1.length();
        int leng2 = num2.length();
        
        StringBuffer answer = new StringBuffer();
        
        int next = 0, a, b;
        while(leng1>0 || leng2>0){
            a=0;
            b=0;
            if(leng1!=0){
                a = Integer.parseInt(num1.substring(leng1-1,leng1));
                leng1--;
            }
            if(leng2!=0){
                b = Integer.parseInt(num2.substring(leng2-1,leng2));
                leng2--;
            }
            answer.append(String.valueOf((next + a + b)%10));
            next = (next + a + b)/10;
        }    
        if(next!=0) answer.append(next);
        return answer.reverse().toString();
    }
}