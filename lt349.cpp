#include<stdio.h>
#include<set>
#include<vector>

class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::set<int> res;
        for(int i = 0; i < nums1.size(); i ++){
        	res.insert(nums1[i]);
		}
		
		std::set<int> res2;
		for(int i = 0; i < nums2.size(); i++){
			if(res.find(nums2[i]) != res.end()){
				res2.insert(nums2[i]);
			}
		}
		
		std::vector <int> result;
		for(std::set<int>::iterator it = res2.begin(); it != res2.end() ; it++){
			result.push_back(*it);
		}
		return result;
    }
};

int main(){
	int a[] = {9,4,9,4,8};
	std::vector<int> nums1(a,a+5);
	int b[] = {9,4};
	std::vector<int> nums2(b,b+2);
	Solution s;
	std::vector<int> res = s.intersection(nums1,nums2);
	for(int i = 0; i < res.size();i++){
		printf("%d",res[i]);
	} 
	return 0;
}
