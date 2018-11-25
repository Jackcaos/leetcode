#include<stdio.h>
#include<queue>
#include<stack>

class Myqueue{
	public:
		Myqueue(){			
		}
	    void push(int x){
	    	std::stack<int> temp_stack;	
	    	while(!Mystack.empty()){     //队列和栈必须通过此方法检测是否为空 
	    		temp_stack.push(Mystack.top());
	    		Mystack.pop();
			}
			temp_stack.push(x);//这一步的顺序和栈实现队列的顺序不同 
			while(!temp_stack.empty()){
				Mystack.push(temp_stack.top());
				temp_stack.pop();
			}
		}
		
		int pop(){
			int x = Mystack.top();
			Mystack.pop();
			return x;
		}
		
		int peek(){
			return Mystack.top();
		}
		
		bool empty(){
			return Mystack.empty();
		}
	private:
		std::stack<int> Mystack;
};
int main(){
	Myqueue Q;
	Q.push(1);
	Q.push(2);
	Q.push(3);
	Q.push(4);
	printf("%d\n", Q.peek());
	Q.pop();
	printf("%d\n", Q.peek());	
	return 0;
}
