#include<stdio.h>
#include<string>
#include<vector>

int main(){
	int char_map[128] = {0};
	std::string a = "abcdefffsss";
	
	for(int i = 0; i < a.length(); i++){
		char_map[a[i]] ++;
	}
	
	for(int i = 0 ;i < 128;i++){
		printf("[%c][%d]:%d\n",i,i,char_map[i]);
	}
	return 0;
}

