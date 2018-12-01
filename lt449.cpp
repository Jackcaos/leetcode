#include<stdio.h>
#include<vector>
#include<string>
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x),left(NULL),right(NULL){}
};
class Codec {
public:
	void change(int val,std::string &str){     //ÕûÐÍ×ª×Ö·û´® 
		std::vector<int> num;
	    while(val > 0){
	    	num.push_back(val % 10);
	    	val = val / 10;
		}
		for(int i = num.size() - 1; i >= 0; i--){
			str += num[i] + '0';
		}
		str += '#';
	}
	
	void BST(TreeNode *node,std::string &data){
		if(!node){
			return;
		}
		std::string str;
		change(node->val,str);
		data += str;
		BST(node->left,data);
		BST(node->right,data);
	}
    
	void BST_insert(TreeNode* root,TreeNode* target){
		if(root->val > target->val){
			if(root->left){
				BST_insert(root->left,target);
			}
			else{
				root->left = target;
			}
		}
		else
		{
			if(root->right){
				BST_insert(root->right,target);
			}
			else{
				root->right = target;
			}
		}
	}
	void BST_print(TreeNode* root,int lay){
		if(!root){
			return;
		}
		for(int i = 0; i < lay; i++){
			printf("---");
		}
		printf("%d\n",root->val);
		BST_print(root->left,lay+1);
		BST_print(root->right,lay+1);
	}
    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root) {
        std::string str;
        BST(root,str);
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data) {
        if(data == ""){
        	return NULL;
		}
		int num = 0;
		std::vector<TreeNode*> root;
		for(int i = 0; i < data.length(); i++){
			if(data[i] == '#'){  //123#345#
				root.push_back(new TreeNode(num));
				num = 0;
				continue;
			}
			num = num * 10 + data[i] - '0';
		}
		for(int i = 1; i < root.size(); i++){
			 BST_insert(root[0],root[i]);
		}
		return root[0];
    }
};

int main(){
	std::string str;
	TreeNode *root;
	Codec cc;
	TreeNode a(2);
	TreeNode b(1);
	TreeNode c(3);
	TreeNode d(4);
	a.left = &b;
	a.right = &c;
	c.right = &d;
	str = cc.serialize(&a); 
	root = cc.deserialize(str);
	cc.BST_print(root,0);
	return 0;
}
