#include<stdio.h>
#include<vector>

class Solution{
	public: 
    int maxSubArray(std::vector<int>& nums) {
        if(nums.size()==0){
        	return 0;
		} 
		if(nums.size()==1){
			return nums[0];
		}
		std::vector<int> dp(nums.size(),0);
		dp[0] = nums[0];
		int max_res = dp[0];
		for(int i = 1; i< nums.size();i++){
			dp[i] = std::max(dp[i-1]+nums[i],nums[i]);
	    	if(dp[i] > max_res){
	    		max_res = dp[i];
	    	}
	}
	    return max_res;	
    }
};

int main(){
	std::vector<int> nums;
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(-4);
	nums.push_back(-1);
	nums.push_back(-5);
	nums.push_back(7);
	Solution solu;
	printf("%d",solu.maxSubArray(nums));
	return 0;
}
