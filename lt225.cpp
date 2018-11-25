#include<stdio.h>
#include<queue>
#include<stack>
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        std::queue<int> temp_queue;
        temp_queue.push(x);
        while(!_data.empty()){
        	temp_queue.push(_data.front());
        	_data.pop();
		}
		while(!temp_queue.empty()){
			_data.push(temp_queue.front());
			temp_queue.pop();
		}
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x = _data.front();    //取队列最前面的数 
        _data.pop();      //弹出栈顶元素 
        return x;
    }
    
    /** Get the top element. */
    int top() {
       return _data.front(); 
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return _data.empty();
    }
private:
	std::queue<int> _data;
};
int main(){
	MyStack S;
	S.push(1);
	S.push(2);
	S.push(3);
	S.push(4);
	printf("%d\n", S.top());
	S.pop();
	printf("%d\n", S.top());
	S.push(5);
	printf("%d\n", S.top());	
	return 0;
}
