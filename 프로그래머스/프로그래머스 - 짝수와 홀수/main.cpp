#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(int num) {
    return (abs(num)%2 == 1) ? "Odd" : "Even";
}

int main() {
    cout << solution(-3) << endl;
}