#include <iostream>
using namespace std;
struct Node{
	int data;
	Node *left,*right,*parent;
	Node(){}
	Node(int data){
		left = right = NULL;
		this->data = data;
	}
};
		Node* insert(Node *node, int val){
			if(node == NULL)
			    {
			        node = new Node(val);
			    }
		    else if(node->data < val){
		        node->right = insert(node->right, val);
		    }
		    else
		    {
		        node->left = insert(node->left, val);
		    }
		    return node;
		}
		Node* search(Node *node, int val){
			if(node == NULL)
			    {
			        return NULL;
			    }
			else if(node->data == val){
		        return node;
		    }
		    else if(node->data < val){
		        return search(node->right, val);
		    }
		    else
		    {
		        return search(node->left, val);
		    }
		}
		void preOrder(Node *n){
			if(n == NULL)	return;
			cout<<n->data<<' ';
			preOrder(n->left);
			preOrder(n->right);
		}
		void inOrder(Node *n){
			if(n == NULL)	return;
			preOrder(n->left);
			cout<<n->data<<' ';
			preOrder(n->right);
		}
		void postOrder(Node *n){
			if(n == NULL)	return;
			preOrder(n->left);
			preOrder(n->right);
			cout<<n->data<<' ';
		}
		bool exists(Node *n, int val){
			if(n == NULL)	return 1;
			else if(n->data == val)	return 0;
			else if(n->data<val){
				exists(n->right,val);
			}
			else{
				exists(n->left,val);
			}
		}
		int counts(Node *n, int count = 0){
			if(n == NULL)	return count;
			counts(n->left,count++);
			return counts(n->right,count++);
		}
		bool bst(Node *n){
			if(n->left == NULL && n->right == NULL)	return 1;
			else if(n->right->data > n->data)
				bst(n->right);
			else if(n->left->data < n->data)
				bst(n->left);
			//return 0;
		}
int main(){
	Node *root = NULL;
	root = insert(root,1);	
	root = insert(root,2);
    root = insert(root,3);
    root = insert(root,4);
    root = insert(root,5);
    root = insert(root,8);
	preOrder(root);
	if(bst(root))	cout<<"\nIt is a binary Search tree\n";
	//Node* t = search(root,20);
	//cout<<t->data;
	if(exists(root,20))	cout<<"Yes\n";
	else cout<<"No\n";
	cout<<counts(root);
	return 0;
}