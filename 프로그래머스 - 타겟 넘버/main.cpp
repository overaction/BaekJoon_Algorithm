#include <string>
#include <vector>
#include <queue>
using namespace std;

int answer;

// bfs 방식
void bfs(vector<int> numbers, int target) {
	// {현재 값, 더한 횟수}
	queue < pair < int,int > > q;
	q.push({numbers[0],1});
	q.push({-numbers[0],1});

	int maxCnt = numbers.size();
	while(!q.empty()) {
		int now = q.front().first;
		int cnt = q.front().second;
		q.pop();

		// 끝까지 도달
		if(cnt == maxCnt) {
			if(target == now) answer++;
		}
		else {
			// -
			q.push({now-numbers[cnt], cnt+1});
			// +
			q.push({now+numbers[cnt], cnt+1});
		}
	}
}

// dfs 방식
void dfs(vector<int> numbers, int now, int cnt, int target) {
	// 끝까지 도달
	if(cnt == numbers.size()) {
		if(target == now) answer++;
		return;
	}
	dfs(numbers,now+numbers[cnt],cnt+1,target);
	dfs(numbers,now-numbers[cnt],cnt+1,target);
}

int solution(vector<int> numbers, int target) {
    answer = 0;
	// bfs 적용
	bfs(numbers,target);

	// dfs 적용
	dfs(numbers, -numbers[0], 1, target);
	dfs(numbers, numbers[0], 1, target);
    return answer;
}