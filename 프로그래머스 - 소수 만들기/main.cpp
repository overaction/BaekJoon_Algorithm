#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int answer;
bool checked[50];

bool checking(int num) {
    if(num < 2) return false;
    int temp = (int) sqrt(num);
    for(int i=2; i<=temp; i++) {
        if(num % i == 0) return false;
    }
    return true;
} 

void dfs(int cnt, int idx, vector<int> nums) {
    if(cnt == 3) {
        int hap = 0;
        for(int i=0; i<nums.size(); i++) {
            if(checked[i]) hap += nums[i];
        }
        if(checking(hap)) answer++;
        return;
    }
    for(int i=idx; i<nums.size(); i++) {
        if(checked[i]) continue;
        checked[i] = true;
        dfs(cnt+1,i,nums);
        checked[i] = false;
    }
}

int solution(vector<int> nums) {
    answer = 0;

    dfs(0,0,nums);

    return answer;
}