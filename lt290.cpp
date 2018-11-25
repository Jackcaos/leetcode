#include<stdio.h>
#include<string>
#include<vector>
#include<map>

class Solution{
	public:
    	bool wordPattern(std::string pattern, std::string str) {
        std::map<std::string,char> word_map;
        char char_map[128] = {0};
        int pos = 0;
        std::string word;
        str.push_back(' ');
        for(int i = 0; i < str.length(); i++){
        	if(str[i] == ' '){
        		if(pos == pattern.length()){
        			return false;
				}
				if(word_map.find(word) == word_map.end()){
					if(char_map[pattern[pos]]){
						return false;
					}
					char_map[pattern[pos]] = 1;
					word_map[word] = pattern[pos];
				}
				else
				{
				    if(word_map[word] != pattern[pos]){
				    	return false;
					}
				}
				word = "";
				pos++;
			}else{
				word += str[i];
			}
		}
		if(pattern.length() != pos){
			return false;
		}
			return true;
       }
};

int main(){
	std::string a = "abba";
	std::string b = "dog cat cat dog";
	Solution s;
	printf("%d\n",s.wordPattern(a,b));
	return 0;
}
