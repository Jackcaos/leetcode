#include<stdio.h>
#include<vector>

class Solution{
	public:
	int searchInsert(std::vector<int> &num,int target){
		int first = 0;
		int end = num.size() - 1;
		int key;
	    while(first <= end){
	    	int mid = (first+end) / 2;
	    	if(target == num[mid]){
	    		key = mid;
			}
			else if(target < num[mid]){
				if(mid == 0 || target > num[mid - 1]){
					key = mid;
				}
				end = mid - 1;
			}
			else if(target > num[mid]) {
				if(mid == num.size() - 1|| target < num[mid + 1]){
					key = mid + 1; 
				}
			    first = mid + 1;
			}
		}
		return key;
	}
}; 

int main(){
	std::vector<int> orderArray;
	orderArray.push_back(1);
	orderArray.push_back(2);
	orderArray.push_back(3);
	orderArray.push_back(4);
	Solution s;
	int res = s.searchInsert(orderArray,5);
	printf("%d",res);
	return 0;
}
