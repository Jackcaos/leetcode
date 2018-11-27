#include<stdio.h>
#include<vector>
#include<string>
#include<map>
#include<algorithm>

class Solution{
	public:
		std::vector<std::vector<std::string > > groupAnagrams(std::vector<std::string> &strs){
			std::map<std::string,std::vector<std::string> > str;
			std::string word = "";
			std::vector<std::vector<std::string > > result;
			for(int i = 0; i < strs.size() ; i++){
				word = strs[i];
				std::sort(word.begin(),word.end());
				if(str.find(word) == str.end()){
					std::vector<std::string > item;
					str[word] = item;
				}
				str[word].push_back(strs[i]);
			}
			std::map<std::string, std::vector<std::string> > ::iterator it;
			for(it = str.begin(); it != str.end(); it++){
				result.push_back((*it).second);
			}
			return result;
		}
}; 

int main(){
	std::vector<std::string> strs;
	strs.push_back("bat");
	strs.push_back("bta");
	strs.push_back("atb");
	strs.push_back("tan");
	strs.push_back("atn");
	Solution s;
	std::vector<std::vector<std::string > > result = s.groupAnagrams(strs);
	for(int i = 0; i < result.size() ; i++){
		for(int j = 0 ; j < result[i].size() ; j++){
			printf("[%s]",result[i][j].c_str());
		}
		printf("\n");
	}
	return 0;
}
