#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <regex>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map < string, string > matchMap;
    vector < pair < string, string > > test;
    for(int i=0; i<record.size(); i++) {
        string now = record[i];
        int blankIdx1 = now.find(" ");
        int blankIdx2 = now.find(" ",blankIdx1+2);
        string id = now.substr(blankIdx1+1,blankIdx2-blankIdx1-1);
        string name = now.substr(blankIdx2+1);
        
        // Enter
        if(now[0] == 'E') {
            test.push_back({"Enter", id});
            matchMap[id] = name;
        }
        // Leave
        else if(now[0] == 'L') {
            id = now.substr(blankIdx1+1);
            test.push_back({"Leave", id});
        }
        // Change
        else if(now[0] == 'C') {
            matchMap[id] = name;
        }
    }

    for(int i=0; i<test.size(); i++) {
        string type = test[i].first;
        string id = test[i].second;
        if(type == "Enter")
            answer.push_back(matchMap[id]+"님이 들어왔습니다.");
        else if(type == "Leave")
            answer.push_back(matchMap[id]+"님이 나갔습니다.");
    }

    return answer;
}

int main() {
	vector < string > test;
    test.push_back("Enter uid1234 Muzi");
    test.push_back("Enter uid4567 Prodo");
    test.push_back("Leave uid1234");
    test.push_back("Enter uid1234 Muzi");
    test.push_back("Enter uid1234 Muzi");
    solution(test);
}