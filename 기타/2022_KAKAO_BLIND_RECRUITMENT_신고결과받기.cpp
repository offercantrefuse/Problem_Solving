#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    int rptd[1000][1000] = {0,};
    int voted[1000] = {0, };
    map<string, int> id_num;
    for(int i=0; i<id_list.size(); i++){
        // map (아이디, 번호)
        id_num.insert(make_pair(id_list[i], i));
    } 
    for(int i=0;i<report.size();i++){
        string reporter = report[i].substr(0,report[i].find(" "));
        string rptedPerson = report[i].substr(report[i].find(" ")+1);
        auto iter1 = id_num.find(reporter);
        auto iter2 = id_num.find(rptedPerson);
        if(rptd[iter1->second][iter2->second] == 0){
            rptd[iter1->second][iter2->second] = 1;  
            voted[iter2->second]++;
        }
    }    
    for(int i=0;i<id_list.size();i++){
        int cnt = 0;
        for(int j=0;j<id_list.size();j++){
            if(rptd[i][j]==1){
                if(voted[j] >= k) 
                    cnt++;
            }
        }
        answer.push_back(cnt);
    }
    
    return answer;
}