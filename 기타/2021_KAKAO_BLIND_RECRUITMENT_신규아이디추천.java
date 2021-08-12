class Solution {
    public String solution(String new_id) {
        String answer = "";             
        
        // step1
        answer = new_id.toLowerCase();
        
        // step2 
        StringBuffer stepTwoSb = new StringBuffer();
        int length = answer.length();
        
        for(int i=0;i<length;i++){
            char curChar = answer.charAt(i);
            if( (curChar>='a' && curChar<='z')      // a~z
                || (curChar>='0' && curChar<='9')   // 0~9
                || curChar=='-' || curChar=='_' || curChar=='.')
                stepTwoSb.append(curChar);              
        }
        answer = stepTwoSb.toString();
        
        // step3        
        for(int i=0;i<10;i++){  // .이 최대 1000개라고 해도 2^10 = 1024 이하에 압축 가능
            answer = answer.replace("..",".");
        }
        
        // step4
        length = answer.length();
        int startIdx = 0;
        while(startIdx<length){
            if(answer.charAt(startIdx)!='.')
                break;
            startIdx++;
        }
        int endIdx = length-1;
        while(endIdx>=0){
            if(answer.charAt(endIdx)!='.')
                break;
            endIdx--;
        }   
        if(endIdx < startIdx) answer = "";
        else answer = answer.substring(startIdx, endIdx+1);

        // step5
        if(answer=="") answer = "a";

        // step6
        if(answer.length() >= 16){
            answer = answer.substring(0,15);
            endIdx = answer.length()-1;
            while(endIdx>=0){
                if(answer.charAt(endIdx)!='.')
                    break;
                endIdx--;
            }
            answer = answer.substring(0,endIdx+1);
        }
        
        // step7
        length = answer.length();
        StringBuffer stepSevenSb = new StringBuffer();
        stepSevenSb.append(answer);
        String insChar = "";
        if(length <= 2){
             insChar = answer.substring(length-1,length);            
             for(int i=0;i<3-length;i++){
                stepSevenSb.append(insChar);
             }             
        }
        answer = stepSevenSb.toString();
               
        return answer;
    }
}