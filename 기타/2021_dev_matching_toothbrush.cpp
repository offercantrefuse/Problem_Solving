#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    map<string, string> people;
    map<string, int> profit; 
    
    for(int i=0;i<referral.size();i++){
        if(referral[i] == "-"){
            people.insert(pair<string, string>(enroll[i], "abcdefghijk"));
        }
        else {
            people.insert(pair<string, string>(enroll[i], referral[i]));
        }
        profit.insert(pair<string, int>(enroll[i], 0));
    }
    for(int i=0;i<seller.size();i++){
        int earn = amount[i] * 100;
        string kid = seller[i];
        
        while(kid!="abcdefghijk"){
            profit[kid] += earn - earn/10;
            earn = earn/10;
            if(earn==0) break;
            kid = people[kid];
        }
    }
    for(int i=0;i<enroll.size();i++){
        answer.push_back(profit[enroll[i]]);
    }
    
    return answer;
}
