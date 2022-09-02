#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int checked[8];
vector < pair <int,int > > v;
int answer = 0;
int tired = 0;

// 클리어 가능한 던전 개수 구하기
int calculate() {
    int nowTired = tired;
    int cleared = 0;
    for(int i=0; i<v.size(); i++) {
        if(v[i].first <= nowTired) {
            nowTired -= v[i].second;
            cleared++;
        }
        // 피로도 부족 시 리턴
        else return cleared;
    }
    return cleared;
}

// 순열 구하기
void perm(int idx, int cnt, int max, vector<vector<int>> dungeons) {
    if(cnt == max) {
        int temp = calculate();
        answer = (answer > temp) ? answer : temp; 
        return;
    }
    for(int i=0; i<max; i++) {
        if(checked[i] == 0) {
            checked[i] = 1;
            v.push_back({dungeons[i][0], dungeons[i][1]});
            perm(i,cnt+1,max,dungeons);
            v.pop_back();
            checked[i] = 0;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    tired = k;
    perm(0,0,dungeons.size(),dungeons);
    return answer;
}