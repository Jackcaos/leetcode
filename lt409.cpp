#include<stdio.h>
#include<string>
#include<vector>

class Solution{
	public:
		int longest(std::string s){
			char str_hash[128] = {0};
			int length = 0;
			int flag = 0;
			for(int i = 0;i < s.length();i++){
				str_hash[s[i]] ++;
			}
			for(int i = 0; i < 128;i++){
				if(str_hash[i] > 0 && str_hash[i] % 2 == 0){
					length += str_hash[i];
				}else if(str_hash[i] > 0 && str_hash[i] % 2 == 1){
					length +=str_hash[i] - 1;
					flag = 1;
				}
			}
			int max_length = flag + length;
			return max_length;
		}
};

int main(){
	std::string str = "aabbbbccccsss";
	Solution s;
	printf("%d\n",s.longest(str));
	return 0;
}
