#include <string>
#include <vector>

using namespace std;

bool solution(vector<int> arrA, vector<int> arrB) {
    bool answer = false;
    if(arrA.size()!= arrB.size()) {
        answer = false;
        return answer;
    }
    int size = arrA.size();
    for(int t=0;t<size;t++){
        int tmp = 0;
        tmp=arrA[size-1];
        for(int i=size-1;i>0;i--){
            arrA[i]=arrA[i-1];
        }
        arrA[0] = tmp;
        if(arrA==arrB){
            answer= true;
            return answer;
        }
    }
    return answer;
}