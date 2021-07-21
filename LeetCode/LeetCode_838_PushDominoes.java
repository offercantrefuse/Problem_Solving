class Solution {
    StringBuffer sb = new StringBuffer();
    boolean endProcess = false;
    
    public void manageDomino(int state, int nextState, int start, int end){
        int leng = end-start+1;
        if(state==0 && nextState==0){ //>>
            for(int i=0;i<leng;i++){
                sb.append("R");
            }
        }
        else if(state==0 && nextState==2){  //><
        	leng = leng-1;
        	sb.append("R");
            for(int i=0;i<leng/2;i++){
                sb.append("R");
            }
            if(leng%2 == 1)
                sb.append(".");
            for(int i=0;i<leng/2;i++){
                sb.append("L");
            }
        }
        else if(state==1 && nextState==0){  //.>
            for(int i=0;i<leng;i++)
                sb.append(".");
        }
        else if(state==1 && nextState==2){  //.<
            for(int i=0;i<leng;i++)
                sb.append("L");
        }
        else if(state==2 && nextState==0){  //<>
            sb.append("L");
            for(int i=0;i<leng-1;i++)
                sb.append(".");
        }
        else if(state==2 && nextState==2){  //<<
            for(int i=0;i<leng;i++)
               sb.append("L");
        }        
        else if(nextState==3){
            if(state==0){
                for(int i=0;i<leng;i++)
                    sb.append("R");        
            }
            else if(state==1){
                for(int i=0;i<leng;i++)
                    sb.append(".");
            }
            else if(state==2){
                sb.append("L");
                for(int i=0;i<leng-1;i++)
                    sb.append(".");
            }
        }
    }
    
    public String pushDominoes(String dominoes) {
        int length = dominoes.length();
        int state=0, start=0, end=0, nextState=0;        
        
        if(dominoes.charAt(0)=='R')
            state = 0;
        else if(dominoes.charAt(0)=='.')
            state = 1;
        else
            state = 2;
        
        for(int i=1;i<length;i++){
            while(i<length && dominoes.charAt(i)=='.'){
                end = i++;
            }
            if(i>=length){
            	manageDomino(state, 3, start, end);
            	endProcess =true;
            }                
            else{
                //사이 처리
                if(dominoes.charAt(end+1) == 'R')
                    nextState = 0;
                else 
                    nextState = 2;
                manageDomino(state, nextState, start, end);
                state = nextState;
                start = end+1;
                end = end+1;
            }
        }
        if(!endProcess) {
        	sb.append(dominoes.charAt(length-1));
        }
        return sb.toString();
    }
}