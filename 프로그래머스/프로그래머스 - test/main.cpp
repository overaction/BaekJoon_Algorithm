#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector <int> v;

int solution() {
    vector <int> answer;
    answer.push_back(v[0]);
    for(int i=1; i<v.size(); i++) {
        int next = v[i];
        if(answer.back() < next)
            answer.push_back(next);
        else {
            auto itr = lower_bound(answer.begin(),answer.end(),next);
            *itr = next;
        }
    }
    return answer.size();
}

int main() {
    int N,num;
    scanf("%d",&N);
    for(int i=0; i<N; i++) {
        scanf("%d",&num);
        v.push_back(num);
    }
    printf("%d\n",solution());
}