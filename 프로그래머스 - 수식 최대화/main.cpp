#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

long long answer = 0;
bool checked[3];
vector <char> priority;
vector <char> ops;
vector <long long> nums;
unordered_map <int, char> opMap;

long long calc(char op, long long a, long long b) {
	if(op == '+') return a+b;
	if(op == '-') return a-b;
	if(op == '*') return a*b;
}

long long calculation() {
	// 계산을 위해 임시 저장
	vector <char> tempOps = ops;
	vector <long long> tempNums = nums;
	for(int i=0; i<priority.size(); i++) {
		char now = priority[i];
		for(int j=0; j<tempOps.size(); j++) {
			if(now == tempOps[j]) {
				long long res = calc(now,tempNums[j],tempNums[j+1]);
				tempNums.erase(tempNums.begin()+j+1);
				tempNums[j] = res;
				tempOps.erase(tempOps.begin()+j);
				j--;
			}
		}
	}
	return abs(tempNums[0]);
}

void dfs(int cnt) {
	if(cnt == 3) {
		long long res = calculation();	
		answer = (answer > res) ? answer : res;
		return;
	}
	for(int i=0; i<3; i++) {
		if(checked[i] == false) {
			checked[i] = true;
			priority.push_back(opMap[i]);
			dfs(cnt+1);
			priority.pop_back();
			checked[i] = false;
		}
	}
}

long long solution(string expression) {
    answer = 0;
	// 숫자와 문자 나누기
	int start = 0, cnt = 0;
	for(int i=0; i<expression.size(); i++) {
		if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
			ops.push_back(expression[i]);
			string num = expression.substr(start,cnt);
			nums.push_back(stoi(num));
			start = i+1;
			cnt = 0;
		}
		else cnt++;
	}
	string num = expression.substr(expression.size() - cnt);
	nums.push_back(stoi(num));
	// map 기록
	opMap[0] = '+';
	opMap[1] = '-';
	opMap[2] = '*';
	cout<< ops[2] << nums[3] << endl;
	// 순열탐색 및 결과 찾기
	dfs(0);
    return answer;
}

int main() {
	cout << solution("50*6-3*2");
}