#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool cmp(pair <double,int> a, pair <double,int> b) {
	if(a.first == b.first) return a.second < b.second;
	else return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
	// 맵마다 도전 후 성공한 횟수
	unordered_map <int,int> success;
	unordered_map <int,int> failure;
	for(int i=0; i<stages.size(); i++) {
		for(int j=1; j<stages[i]; j++) {
			success[j]++;
		}
		if(stages[i] == N+1) continue;
        failure[stages[i]]++;
	}

	vector <pair <double,int > > sortV;
	for(int i=0; i<N; i++) {
		if((success[i+1] + failure[i+1]) == 0) sortV.push_back({0,i+1});
		else {
            double temp = (double)failure[i+1]/(success[i+1]+failure[i+1]);
            sortV.push_back({temp,i+1});
        }
    }
    
	sort(sortV.begin(), sortV.end(), cmp);
	for(int i=0; i<sortV.size(); i++) answer.push_back(sortV[i].second);
    return answer;
}