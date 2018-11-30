#include<stdio.h>
#include<vector>

class Solution{
	public:
	std::vector<int> searchRange(std::vector<int> &nums,int target){
		int first = 0;
		int end = nums.size() - 1;
		std::vector<int> res;
		int leftNum = left(nums,target,first,end);
		int rightNum = right(nums,target,first,end);
		res.push_back(leftNum);
		res.push_back(rightNum);
		return res;
	}
	
	int left(std::vector<int> &num,int target,int first,int end){
		int mid;
		while(first <= end){
			mid = ( first + end ) / 2;
			if(target == num[mid]){
				while(mid >= 0){
				if(mid == 0 || num[mid - 1] < target){
					return mid;
				}
				mid--;
				}
			}
			else if(target < num[mid]){
				end = mid - 1;
			}
			else if(target > num[mid]){
				first = mid + 1;
			}
		}
		return -1;
	}
	int right(std::vector<int> &num,int target,int first,int end){
		int mid;
		while(first <= end){
			mid = ( first + end ) / 2;
			if(target == num[mid]){
				while(mid <= num.size()){
					if(mid == num.size() - 1 || target < num[mid+1] ){
						return mid;
					}
					mid++;
				}
			}
			else if(target < num[mid]){
				end = mid - 1;
			}
			else if(target > num[mid]){
				first = mid + 1;
			}
		}
		return -1;
	}
	
}; 

int main(){
	std::vector<int> orderArray;
	orderArray.push_back(1);
	orderArray.push_back(1);
	orderArray.push_back(3);
	orderArray.push_back(4);
	Solution s;
	std::vector<int> res = s.searchRange(orderArray,1);
	for(int i = 0; i < res.size(); i++){
		printf("[%d]",res[i]);
	}
	return 0;
}
