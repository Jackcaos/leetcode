#include<stdio.h>

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){
	}
};

class Solution{
	public:
		//node_ptr表示链表m的前驱，node_next表示第n的后继 
	ListNode* reverseBetween(ListNode* head, int m, int n) {
        int s = n-m+1;
        ListNode *node_ptr = NULL;
        ListNode *result = head;    //为了确保head不是一个节点，先将其保存 
        
		while(--m&&head){
			node_ptr = head;        //运行到第m个时的前驱 
			head = head->next; 
		}
		ListNode *node_next = head;  //连接head
		ListNode *new_head = NULL;   //定义一个新的节点 
		while(s&&head){
			ListNode *next = head->next;
			head->next = new_head;
			new_head = head;
			head = next; 
			s--;          
		}                           //保证了[m,n]之间逆序，且其head的指针在不断向后运动 
		node_next->next = head;    //第n个的后继接上后面的head 
	
		if(node_ptr){              //判断是否head只有一个节点 
		   node_ptr->next = new_head;         //连接m的前驱和后继	
		} else{
		     result = new_head;
		}
		return result;
    }           
};

int main(){	
	ListNode a(1);
	ListNode b(2);
	a.next = &b;
	b.next = NULL;
	Solution solve;
	ListNode *head = solve.reverseBetween(&a, 1, 2);	
	while(head){
		printf("%d\n", head->val);
		head = head->next;
	}
	return 0;
}
