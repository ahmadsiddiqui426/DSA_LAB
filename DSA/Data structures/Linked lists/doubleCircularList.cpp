#include <iostream>
using namespace std;
class Node{
	public:
	int data;
	Node *next,*prev;
	
		Node(int d , Node*n=0, Node *p=0){
			data = d;
			next = n;
			prev = p;
		}
};
class DCList{
	public:
	Node  *tail;
	public:
		DCList(){
			tail = 0;
		}
		bool isEmpty(){
			if(tail == 0) return 1;
			return 0;
		}
		void addToHead(int e){
			if(tail==0){
				tail = new Node(e);
				tail->next=tail;
				tail->prev=tail;
			}
			else{
				tail->next->prev=new Node(e,tail->next,tail);
				tail->next=tail->next->prev;
			}
		}
		void addToTail(int e){
			if(tail==0){
				tail = new Node(e);
				tail->next=tail;
				tail->prev=tail;
			}
			else{
				tail->next->prev=new Node(e,tail->next,tail);
				tail->next=tail->next->prev;
				tail=tail->next;
			}
		}
		int deleteFromHead(){
			if(!isEmpty()){
				int e=tail->next->data;
				if(tail->next==tail){
					delete tail;
					tail=0;
				}
				else{
					tail->next=tail->next->next;
					delete tail->next->prev;
					tail->next->prev=tail;
				}
				return e;
			}
			return 0;
		}
		int deleteFromTail(){
			if(!isEmpty()){
				int e=tail->next->data;
				if(tail->next==tail){
					delete tail;
					tail=0;
				}
				else{
					tail->prev->next=tail->next;
					tail=tail->prev;
					delete tail->next->prev;
					tail->next->prev=tail;
				}
			}
			return 0;
		}
		void display(){
			Node *t=tail->next;
			for(;t!=tail;t=t->next)
				cout<<t->data<<'\n';
			cout<<t->data<<'\n';
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
				else if(tail->next->data==e){
					deleteFromHead();
				}
				else{
					Node *t;
					for(t=tail->next;t!=tail;t=t->next){
							if(t->data==e){
								t->prev->next=t->next;
								t->next->prev=t->prev;
								break;
							}	
					}
				delete t;
				}
			}
		}
		void addNode(int e,int pos){
			int i=0;
			if(pos==1){
				addToHead(e);	return;}
			else{
				Node *t=tail->next;
				for(;t!=tail;t=t->next){
					i++;
					if(i==pos-1){
						t->next->prev=new Node(e,t->next,t);
						t->next=t->next->prev;
						return;
					}
				}
			}
			if (i+2==pos)	addToTail(e);
		}
		friend istream& operator>>(istream& in,DCList &s){
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
	DCList d;
	cin>>d;
	cout<<"\n--------\nDeleting from head:\n";
	d.deleteFromHead();
	d.display();
	cout<<"\n--------\nDeleting from tail:\n";
	d.deleteFromTail();
	d.display();
	cout<<"\n--------\nAdding:\n";
	cout<<"Enter data to add: ";
	cin>>data;
	cout<<"\nEnter position to add: ";
	cin>>pos;
	d.addNode(data,pos);
	cout<<"\nAfter adding:\n";
	d.display();
	cout<<"\n--------\nDeleting:\n";
	cout<<"Enter data to delete: ";
	cin>>data;
	d.deleteNode(data);
	cout<<"\nAfter Deleting:\n";
	d.display();
	return 0;
}