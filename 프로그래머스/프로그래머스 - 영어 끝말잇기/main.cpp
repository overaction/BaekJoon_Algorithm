#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map <string,int> m;
    m[words[0]] = 1;

    int idx = 0;
    int cnt = 0;
    for(int i=1; i<words.size(); i++) {
        // 탈락자 발생
        if(m[words[i]] == 1 || words[i-1].back() != words[i][0]) {
            idx = ((i+1) % n) == 0 ? n : ((i+1)%n);
            cnt = ((i+1) % n) == 0 ? (i+1)/n : (i+1)/n + 1;
            answer.push_back(idx);
            answer.push_back(cnt);
            return answer;
        }
        m[words[i]]++;
    }
    answer.push_back(idx);
    answer.push_back(cnt);
    return answer;
}