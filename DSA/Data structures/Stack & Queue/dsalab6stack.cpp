#include<iostream>
using namespace std;

template<class T>

class Stack{
	T *stack;
	int capacity;
	int top;
public:
	Stack(T capacity)
	{ 
		this->capacity = capacity;
		stack = new T[capacity];
		top=-1;
	}
	bool isEmpty()
	{
		if(top==-1)
		 return 1;
		 else    return 0;
	}
    bool isFull()
	{
		if(top==capacity-1)
		 return 1;
		 else    return 0;
	}
	T Top()
	{
		if(!isEmpty())    
		   return stack[top];
		else return 0;
	}
	void push(T a)
	{
		if(!isFull())
		  top = top+1;
		stack[top]  = a;
	}
	int pop()
	{
		T e;
		if(!isEmpty())
		e = stack[top];
		top = top-1;
		return e;
	}

bool balance(string a){
	int count = 0 , mid;
	for(int i = 0 ;a[i] != '\0' ;i++){
		if(a[i]=='(' || a[i]==')' || a[i]=='{' || a[i]=='}' || a[i]==']' || a[i]=='['){
			count++;
			push(a[i]);
		}
	}
	if(count % 2 != 0)	return 0;
	mid = count/2;
	char *b = new char [mid];
	for (int i = 0 ; i < mid ;i++){
		b[i] = pop();
	}
	for (int i = mid-1 ; i > 0 ;i--){
		if( (b[i] == ')' && Top() =='(') || (b[i] == ']' && Top() =='[' )|| (b[i] == '}' && Top() =='{')){
			pop();
			continue;
		}
		else 	return 0;
	}
	return 1;
}
};
int main(){
	Stack <int> s(13);
	string a="(A+{B-[C+D]})";
	if(s.balance(a))	cout<<"Balance";
	else	cout<<"Not Balance";
	return 0;
}