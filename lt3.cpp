#include<stdio.h>
#include<map>
#include<string>
#include<vector>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int char_map[128] = {0};
        int pos = 0,length = 0,maxlength = 0;
        std::string word ="";
        for(int i = 0; i < s.length(); i++){
        	char_map[s[i]]++;
        	if(char_map[s[i]] > 1){
				while(pos < i && char_map[s[i]] > 1){
					char_map[s[pos]]--;
					pos ++;
				}
		    	word = "";
				for(int j = pos ; j <= i ; j++){
					word += s[j];
				}
			}else{
				word += s[i]; 
				length = word.length();
	        	if(length > maxlength){
	        		maxlength = length;
				}
			}
		}
		return maxlength;
    }
};

int main(){
	std::string str = "bbtablud";
	Solution s;
	printf("%d\n",s.lengthOfLongestSubstring(str));
	return 0;
}

