#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <regex>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    map<int,int> win_map;
    int zeroCnt = 0;
    int minimum = 0;
    for(int i=0; i<6; i++) {
        win_map[win_nums[i]] = 1;
    }
    for(int i=0; i<6; i++) {
        if(lottos[i] == 0) zeroCnt++;
        else if(win_map[lottos[i]] == 1) minimum++;
    }
    (minimum+zeroCnt == 0) ? answer.push_back(6) : answer.push_back(7-(minimum+zeroCnt));
    (minimum == 0) ? answer.push_back(6) : answer.push_back(7-minimum);
    return answer;
}

int main() {

}