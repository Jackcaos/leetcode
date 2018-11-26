#include<stdio.h>
#include<map>
#include<vector>

class Solution {
public:
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::map<int,int> res;
        for(int i = 0; i < nums1.size(); i++){
        	res[nums1[i]]++;
		}
		std::vector<int > result;
		for(int i = 0; i < nums2.size(); i++){
			if(res[nums2[i]] > 0){
				result.push_back(nums2[i]);
			}
		}
		return result;
    }
};

int main(){
	int a[] = {1,2,3,4};
	std::vector<int> nums1(a,a+4);
	int b[] = {1,2};
	std::vector<int> nums2(b,b+2);
	Solution s;
	std::vector<int> res = s.intersect(nums1,nums2);
	for(int i = 0; i < res.size();i++){
		printf("%d",res[i]);
	} 
	return 0;
}
