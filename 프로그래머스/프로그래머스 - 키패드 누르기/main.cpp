#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <regex>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int ly = 3, lx = 0, ry = 3, rx = 2;
    int y,x;
    for(int i=0; i<numbers.size(); i++) {
        if(numbers[i] == 0) {
            y = 3, x = 1;
        }
        else {
            x = ((numbers[i] % 3 - 1) < 0) ? 2 : (numbers[i] % 3 - 1);
            if(numbers[i] <= 3) y = 0;
            else if(numbers[i] <= 6) y = 1;
            else y = 2;
        }
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            answer += "L";
            ly = y, lx = x;
        }
        else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            answer += "R";
            ry = y, rx = x;
        }
        else {
            if(abs(ly - y) + abs(lx - x) > abs(ry - y) + abs(rx - x)) {
                answer += "R";
                ry = y, rx = x;
            }
            else if(abs(ly - y) + abs(lx - x) < abs(ry - y) + abs(rx - x)) {
                answer += "L";
                ly = y, lx = x;
            }
            else {
                if(hand == "right") {
                    answer += "R";
                    ry = y, rx = x;
                }
                else {
                    answer += "L";
                    ly = y, lx = x;
                }
            }
        }
    }
    return answer;
}

int main() {
    vector < int > test;
    test.push_back(1);
    test.push_back(3);
    test.push_back(4);
    test.push_back(5);
    test.push_back(8);
    test.push_back(2);
    test.push_back(1);
    test.push_back(4);
    test.push_back(5);
    test.push_back(9);
    test.push_back(5);
    solution(test,"right");
}