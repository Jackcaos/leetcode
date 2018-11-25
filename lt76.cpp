#include<stdio.h>
#include<string>
#include<vector>

class Solution{
	public:
		bool is_ok(int map_s[],int map_t[],std::vector<int> &vec){
			for(int i = 0; i < vec.size() ; i++){
				if(map_t[vec[i]] > map_s[vec[i]]){
					return false;
				}
			}
			return true;
		}
		
		std::string minWindow(std::string s,std::string t){
			int map_s[128] = {0};
			int map_t[128] = {0};
			std::vector<int> vec;
			for(int i = 0; i < t.length(); i++){
				map_t[t[i]] ++;
			}
			for(int i = 0; i < 128; i++){
				if(map_t[i] > 0){
					vec.push_back(i);
				}
			}
			std::string word = "";
			int pos = 0,length = 0;
		    for(int i = 0; i < s.length(); i++){
		    	map_s[s[i]] ++;
		    	while(pos < i){
		    		if(map_t[s[pos]] == 0){
		    			pos++;
					}
					else if(map_t[s[pos]] < map_s[s[pos]]){
						map_s[s[pos]] --;
						pos++;
					}
					else{
						break;
					}
				}
				if(is_ok(map_s,map_t,vec)){
					length = i - pos + 1;
					if(word == "" || word.length() > length){
						word = s.substr(pos,length);
					}
				}
			}
			return word;	
		}
};

int main(){
	std::string s = "abeedcanbc";
	std::string t = "abc";
	std::string str = "";
	Solution S;
	str = S.minWindow(s,t);
	printf("%s\n",str.c_str());
	return 0;
}
