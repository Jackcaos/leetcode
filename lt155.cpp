#include<stdio.h>
#include<stack>

class MinStack{
	public:
    MinStack() {
    }
    
    void push(int x) {
        MyStack.push(x);
        if(MinStacks.empty()){
         	MinStacks.push(x);
	    }
        	if(x<=MinStacks.top()){
        		MinStacks.push(x);
			}
			else{
				MinStacks.push(MinStacks.top());
			}
    }
    
    void pop() {
        MyStack.pop();
        MinStacks.pop();
    }
    
    int top() {
        return MyStack.top();
    }
    
    int getMin() {
       return MinStacks.top();

    }
    private:
    	std::stack<int> MinStacks;
        std::stack<int> MyStack;
};

int main(){
	MinStack minStack;
	minStack.push(-2);
	printf("top = [%d]\n", minStack.top());
	printf("min = [%d]\n\n", minStack.getMin());	
	minStack.push(0);
	printf("top = [%d]\n", minStack.top());
	printf("min = [%d]\n\n", minStack.getMin());
	minStack.push(-5);
	printf("top = [%d]\n", minStack.top());
	printf("min = [%d]\n\n", minStack.getMin());
	minStack.pop();
	printf("top = [%d]\n", minStack.top());
	printf("min = [%d]\n\n", minStack.getMin());	
	return 0;
}
