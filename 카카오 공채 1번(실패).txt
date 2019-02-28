#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

vector<string> answer;
vector<string> solution(vector<string> record) {
	vector<pair<pair<string, string>, int>> user;
	for (int i = 0; i < record.size(); i++) {  // vector( (id, 닉넴), inout)   //   Enter =1 , leave = 2
		if (record[i] == "\"Enter") {
			bool flag = true;
			for (int j = 0; j < user.size(); j++) {
				if (record[i + 1] == user[j].first.first) {
					flag = false;
					user[j].first.second = record[i + 2].erase(record[i + 2].length() - 2, record[i + 2].length() - 1);
				}
			}
			if (flag) {
				user.push_back(make_pair(make_pair(record[i + 1], record[i + 2].erase(record[i + 2].length() - 2, record[i + 2].length() - 1)), 1));
			}
			i += 2;
		}
		else if (record[i] == "\"Change") {
			for (int j = 0; j < user.size(); j++) {
				if (record[i + 1] == user[j].first.first) {
					user[j].first.second = record[i + 2].erase(record[i + 2].length() - 2, record[i + 2].length() - 1);
				}
			}
			i += 2;
		}
		else if (record[i] == "\"Leave") {
			for (int j = 0; j < user.size(); j++) {
				if (record[i + 1] == user[j].first.first) {
					user.push_back(make_pair(make_pair(record[i + 1], record[i + 2].erase(record[i + 2].length() - 2, record[i + 2].length() - 1)), 2));
				}
			}
			i += 2;

		}
	}
	for (int i = 0; i < user.size(); i++) {
		if (user[i].second == 1) {
			if (i != user.size() - 1) {
				answer.push_back(user[i].first.second);
				answer.push_back("님이 들어왔습니다.\",");
			}
			else {
				answer.push_back(user[i].first.second);
				answer.push_back("님이 들어왔습니다.\"");
			}
		}
		if (user[i].second == 2) {
			if (i != user.size() - 1) {
				answer.push_back(user[i].first.second);
				answer.push_back("님이 나갔습니다.\",");
			}
			else {
				answer.push_back(user[i].first.second);
				answer.push_back("님이 나갔습니다.\"");
			}
		}
	}
	return answer;
}
int main() {
	string s, w;
	vector<string> word;
	getline(cin, s);                     /// 공백을 포함한 문자열 입력
	for (stringstream sts(s); (sts >> w);) {  /// 문자열 s로 만들어진 문자열 스트림 sts생성
											  /// 문자열 스트림 sts를 이용하여 한 단어씩 w에 입력
											  /// sts에 남은 단어가 없다면 NULL 반환
		word.push_back(w);               /// 단어 w를 word에 추가
	}


	solution(word);
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i];
	}
	return 0;
}