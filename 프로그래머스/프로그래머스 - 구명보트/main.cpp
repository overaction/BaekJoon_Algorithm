#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(),people.end());
    int answer = 0;
    int head = 0, tail = people.size()-1;
    while(head <= tail) {
        // 양 끝의 합이 최댓값보다 같거나 작다면
        if(people[head] + people[tail] <= limit) {
            head++, tail--;
        }
        else {
            tail--;
        }
        answer++;
    }
    return answer;
}