#include <iostream>
using namespace std;

template <class T>
class priorityQueue{
	int size;
	T *queue;
	int *priority;
	int front;
	int rear;
	public:
		priorityQueue(int size)
		{
			this->size = size;
			queue = new T[size];
			priority = new int[size];
			front = -1;
			rear = -1;
		}
		bool isEmpty()
		{
			if(front == -1 && rear == -1)	return true;
			return false;
		}
		bool isFull()
		{
			if(rear == size-1)	return true;
			return false;
		}
		void enqueue(T ele , int pri)
		{
			if(!isFull())	rear+=1;
			queue[rear] = ele;
			priority[rear] = pri;
			if(front == -1)	front += 1;
			if(rear != front){
			for(int i = front; i< rear; i++)
				for(int j= front;j<rear ;j++)
				{
					if(priority[j]>priority[j+1]){
						int temp = priority[j];
						priority[j] = priority[j+1];
						priority[j+1] = temp;
						int temp2 = queue[j];
						queue[j] = queue[j+1];
						queue[j+1] = temp2;
					}
				}
			}
		}
		T dequeue()
		{
			T element;
			if(!isEmpty())
				element = queue[front];
			else cout<<"Empty\n";
			if(front == rear)		front = rear =-1;
			else front++;
			return element;
		}
};
int main(){
	priorityQueue <int> p1(3);
	p1.enqueue(50,3);
	p1.enqueue(20,1);
	p1.enqueue(10,2);
	cout<<p1.dequeue()<<' ';
	cout<<p1.dequeue()<<' ';
	cout<<p1.dequeue()<<' ';
	return 0;
}