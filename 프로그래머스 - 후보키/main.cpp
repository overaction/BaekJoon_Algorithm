#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>
using namespace std;

int visited[8];
int colNum;
vector <string> v;
vector <string> uniqueV;
unordered_map <string,int> uniqueMap;

void combination(int idx, int cnt, int size, string str) {
    if(cnt == size) {
        v.push_back(str);
        return;
    }
    for(int i=idx; i<colNum; i++) {
        if(visited[i] == 0) {
            visited[i] = 1;
            str += (i+'0');
            combination(i,cnt+1,size,str);
            str.pop_back();
            visited[i] = 0;
        }
    }
}

void minComb(int idx, int cnt, int size, string str, string value) {
    if(cnt == size) {
        uniqueV.push_back(str);
        return;
    }
    for(int i=idx; i<colNum; i++) {
        if(visited[i] == 0) {
            visited[i] = 1;
            str += value[i];
            minComb(i,cnt+1,size,str,value);
            str.pop_back();
            visited[i] = 0;
        }
    }
}

bool isUnique(string temp, vector<vector<string>> relation) {
    set < string > checkSet;
    for(int i=0; i<relation.size(); i++) {
        string s;
        for(int j=0; j<temp.size(); j++) {
            s += relation[i][temp[j]-'0'];
        }
        // 중복 체크
        auto it = checkSet.find(s);
        if(it == checkSet.end()) checkSet.insert(s);
        else return false;
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    colNum = relation[0].size();
    // 조합 구하기
    for(int i=1; i<=colNum; i++) {
        combination(0,0,i,"");
    }
    // 유일성 구하기, 결과 저장
    for(int i=0; i<v.size(); i++) {
        string now = v[i];
        bool result = isUnique(now,relation);
        uniqueMap[now] = result;
    }
    // 최소성 구하기
    for(int i=v.size()-1; i>=0; i--) {
        bool isAnswer = true;
        string now = v[i];
        // 유일성 안되면 패스
        if(uniqueMap[now] == 0) continue;
        // 조합 중에서 유일성 충족시키는게 있다면 실패
        for(int j=1; j<=now.size()-1; j++) {
            minComb(0,0,i,"",now);
        }
        for(int j=0; j<uniqueV.size(); j++) {
            if(uniqueMap[uniqueV[j]] == 1) {
                isAnswer = false;
                break;
            }
        }
        if(isAnswer) return now.size();
    }
}