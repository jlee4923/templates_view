#include <iostream>
#include <vector>
using namespace std;
/**********************************************************
슬라이딩 윈도우(Sliding Window) 알고리즘 (2021.08.14 작성)
상황 : k개의 연속된 원소로 이루어진 subarray들 중 그 합이 최대가 되는 값을 찾는 상황
알고리즘 설명: arr = [2,4,7,10,8] 을 가정했을 때, k = 3이라 해 보자.
naive하게 상황을 해결하려고 한다면 arr의 크기와 k가 작으면 상관이 없지만
둘 다 크다면 매우 비효율적이다.
arr의 subarray 중 [2,4,7], [4,7,10]을 보면 [4,7]이라는 공통부분이 생긴다.
바로 이 "공통부분"을 잘 활용하여 O(arr.size()) (linear time)에 상황을 해결하는 것이
슬라이딩 윈도우 알고리즘이다. 
maxSum 함수에서 window_start, window_end는 각각 슬라이딩되는 윈도우의
시작과 끝이며, 익숙해지면 i,j로 써도 되지만 이해를 돕기 위해 저렇게 설정했다.
***********************************************************/
int maxSum(vector<int> &arr, int k){
	int window_start = 0, window_end, window_sum = 0, max_sum = 0;
	for(window_end = 0; window_end < arr.size(); window_end++){
		window_sum += arr[window_end];
		if(window_end>=k-1){
			max_sum = max_sum>window_sum? max_sum:window_sum; //max_sum 값 갱신
			window_sum -= arr[window_start]; //window 범위에 없는 원소를 제외해준다
			window_start++;
		}
	}
	return max_sum;
}
int main(){
	//input array elements
	vector<int> arr;
	int n, k, input;
	cin >> n >> k;
	for(int i=0; i<n; i++){
		cin >> input;
		arr.push_back(input);
	}
	cout << "길이 " << k << "인 연속된 subarray의 최대 합 : " << maxSum(arr, k) << '\n';
	return 0;
}
