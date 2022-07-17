#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

/*
	+ 0
	- 1
	* 2
*/
int checked[3];
vector <long long> numbers;
unordered_map <int, char> opMap;
vector <char> priority, op;
long long answer = 0;

long long opCalc(char op, long long a, long long b) {
	if(op == '+') return a+b;
	if(op == '-') return a-b;
	if(op == '*') return a*b;
}

long long calculation() {
	vector<char> tempOp = op;
	vector<long long> tempNum = numbers;
	for(int i=0; i<priority.size(); i++) {
		char now = priority[i];
		for(int j=0; j<tempOp.size(); j++) {
			if(now == tempOp[j]) {
				long long first = tempNum[j];
				long long second = tempNum[j+1];
				long long res = opCalc(now,first,second);

				tempNum[j] = res;
				tempNum.erase(tempNum.begin()+j+1);
				tempOp.erase(tempOp.begin()+j);
				j--;
			}
		}
	}
	return abs(tempNum[0]);
}

void dfs(int cnt) {
	if(cnt == 3) {
		long long res = calculation();
		answer = (answer > res) ? answer : res;
		return;
	}
	for(int i=0; i<3; i++) {
		if(checked[i]) continue;
		checked[i] = 1;
		priority.push_back(opMap[i]);
		dfs(cnt+1);
		priority.pop_back();
		checked[i] = 0;
	}
}

long long solution(string expression) {
    answer = 0;
	int start = 0;
	int cnt = 0;
	for(int i=0; i<expression.size(); i++) {
		if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
			op.push_back(expression[i]);
			string num = expression.substr(start,cnt);
			numbers.push_back(stoi(num));
			start = i+1;
			cnt = 1;
		}
		cnt++;
	}
	numbers.push_back(stoi(expression.substr(expression.size() - cnt + 2)));
	opMap[0] = '+';
	opMap[1] = '-';
	opMap[2] = '*';

	dfs(0);
    return answer;
}

int main() {
	cout << solution("100-200*300-500-20");
}