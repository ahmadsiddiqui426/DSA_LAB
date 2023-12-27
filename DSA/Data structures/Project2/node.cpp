#ifndef NODE
#define NODE
#include<iostream>
using namespace std;

struct Node{
	int id;
	string name, author;
	Node *next;
	Node(){	}
	Node(int i, string a, string n, Node *next = NULL){
		id = i;
		author = a;
		name = n;
		this->next = next;
	}
};
struct SNode{
	int rollNo;
	string name, dep, date1, date2;
	SNode *next;
	int issue, fine;
	string book1, book2;
	SNode(){	}
	SNode(int r, string n, string dp, string d1 = "Nil", string d2 = "Nil", int f = 0, string b1 = "None",string b2 = "None", int iss = 0, SNode *next = NULL){
		rollNo = r;
		dep = dp;
		name = n;
		date1 = d1;
		date2 = d2;
		fine = 0;
		issue = iss;
		book1 = b1;
		book2 = b2;
		this->next = next;
	}
};
#endif