#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
	vector < int > completed;
	for(int i=0; i<progresses.size(); i++) {
		int temp = (100-progresses[i]) / speeds[i];
		if(temp * speeds[i] < 100-progresses[i]) temp += 1;
		completed.push_back(temp);
	}

	int tasks = completed[0];
	int res = 1;
	for(int i=1; i<completed.size(); i++) {
		if(tasks >= completed[i]) res++;
		else {
			answer.push_back(res);
			res = 1;
			tasks = completed[i];
		}
	}
	answer.push_back(res);
    return answer;
}
