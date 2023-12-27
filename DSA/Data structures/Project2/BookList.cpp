#ifndef BOOKLIST
#define BOOKLIST
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<cstring>
#include<conio.h>
#include <windows.h>
#include "node.cpp"
using namespace std;

class BList{
	public:
		HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
		void addToTail(Node *&head , Node *n){
			if(head == NULL){
				head = n;
			}
			else{
				Node *t;
				for(t=head;t->next!=NULL;)
					t=t->next;
				t->next=n;
			}
		}
		void show(Node* head){
			if (head == NULL)
				{
					SetConsoleTextAttribute(color, 15);
					cout << "\n\n\t\t\t\t\t\t\tEmpty Record" << endl;
					return;
				}
			Node *ptr = head;
			SetConsoleTextAttribute(color, 15);
			cout << "\n\n\t\t\t\t\t\t\t<-----------------Saved Record of All Books----------------->\n\n " << endl;
			while (ptr != NULL)
			{
				SetConsoleTextAttribute(color, 15);
				cout << "\n\n\t\t\t\t\t\t\t=>";
				SetConsoleTextAttribute(color, 9);
				cout<<"\n\t\t\t\t\t\t\t\tBook ID # : " << ptr->id << endl;
				SetConsoleTextAttribute(color, 15);
				cout << "\n\t\t\t\t\t\t\t\tBook NAME: " << ptr->name << endl;
				SetConsoleTextAttribute(color, 9);
				cout << "\n\t\t\t\t\t\t\t\tAuthor NAME : " << ptr->author << endl;
				cout << endl;
				ptr = ptr->next;
			}
		}
		bool idExists(Node* &head, int id){
			Node* ptr = head;
			while (ptr != NULL){
				if(ptr->id == id)	return 1;
				ptr = ptr->next;
			}
			return 0;
		}
		bool bookExists(string n){
			ifstream file;
			file.open("LibBooks2.csv");
			if(file.is_open()){
				string line,name,auth,m;
				while(file.peek()!=EOF){
					getline(file,m,',');
					getline(file,name,',');
					if(name == n)	return 1;
					getline(file,auth,'\n');
				}
			}
			else{
				cout<<"\n\n\t\t\t\t\t\t\tCannot open record! ";
				cout<<"\n\n\t\t\t\t\t\t\tPress any key to exit: ";
				getch();
			}
			return 0;
		}
		void search(Node* &head, string name){
			Node* ptr = head;
			while (ptr != NULL){
				if(ptr->name == name){
					cout << "\n\n\t\t\t\t\t\t\tBook ID: " << ptr->id << endl;
					cout << "\n\n\t\t\t\t\t\t\tBook NAME: " << ptr->name << endl;
					cout << "\n\n\t\t\t\t\t\t\tAuthor NAME : " << ptr->author << endl;
					cout << endl
						 << endl;
					return;
				}
				ptr = ptr->next;
			}
			cout<<"\n\n\t\t\t\t\t\t\tBook does not exist in record "<<endl;
		}
		void modify(Node* &head, int id){
			Node* ptr = head;
			while (ptr != NULL)
			{
				
				if (id == ptr->id)
				{
					cin.ignore();
					cout<<"\n\n\t\t\t\t\t\t\tEnter New Book Name: ";
					getline(cin, ptr->name);
					cout<<"\n\n\t\t\t\t\t\t\tEnter New Author Name: ";
					getline(cin, ptr->author);
		
					cout << "\n\n\t\t\t\t\t\t\tRecord is updated!" << endl;
				}
				ptr = ptr->next;
			}
			convertToFile(head);
		}
		void delNode(Node *head, int id){
			Node* n;
			if(head->id == id){
				n = head;
				head = head->next;
				delete n;
			}
			else{
				Node *t;
				while (head->next->id != id)
					head = head->next;
				t = head->next;
				head->next = t->next;
				delete t;
			}
			n = head;
			convertToFile(n);
			cout << "\n\n\t\t\t\t\t\t\tBook deleted success fully!" << endl;
			return;
		}
		Node* makeList(Node *head = NULL){
			ifstream file;
			file.open("LibBooks2.csv");
			if(file.is_open()){
				string line,name,auth,m;
				int id;
				while(file.peek()!=EOF){
					Node *n = new Node;
					getline(file,m,',');
					id = atoi(m.c_str());
					getline(file,name,',');
					getline(file,auth,'\n');
					n->id = id;
					n->name = name; 
					n->author = auth;
					n->next = NULL;
					addToTail(head, n);
				}
			}
			else{
				cout<<"\n\n\t\t\t\t\t\t\tCannot open record! ";
				cout<<"\n\n\t\t\t\t\t\t\tPress any key to exit: ";
				getch();
				exit(1);
			}
			return head;
		}
		void convertToFile(Node *&head){
			Node *ptr = head;
			ofstream file;
			file.open("LibBooks2.csv");
			if(!file.is_open()){
				cout<<"\n\n\t\t\t\t\t\t\tCannot open your record!\n";
				return;
			}
			file.close();
			fstream file2;
			file2.open("LibBooks2.csv",ios::app);
			while (ptr != NULL)
			{
				file2<<ptr->id<<","<<ptr->name<<","<<ptr->author<<'\n';
				ptr = ptr->next;
			}
			file2.close();
		}
};
#endif