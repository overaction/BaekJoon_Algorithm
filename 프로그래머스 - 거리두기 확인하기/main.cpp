#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

typedef struct op {
	int seat,y,x;
}op;

int bfs(vector<vector<string>> places, int idx) {
	queue < op > q;
	for(int i=0; i<5; i++) {
		for(int j=0; j<5; j++) {
			
		}
	}
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
	for(int i=0; i<places.size(); i++) {
		answer.push_back((places,i));
	}
    return answer;
}