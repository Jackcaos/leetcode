#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
class Solution{
	public:
	int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
        std::map<std::string ,std::vector <std::string> > graph;
        graphs(beginWord,wordList,graph);
        return graph_BFS(beginWord,endWord,graph);
    }
	bool connect(const std::string &word1,const std::string &word2){  //判断两个单词是不是存在一个字母不同 
		int num = 0;
		for(int i = 0;i < word1.length(); i++){
			if(word1[i] != word2[i]){
				num++;
			}
		}
	return num==1;
	}
	
	void graphs(std::string &beginWord,std::vector <std::string> &wordList,
	std::map<std::string ,std::vector <std::string> > &graph){
		wordList.push_back(beginWord);
		for(int i = 0;i < wordList.size(); i++){
			graph[wordList[i]] = std::vector<std::string>();
		}
		for(int i = 0; i < wordList.size();i++){
			for(int j = i+1; j < wordList.size();j++){
				if(connect(wordList[i],wordList[j])){
					graph[wordList[i]].push_back(wordList[j]);
					graph[wordList[j]].push_back(wordList[i]);
				}
			}
		}
	}
	
	int graph_BFS(std::string &beginWord,std::string &endWord,
	std::map<std::string ,std::vector <std::string> > &graph
	) {
		std::queue<std::pair<std::string, int> > q;
	std::set<std::string> mark;
	q.push(std::make_pair(beginWord,1));
	mark.insert(beginWord);
	while(!q.empty()){
		std::string str = q.front().first;
		int step = q.front().second;
		q.pop();
		if(str == endWord){
			return step;
		}
		const std::vector<std::string> &node = graph[str];
		for(int i = 0; i < node.size(); i++){
			if(mark.find(node[i]) == mark.end()){
				q.push(std::make_pair(node[i],step+1));
				mark.insert(node[i]);
			}
		}	
	}
	return 0;
	}	
};

int main(){
	std::string beginWord = "hot";
	std::string endWord = "cog";
	std::vector<std::string> wordList;
	wordList.push_back("hot");
	wordList.push_back("dot"); 
	wordList.push_back("dog");
	wordList.push_back("lot");
	wordList.push_back("log");
	wordList.push_back("cog");
	Solution s;
	int res = s.ladderLength(beginWord,endWord,wordList);
	printf("%d",res);
	return 0;
}
