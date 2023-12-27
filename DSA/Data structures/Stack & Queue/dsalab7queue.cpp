#include<iostream>
using namespace std;

template<class T>

class Queue{
	T *queue;
	int size;
	int rear ;
	int front ;
public:
	Queue(T size)
	{
		this->size = size;
		queue = new T[size];
		rear=-1;
		front=-1;
	}
	bool isEmpty()
	{
		if(rear==-1 && front==-1 )
			return 1;
		return 0;
	}
    bool isFull()
	{
		if(rear==size-1)
			return 1;
		return 0;
	}
//	T dequeue( T e)
//	{
//		if(!isEmpty())    
//		   return queue[top];
//		else return 0;
//	}
	void enqueue( T e)
	{
		if(!isFull())
		 	rear = rear+1;
		queue[rear]  = e;
		if(front == -1)		front = front + 1;
	
	}
	int dequeue()
	{
		int e;
		if(!isEmpty())
		e = queue[front];
		
		if(front == rear)		front = rear = -1;
		else front = front+1;
		return e;
	}
};
template<class T>

class CircularQueue{
	T *queue;
	int size;
	int rear ;
	int front ;
public:
	CircularQueue(T size)
	{
		this->size = size;
		queue = new T[size];
		rear=-1;
		front=-1;
	}
	bool isEmpty()
	{
		if(rear==-1 && front==-1 )
			return 1;
		return 0;
	}
    bool isFull()
	{
		if(front == (rear+1) % size)
			return 1;
		return 0;
	}
//	T dequeue( T e)
//	{
//		if(!isEmpty())    
//		   return queue[top];
//		else return 0;
//	}
	void enqueue( T e)
	{
		if(!isFull())
		 	rear = (rear+1) % size;
		queue[rear]  = e;
		if(front == -1)		front = front + 1;
	
	}
	int dequeue()
	{
		int e;
		if(!isEmpty())
		e = queue[front];
		
		if(front == rear)		front = rear = -1;
		else front = (front+1) % size;
		return e;
	}
};
int main(){
	Queue <int> q1(4);
	q1.enqueue(2);
	q1.enqueue(5);
	q1.enqueue(8);
	q1.enqueue(9);
	//cout<<"-------------------------\n";
	cout<<q1.dequeue()<<' ';
	cout<<q1.dequeue()<<' ';
	cout<<q1.dequeue()<<' ';
	cout<<q1.dequeue()<<' ';
	cout<<"\n-------------------------\n";
	CircularQueue <int> q(3);
	q.enqueue(1);
	q.enqueue(5);
	q.enqueue(8);
	cout<<q.dequeue()<<'\n';
	q.enqueue(6);
	cout<<q.dequeue();
	cout<<q.dequeue();
	cout<<q.dequeue();
	return 0;
}

