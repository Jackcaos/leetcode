#include<stdio.h>
#include <set>
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){
	}
};

class Solution{
	public :
	  ListNode *detectCycle(ListNode *head) {
	  	std::set<ListNode *> node;
        while(head){
          node.insert(head);
          if(node.find(head)!=node.end()){
          	return head;
		  }
		  head = head->next;
		}
		return NULL;
    }
};

int main(){
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	ListNode e(5);
	ListNode f(6);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	f.next = &c;
	Solution solve;
	ListNode *node = solve.detectCycle(&a);
	if (node){
		printf("%d",node->val);
	}
	else{
		printf("NULL");
	}
	return 0;
}
