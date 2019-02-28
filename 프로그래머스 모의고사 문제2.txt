#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(int l, vector<int> v) {
   // int answer = 0;
    int size = v.size();
    sort(v.begin(),v.end());
    int num1 = v[0];
    int num2 = l- v[size-1];
    int maxi =0;
    maxi= num1>num2? num1:num2;
    for(int i=0;i<size-1;i++){
        int dif = v[i+1]-v[i];
        if(dif%2==0) dif /= 2;
        else dif = (dif+1)/2;
        maxi = maxi>dif? maxi:dif;
    }
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다. 
    cout << maxi << endl;

    return maxi;
}