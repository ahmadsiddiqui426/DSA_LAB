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
class DLList{
	public:
	Node *head;
	Node  *tail;
	public:
		DLList(){
			head = tail = 0;
		}
		bool isEmpty(){
			if(head == 0) return 1;
			return 0;
		}
		void addToHead(int e){
			if(head == 0)	tail = head = new Node(e);
			else{
			head = new Node(e,head,0);
			head->next->prev=head;
			}
		}
		void addToTail(int e){
			if(tail != 0){
				tail = new Node(e,0,tail);
				tail->prev->next = tail;
			}
			else head = tail = new Node(e);
		}
		int deleteFromTail(){
			if(!isEmpty()){
				int e=tail->data;
				if(head==tail){
					delete tail;
					head= tail =0;
				}
				else{
					tail = tail->prev;
					delete tail->next;
					tail->next=0;
				}
				return e;
			}
			else {
			cout<<"\nEmpty";
			return 0;}
		}
		int deleteFromHead(){
			if(!isEmpty()){
				int e=head->data;
				if(head==tail){
					delete head;
					head= tail =0;
 				}
				else{
					head = head->next;
					delete head->prev;
					head->prev=0;
				}
				return e;
			}
			else {
			cout<<"\nEmpty";
			return 0;}
		}
		void deleteNode(int e){
			if(head->data == e && head==tail){
				delete head;
				head=tail=0;
			}
			else if(head->data==e){
				head=head->next;
				delete head->prev;
				head->prev=0;
			}
			else{
				Node *t;
				for(t=head->next;t!=0;t=t->next){
					if(t->data==e){
						t->prev->next=t->next;
						t->next->prev=t->prev;
						break;
					}	
				}
				delete t;
			}
		}
		void addNode(int pos, int e){
		int i=0;
		Node *temp;
		for(temp=head;temp!=0;temp=temp->next){
			i++;
			if(i==pos-1){
				Node *mid=new Node (e,temp->next,temp);
				temp->next=mid;
				mid->prev->next=mid;
			}
		}
	}
		void display(){
		for(Node *t=head;t!=0;t=t->next)
			cout<<t->data<<'\n';
	}
};
int main(){
	DLList d1;
	d1.addToHead(11);
	d1.addToHead(22);
	d1.addToTail(33);
	d1.display();
	cout<<"\n-------\n";
	
	d1.deleteNode(11);
	d1.display();
	cout<<"\n-------\n";
	d1.addNode(2,44);
	d1.display();
	
	cout<<"\n-------\n";
	cout<<d1.deleteFromHead()<<' ';
	cout<<d1.deleteFromTail()<<' ';
	cout<<"\n-------\n";
	d1.display();
	cout<<"\n-------\n";
	d1.addToHead(55);
	d1.display();
	//cout<<d1.deleteFromTail()<<' ';
	return 0;
}
		
		