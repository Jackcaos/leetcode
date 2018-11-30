#include<stdio.h>
#include<vector>
// ²éÕÒ5
// 1 2 3 4 5 6 7 8  target>mid,mid>first,target >= first,first = mid + 1
// 7 8 1 2 3 4 5 6   target>mid,mid<first,target < first,first = mid + 1
// 6 7 8 1 2 3 4 5   

// 5 6 7 8 1 2 3 4   target<mid,mid>first,target >= first,end = mid - 1
// 4 5 6 7 8 1 2 3   target<mid,mid>first,target >= first,end = mid - 1
// 3 4 5 6 7 8 1 2   target>mid,mid>first,target >= first,end = mid - 1
// 6 9 2 3 5 target<mid,mid<first,target<first,first = mid - 1
// 2 3 4 5 6 7 8 1   target=mid
class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int first = 0;
        int end = nums.size() - 1;
        int mid;
        while(first <= end){
        	mid = (first + end) / 2;
        	if(target == nums[mid]){
        		return mid;
			}
			else if(target > nums[mid]){
				if(nums[mid] < nums[first]){
					if(target >= nums[first]){
					   end = mid - 1;		 
					}
					else
					{
					   first = mid + 1;
					}
			   	}
				else if(nums[mid] >= nums[first])
				{
				     first = mid + 1;
				}
			}
			else if(target < nums[mid]){
				if(nums[mid] > nums[first]){
					if(target >= nums[first]){
						end = mid - 1;
					}
					else{
						first = mid + 1;	
					}
				}
				else if(nums[mid] < nums[first]){
					   end = mid - 1;
				}
				else if(nums[mid] == nums[first]){
					   first = mid + 1;
				}
			}
		}
		return -1;
    }
};

int main(){
	std::vector<int> orderArray;
	orderArray.push_back(5);
	orderArray.push_back(1);
	orderArray.push_back(2);
	orderArray.push_back(3);
	orderArray.push_back(4);
	Solution s;
	int res = s.search(orderArray,1);
		printf("[%d]",res);
	return 0;
}
