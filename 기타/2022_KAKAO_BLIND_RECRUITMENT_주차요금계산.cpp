#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
 
    return answer;
}

int calcTm(string stTm, string edTm){
    string startHr = stTm.substr(0,2);
    string startMin = stTm.substr(3);
    string endHr = edTm.substr(0,2);
    string endMin = edTm.substr(3);
        
    return (60*(stoi(endHr)-stoi(startHr))) + (stoi(endMin) - stoi(startMin));
}

int calcFee(int pkTm, vector<int> fees){
    if(pkTm <= fees[0]){
        return fees[1];
    }
    if((pkTm - fees[0])%fees[2] == 0){
        return fees[1] + ((pkTm - fees[0])/fees[2] * fees[3]);
    }
    else {
        return fees[1] + (((pkTm - fees[0])/fees[2] + 1) * fees[3]);
    }
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, string> car;
    map<string, int> parkTime;
    map<string, int> feeTotal;
    
    for(int i=0;i<records.size();i++){
        vector<string> info = split(records[i],' ');
        if(car.find(info[1]) != car.end()){
            if(parkTime.find(info[1]) != parkTime.end()){
                parkTime[info[1]] += calcTm(car[info[1]], info[0]);       
            }
            else {
                parkTime.insert(make_pair(info[1], calcTm(car[info[1]], info[0])));
            }
            car.erase(car.find(info[1]));
        }
        else {
            car.insert(make_pair(info[1], info[0]));
        }
    }
    auto iter = car.begin();
    while(iter != car.end()){
        if(parkTime.find(iter->first) != parkTime.end()){
            parkTime[iter->first] += calcTm(iter->second, "23:59");
        }
        else {
            parkTime.insert(make_pair(iter->first, calcTm(iter->second, "23:59")));
        }
        iter++;
    }
    
    auto it = parkTime.begin();
    while(it != parkTime.end()){
        feeTotal.insert(make_pair(it->first, calcFee(it->second, fees)));
        it++;
    }
    
    auto ansIt = feeTotal.begin();
    while(ansIt != feeTotal.end()){
        answer.push_back(ansIt->second);
        ansIt++;
    }

    
    return answer;
}
