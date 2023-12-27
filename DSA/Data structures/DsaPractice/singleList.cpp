#include <iostream>
using namespace std;
class Node{
	public:
		int data;
		Node *next;
		Node(int data){
			this->data = data;
			next = NULL;
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
	t->next=n;
}
void addToHead(Node* &head , int val){
	Node *n = new Node(val);
	if(head == NULL){
		head = n;
		return;
	}
	n->next=head;
	head=n;
}
void insert(Node *&head, int pos, int val){
	int i=1;
	if (pos == 1)	addToHead(head,val);
	else{
		Node *n = new Node(val);
		Node *t;
		for(t=head;t!=NULL;t=t->next,i++){
			if(i == pos-1){
				n->next = t->next;
				t->next = n;
			}
		}
	}
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
void deleteFromMid(Node* &head,int val){
	Node *t;
	if(head != NULL){
		if (val == head->data)	deleteFromHead(head);
		else{
			Node *t=head,*n;
			for(;t->next->data != val;){
				t=t->next;
			}
			n = t->next;
			t->next = t->next->next;
			delete n;
		}
	}
}
bool search(Node* &head , int val){
	for(Node *t=head;t!=NULL;t=t->next)	
		if(t->data == val)	return 1;
	return 0;
}
void display(Node* head){
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
	display(head);
	deleteFromTail(head);
	display(head);
	insert(head,2,3);
	insert(head,1,4);
	display(head);
	deleteFromMid(head,3);
	display(head);
	cout<<search(head,4);
	return 0;
}