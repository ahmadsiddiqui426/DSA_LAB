#include <iostream>
using namespace std;
class Node{
	public:
	int data;
	Node* next;
	
		Node(int d , Node*n=0){
			data = d;
			next = n;
		}
};
class SLList{
	public:
	Node *head;
	Node  *tail;
	public:
		SLList(){
			head = tail = 0;
		}
		bool isEmpty(){
			if(head == 0) return 1;
			return 0;
		}
		void addToHead(int e){
			head = new Node(e,head);
			if(tail == 0)	tail = head;
		}
		void addToTail(int e){
			if(tail != 0){
				tail->next= new Node(e);
				tail = tail->next;
			}
			else head = tail = new Node(e);
		}
		void deleteFromHead(){
			if(!isEmpty()){
				int e = head->data;
				Node *temp = head;
				if(head == tail)	head = tail = 0;
				else				head = head->next;		
				//delete head;
				delete temp;
			}
		}
		void deleteFromTail(){
			if(!isEmpty()){
				int e = tail->data;
				if(head == tail){
					delete tail;
					head = tail = 0;
				}
				else{
					Node *temp = head , *a;
					for(; temp->next!=tail;)
						temp = temp->next;
					temp->next=tail->next;
					delete tail;
					tail = temp;
				}
			}
	}
		void display(){
		cout<<"NULL->";
		for(Node *t=head;t!=NULL;t=t->next)
			cout<<t->data<<"->";
		cout<<"NULL"<<endl;
	}
};
int main(){
	SLList s;
	if(s.isEmpty())	cout<<"List Empty\n";
	s.addToHead(34);
	s.addToHead(35);
	s.addToHead(36);
	s.addToTail(37);
	s.display();
	s.deleteFromHead();
	s.display();
	s.deleteFromTail();
	s.display();
	s.deleteFromTail();
	s.display();
	return 0;
}