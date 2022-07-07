#include <string>
#include <vector>

using namespace std;

// 퀵 정렬
void sorting(vector<int> &arr, int start, int end) {
	// 원소가 0개일 경우
	if(start >= end) return;
	
	// 피봇과 시작과 끝 설정
	int pivot = start;
	int i = pivot+1;
	int j = end;
	int temp;

	// 두 포인터가 엇갈릴 때까지 반복
	while(i <= j) {
		// 왼쪽
		while(i <= end && arr[i] <= arr[pivot]) i++;
		// 오른쪽
		while(j > start && arr[j] >= arr[pivot]) j--;

		// 엇갈림 => 피봇과 교체
		if(i > j) {
			temp = arr[j];
			arr[j] = arr[pivot];
			arr[pivot] = temp;
		}
		// i,j번째 스왑
		else {
			temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
	}

	sorting(arr, start, j-1);
	sorting(arr, j+1, end);
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
	for(int i=0; i<commands.size(); i++) {
		int first = commands[i][0];
		int second = commands[i][1];
		int k = commands[i][2];
		vector < int > result;
		// 배열 자르기
		for(int j=first-1; j<second; j++) result.push_back(array[j]);
		// 정렬
		sorting(result,0,result.size()-1);
        
		answer.push_back(result[k-1]);
	}
    return answer;
}