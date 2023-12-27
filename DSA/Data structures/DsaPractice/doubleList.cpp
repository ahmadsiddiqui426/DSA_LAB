#include <iostream>
using namespace std;
class Node{
	public:
		int data;
		Node *next,*prev;
		Node(int data){
			this->data = data;
			next = NULL;
			prev = NULL;
		}
};
void addToTail(Node* &head , int val){
	Node *n = new Node(val);
	if(head == NULL){
		head = n;
		return;
	}
	Node *t;
	for(t=head;t->next!=NULL;)
		t=t->next;
	t->next = n;
	n->prev = t;
}
void addToHead(Node* &head , int val){
	Node *n = new Node(val);
	if(head == NULL){
		head = n;
		return;
	}
	n->prev = NULL;
	n->next = head;
	head = n;
}
void deleteFromHead(Node* &head){
	Node *n;
	if(head!= NULL){
		n = head;
		head = head->next;
		delete n;
	}
}
void deleteFromTail(Node* &head){
	Node *t;
	if(head->next == NULL)	deleteFromHead(head);
	if(head!= NULL){
		for(t=head;t->next->next!=NULL;)
			t=t->next;
		delete t->next;
		t->next = NULL;
	}
}
void display(Node* head){
	cout<<"NULL->";
	for(Node *t=head;t!=NULL;t=t->next)
		cout<<t->data<<"->";
	cout<<"NULL"<<endl;
}
int main(){
	Node* head = NULL;
	addToTail(head,1);
	addToTail(head,2);
	addToTail(head,3);
	addToHead(head,4);
	display(head);
	deleteFromHead(head);
//	display(head);
	deleteFromTail(head);
	display(head);
//	insert(head,2,3);
//	insert(head,1,4);
//	display(head);
//	deleteFromMid(head,3);
//	display(head);
//	cout<<search(head,4);
	return 0;
}