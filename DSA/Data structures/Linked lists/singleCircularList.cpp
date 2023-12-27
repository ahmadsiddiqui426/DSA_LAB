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
class SCList{
	Node *tail;
	public:
		SCList(){
			tail=0;
		}
		bool isEmpty(){
			if(tail==0)		return 1;
			return 0;
		}
		void addToTail(int e){
			if(isEmpty()){
				tail=new Node(e);
				tail->next=tail;
			}
			else{
				tail->next=new Node(e,tail->next);
				tail=tail->next;
			}
		}
		void addToHead(int e){
			if(isEmpty()){
				tail=new Node(e);
				tail->next=tail;
			}
			else{
				tail->next=new Node(e,tail->next);
			}
		}
		void display(){
			Node *t=tail,*t2=tail->next;
			for(;t2!=t;t2=t2->next)
				cout<<t2->data<<'\n';
			cout<<t2->data<<'\n';
		}
		int deleteFromHead(){
			if(!isEmpty()){
				int e=tail->next->data;
				if(tail->next==tail){
					delete tail;
					tail=0;
				}
				else{
					Node *t=tail->next;
					tail->next=tail->next->next;
					delete t;
				}
				return e;
			}
			return 0;
		}
		int deleteFromTail(){
			if(!isEmpty()){
				int e=tail->data;
				if(tail->next==tail){
					delete tail;
					tail=0;
				}
				else{
					Node *t=tail->next;
					for(;t->next!=tail;)
						t=t->next;
					t->next=t->next->next;
					delete tail;
					tail=t;
				}
				return e;
			}
			return 0;
		}
		void addNode(int e,int pos){
			if(pos == 1)	this->addToHead(e);
			else{
				Node *t=tail->next,*a=t->next;
				int i=0;
				for(;t!=tail;t=t->next){
					i++;
					if(i==pos-1){
						t->next=new Node(e,t->next);
					}
				}
			}
		}
		void deleteNode(int e){
			if(!isEmpty()){
				if(tail->data==e&&tail->next==tail){
					delete tail;
					tail=0;
				}
				else if(tail->data==e){
					deleteFromTail();
				}
				else{
					Node *t=tail->next,*a=t->next;
					for(;t!=tail && t->next->data!=e;)
						t=t->next;
					if(t->next->data==e){
						t->next=a->next;
						delete a;
					}
				}
			}
		}
		friend istream& operator>>(istream& in,SCList &s){
			int node,i,data;
			cout<<"Enter no. of nodes:";
			in>>node;
			for(i=0;i<node;i++){
				cout<<"\nEnter data for node "<<i+1<<": ";
				in>>data;
				s.addToTail(data);
			}
			cout<<"\n----------\nEntered list:\n";
			s.display();
			return in;
		}
};
int main(){
	int data,pos;
	SCList s;
	cin>>s;
	cout<<"\n--------\nDeleting from head:\n";
	s.deleteFromHead();
	s.display();
	cout<<"\n--------\nDeleting from tail:\n";
	s.deleteFromTail();
	s.display();
	cout<<"\n--------\nAdding:\n";
	cout<<"Enter data to add: ";
	cin>>data;
	cout<<"\nEnter position to add: ";
	cin>>pos;
	s.addNode(data,pos);
	cout<<"\nAfter adding:\n";
	s.display();
	cout<<"\n--------\nDeleting:\n";
	cout<<"Enter data to delete: ";
	cin>>data;
	s.deleteNode(data);
	cout<<"\nAfter Deleting:\n";
	s.display();
	return 0;
}