#include<stdio.h>

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){
	}
};

class Solution{
	public:
		//node_ptr��ʾ����m��ǰ����node_next��ʾ��n�ĺ�� 
	ListNode* reverseBetween(ListNode* head, int m, int n) {
        int s = n-m+1;
        ListNode *node_ptr = NULL;
        ListNode *result = head;    //Ϊ��ȷ��head����һ���ڵ㣬�Ƚ��䱣�� 
        
		while(--m&&head){
			node_ptr = head;        //���е���m��ʱ��ǰ�� 
			head = head->next; 
		}
		ListNode *node_next = head;  //����head
		ListNode *new_head = NULL;   //����һ���µĽڵ� 
		while(s&&head){
			ListNode *next = head->next;
			head->next = new_head;
			new_head = head;
			head = next; 
			s--;          
		}                           //��֤��[m,n]֮����������head��ָ���ڲ�������˶� 
		node_next->next = head;    //��n���ĺ�̽��Ϻ����head 
	
		if(node_ptr){              //�ж��Ƿ�headֻ��һ���ڵ� 
		   node_ptr->next = new_head;         //����m��ǰ���ͺ��	
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
