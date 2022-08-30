#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
	
	stack <int> s;
	int now;
	for(int i=0; i<arr.size(); i++) {
		if(s.empty() || s.top() != arr[i]) {
			s.push(arr[i]);
			now = arr[i];
		}
		else if(s.top() == now) continue;

	}
	while(!s.empty()) {
        answer.push_back(s.top());
		printf("%d\n",s.top());
        s.pop();
    }
    return answer;
}

int main() {
	vector <int> arr;
	arr.push_back(1);
	arr.push_back(1);
	arr.push_back(3);
	arr.push_back(3);
	arr.push_back(0);
	arr.push_back(1);
	solution(arr);
}