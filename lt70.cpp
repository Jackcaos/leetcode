#include<stdio.h>
#include<vector>

class Solution {
public:
    int climbStairs(int n) {
        std::vector<int> dp(n, 0);
        dp[0] = 1;
        dp[1] = 2;
        for(int i = 2; i < n ; i++){
        	dp[i] = dp[i-1]+dp[i-2];
		}
		return dp[n-1];
    }
};

int main(){
	Solution solu;
	int i = solu.climbStairs(3);
	printf("%d",i);
	return 0;
}
