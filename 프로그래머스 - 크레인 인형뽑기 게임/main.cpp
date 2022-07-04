#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <regex>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack < int > basket;
    for(int i=0; i<moves.size(); i++) {
        int next = moves[i] -1;
        for(int j=0; j<board.size(); j++) {
            if(board[j][next] == 0) continue;
            basket.push(board[j][next]);
            board[j][next] = 0;
            break;
        }
        if(basket.size() >= 2) {
            int one = basket.top();
            basket.pop();
            int two = basket.top();
            basket.pop();
            if(one == two) answer += 2;
            else {
                basket.push(two);
                basket.push(one);
            }
        }
    }
    return answer;
}

int main() {
    vector<vector<int>> v;
    vector < int > v2;
    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(3);
    v2.push_back(4);
    v.push_back(v2);
    v.push_back(v2);
    v[0][0] = 1;
    printf("%d %d\n",v[1][3], v.size());
    stack < int > s;
    s.push(1);
    printf("%d\n",s.top());
}