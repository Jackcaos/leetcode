#include<stdio.h>

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x),next(NULL){
	}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *a, ListNode *b) {

           ListNode *pre_a=a,*pre_b=b;
           int cna=0,cnb=0,ans;
           while(pre_a)
           {
               cna++;
               pre_a=pre_a->next;
           }
           while(pre_b)
           {
               cnb++;
               pre_b=pre_b->next;
           }
           if(cna>cnb)
           {
               ans=cna-cnb;
               while(ans--)
                   a=a->next;
           }
           else
           {
               ans=cnb-cna;
               while(ans--)
                   b=b->next;
           }

           while(a&&b)
           {
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
