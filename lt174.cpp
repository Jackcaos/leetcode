#include<stdio.h>
#include<vector>

class Solution {
public:
    int calculateMinimumHP(std::vector<std::vector<int> >& dungeon) {
    	if(dungeon.size() == 0){
    		return 0;
		}
        int row = dungeon.size();
		int col = dungeon[0].size();
		std::vector<std::vector<int> > dp(row,std::vector<int>(col,0));
		dp[row - 1][col - 1] = std::max(1,1-dungeon[col - 1][row - 1]);
		for(int i = col - 2; i >= 0; i--){
			dp[row - 1][i] = std::max(1,dp[row - 1][i + 1] - dungeon[row - 1][i]);
		}
		for(int i = row - 2; i >= 0; i--){
			dp[i][col - 1] = std::max(1,dp[i + 1][col - 1] - dungeon[i][col - 1]);
		}
		for(int i = row - 2; i >= 0; i--){
			for(int j = col - 2; i >= 0; i--){
				int min = std::min(dp[i+1][j],dp[i][j+1]);
				dp[i][j] = std::max(1,min - dungeon[i][j]);
			}
		}
		return dp[0][0];
    }
};

int main()
{
	std::vector<std::vector<int> > grid;
	int a[3][3] = {{1,-2,-3},{-3,-2,2},{2,2,-3}};
	for(int i = 0; i < 3; i++){
		grid.push_back(std::vector<int> ());
		for(int j = 0; j < 3; j++){
			grid[i].push_back(a[i][j]);
		}
	}
	Solution s;
	printf("%d",s.calculateMinimumHP(grid));
	return 0;
}
