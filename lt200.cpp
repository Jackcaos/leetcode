#include<stdio.h>
#include <queue>  
#include<vector>
 class Solution{
 	public:
 		int numIslands(std::vector <std::vector <char> > &grid){
 			int num_islands = 0;
 			std::vector<std::vector <int> > mark;
 			for(int i = 0; i < grid.size(); i++){
 				mark.push_back(std::vector <int>());    //对mark的x行上进行横向填充
				for(int j = 0; j < grid[i].size(); j++){
					mark[i].push_back(0);
				} 
			 }
			 
			 for(int i = 0; i < grid.size(); i++){
			 	for(int j = 0; j < grid[i].size(); j++){
			 		if(mark[i][j] == 0 && grid[i][j] == '1'){
			 			BFS(mark,grid,i,j);
			 			num_islands++;
					 }
				 }
			 }
			 return num_islands;
		 }
		 
		void BFS(std::vector <std::vector <int> > &mark,
                 std::vector<std::vector <char> > &grid, int x,int y)
		 {
         	static const int dx[] = {-1,1,0,0}; //x方向数组
			static const int dy[] = {0,0,-1,1}; //y方向数组
			std::queue<std::pair<int, int> > q; //宽度搜索的队列
			q.push(std::make_pair(x,y));    //将(x,y)坐标进入队列，并进行标记
			mark[x][y] = 1;          //标记以遍历的坐标
			while(!q.empty()){
				x = q.front().first;     //取出队头元素 
				y = q.front().second;
				q.pop();       //弹出队头元素
				for(int i = 0; i < 4 ; i++){  //上下左右进行变换 
					int ax = dx[i] + x;
					int ay = dy[i] + y;
					if(ax < 0 || ax >= mark.size() || ay < 0 || ay >= mark[ax].size()){
						continue;
					}
				    if(mark[ax][ay] == 0 && grid[ax][ay] == '1'){      //若这是一个新位置加入数组 
				    	q.push(std::make_pair(ax,ay));
				    	mark[ax][ay] = 1;       //进行标记 
					}
				}
			} 
			 
		}	
 };
 
 int main(){
 	std::vector<std::vector <char> > grid;
 	char str[10][10] = {"11100","11000","00100","00011"};
 	for(int i = 0; i < 4; i++){
 		grid.push_back(std::vector <char> ());
 		for(int j = 0; j < 5 ;j++){
		  grid[i].push_back(str[i][j]);
		 }
		 Solution s;
		 printf("%d",s.numIslands(grid));
	 }
	 return 0;
 }
 
 
