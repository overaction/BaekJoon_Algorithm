#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
	set < int > pocket;
	for(int i=0; i<nums.size(); i++) {
		pocket.insert(nums[i]);
	}
	if(pocket.size() > nums.size()/2) answer = nums.size()/2;
	else answer = pocket.size();
    return answer;
}