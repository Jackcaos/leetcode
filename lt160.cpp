#include<stdio.h>

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x),next(NULL){
	}
};

int len(ListNode *head){
	int len = 0;
	while(head){
		len++;
		head = head->next; 
	}
	return len;
}

ListNode *backNode(ListNode *head,int n){
	while(head&&n--){
		head = head->next;
	}
	return head;
}

class Solution{
	public:
		ListNode *getIntersectionNode(ListNode *a,ListNode *b){
			int x = len(a);
			int y = len(b);
			if(x>y){
				int length = x-y;
				a = backNode(a,length);
			}
			else if(x<y){
				int length = y-x;
				b = backNode(b,length);
			}
			while(a&&b){
				if(a==b){
					return a;
				}
				a=a->next;
				b=b->next;
			}
			return NULL;
		}
};

int main(){
	ListNode a1(1);
	ListNode a2(2);
	ListNode b1(3);
	ListNode b2(4);
	ListNode b3(5);
	ListNode c1(6);
	ListNode c2(7);
	ListNode c3(8);
	a1.next = &a2;
	a2.next = &c1;
	c1.next = &c2;
	c2.next = &c3;
	b1.next = &b2;
	b2.next = &b3;
	b3.next = &c1;	
	Solution solve;
	ListNode *result = solve.getIntersectionNode(&a1, &b1);
	printf("%d\n", result->val);
	return 0;
}
