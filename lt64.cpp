#include<stdio.h>
#include<vector>

//[
//   [1,2,3],
//   [1,3,1],
//   [3,1,1]
//]

class Solution {    
public:
    int minPathSum(std::vector<std::vector<int> >& grid) {
        int row = grid.size();
        int col = grid[0].size();
        std::vector<std::vector<int> > dp(row,std::vector<int>(col,0));
        dp[0][0] = grid[0][0];
        for(int i = 1; i < col; i++)
        {
        	dp[0][i] = dp[0][i-1] + grid[0][i];
		}
		for(int i = 1; i < row;i++){
			dp[i][0] = dp[i-1][0] + grid[i][0];
			for(int j = 1; j < col; j++){
				dp[i][j] = std::min(dp[i-1][j] , dp[i][j-1]) + grid[i][j];
			}
		}
		return dp[row-1][col-1];	   
    }
};

int main()
{
	std::vector<std::vector<int> > grid;
	int a[3][3] = {{1,2,3},{3,2,2},{2,2,3}};
	for(int i = 0; i < 3; i++){
		grid.push_back(std::vector<int> ());
		for(int j = 0; j < 3; j++){
			grid[i].push_back(a[i][j]);
		}
	}
	Solution s;
	printf("%d",s.minPathSum(grid));
	return 0;
}
