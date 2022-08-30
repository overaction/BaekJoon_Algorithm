#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
vector <char> nums;
bool visited[7];
unordered_set < int > s;

bool check(string snum) {
	int n = stoi(snum);
	if(n<2) return false;
	for(int i=2; i*i<=n; i++) {
		if(n % i == 0) return false;
	}
	return true;
}

void selecting(int idx, int cnt, int size, string snum) {
	if(cnt == size) {
		if(check(snum)) s.insert(stoi(snum));
		return;
	}
	for(int i=0; i<nums.size(); i++) {
		if(visited[i] == false) {
			visited[i] = true;
			snum += nums[i];
			selecting(i,cnt+1,size,snum);
			snum.pop_back();
			visited[i] = false;
		}
	}
}

int solution(string numbers) {
	for(int i=0; i<numbers.size(); i++) {
		nums.push_back(numbers[i]);
	}
	for(int i=1; i<=numbers.size(); i++) selecting(0,0,i,"");
    return s.size();
}