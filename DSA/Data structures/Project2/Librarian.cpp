#ifndef LIBRARIAN
#define LIBRARIAN
#include <iostream>
#include <conio.h>
#include <fstream>
#include <sstream>
#include <string>
#include <conio.h>
#include <windows.h>
#include "node.cpp"
#include "BookList.cpp"
#include "StudentList.cpp"

using namespace std;

void lib(){
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, 11);
	cout<<"\n\n\n\t\t\t\t\t\t\t********************";
	SetConsoleTextAttribute(color, 4);
	cout<<"  LIBRARY MANAGEMENT  ";
	SetConsoleTextAttribute(color, 11);
	cout<<"*******************\n";
	cout<<"\t\t\t\t\t\t\t*************************";
	SetConsoleTextAttribute(color, 4);
	cout<<"  SYSTEM  ";
	SetConsoleTextAttribute(color, 11);
	cout<<"**************************\n\n\n\n";
}
class Librarian{
	BList b;
	SList s;
	public:
		Node* head = NULL;
		HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
		void menu2(){
			p:
				system("cls");
				lib();
				SetConsoleTextAttribute(color, 4);
				cout <<"\t\t\t\t\t\t\t<--------------------";
				SetConsoleTextAttribute(color, 11);
				cout<<"  LIBRARIAN  MENU  ";
				SetConsoleTextAttribute(color, 4);
				cout<<"-------------------->" << endl;
				int choice;
				SetConsoleTextAttribute(color, 3);
				cout << "\n\n\t\t\t\t\t\t\t 1.Insert BOOK.";
				SetConsoleTextAttribute(color, 10);
				cout << "\n\n\t\t\t\t\t\t\t 2.Modify BOOK.";
				SetConsoleTextAttribute(color, 12);
				cout << "\n\n\t\t\t\t\t\t\t 3.Search BOOK.";
				SetConsoleTextAttribute(color, 14);
				cout << "\n\n\t\t\t\t\t\t\t 4.Delete BOOK.";
				SetConsoleTextAttribute(color, 9);
				cout << "\n\n\t\t\t\t\t\t\t 5.Show all BOOKS.";
				SetConsoleTextAttribute(color, 15);
				cout << "\n\n\t\t\t\t\t\t\t 6.Delete all Book RECORD.";
				SetConsoleTextAttribute(color, 4);
				cout << "\n\n\t\t\t\t\t\t\t 7.View STUDENT list.";
				SetConsoleTextAttribute(color, 7);
				cout << "\n\n\t\t\t\t\t\t\t 8.Add student to  STUDENT list.";
				SetConsoleTextAttribute(color, 6);
				cout << "\n\n\t\t\t\t\t\t\t 9.Delete student from  STUDENT list.";
				SetConsoleTextAttribute(color, 2);
				cout << "\n\n\t\t\t\t\t\t\t 10.Delete all student RECORD.";
				SetConsoleTextAttribute(color, 9);
				cout << "\n\n\t\t\t\t\t\t\t 11.Issue fine.";
				SetConsoleTextAttribute(color, 12);
				cout << "\n\n\t\t\t\t\t\t\t 12.Exit.";
				SetConsoleTextAttribute(color, 8);
				cout << "\n\n\n\t\t\t\t\t\t\t Enter your choice.";
				cin >> choice;
				switch (choice)
				{
				case 1:
					system("cls");
					lib();
					SetConsoleTextAttribute(color, 3);
					cout <<"\t\t\t\t\t\t\t<-----------------------  INSERT BOOK  ---------------------->" << endl;
					addBook();
					break;
				case 2:
					system("cls");
					lib();
					SetConsoleTextAttribute(color, 10);
					cout <<"\t\t\t\t\t\t\t<-----------------------  MODIFY BOOK  ---------------------->" << endl;
					update();
					break;
				case 3:
					system("cls");
					lib();
					SetConsoleTextAttribute(color, 12);
					cout <<"\t\t\t\t\t\t\t<-----------------------  SEARCH BOOK  ---------------------->" << endl;
					searchBook();
					break;
				case 4:
					system("cls");
					lib();
					SetConsoleTextAttribute(color, 14);
					cout <<"\t\t\t\t\t\t\t<-----------------------  DELETE BOOK  ---------------------->" << endl;
					delBook();
					break;
				case 5:
					system("cls");
					lib();
					SetConsoleTextAttribute(color, 9);
					cout <<"\t\t\t\t\t\t\t<-----------------------  VIEW RECORD  ---------------------->" << endl;
					bookRecord();
					break;
				case 6:
					system("cls");
					lib();
					SetConsoleTextAttribute(color, 15);
					cout <<"\t\t\t\t\t\t\t<----------------------  DELETE RECORD  --------------------->" << endl;
					delRecord();
					break;
				case 7:
					system("cls");
					lib();
					SetConsoleTextAttribute(color, 4);
					cout <<"\t\t\t\t\t\t\t<---------------------  STUDENT RECORD  --------------------->" << endl;
					StuRecord();
					break;
				case 8:
					system("cls");
					lib();
					SetConsoleTextAttribute(color, 7);
					cout <<"\t\t\t\t\t\t\t<-----------------------  ADD STUDENT  ---------------------->" << endl;
					addStu();
					break;
				case 9:
					system("cls");
					lib();
					SetConsoleTextAttribute(color, 6);
					cout <<"\t\t\t\t\t\t\t<---------------------  REMOVE STUDENT  --------------------->" << endl;
					removeStu();
					break;
				case 10:
					system("cls");
					lib();
					SetConsoleTextAttribute(color, 2);
					cout <<"\t\t\t\t\t\t\t<----------------------  DELETE RECORD  --------------------->" << endl;
					delStuRecord();
					break;
				case 11:
					system("cls");
					lib();
					SetConsoleTextAttribute(color, 9);
					cout <<"\t\t\t\t\t\t\t<----------------------  ISSUE FINE  ------------------------>" << endl;
					fine();
					break;
				case 12:
					exit(0);
				default:
					SetConsoleTextAttribute(color, 12);
					cout << "\n\t\t\t\t\t\t\t Invalid choice\n";
				}
				getch();
				goto p;
		}
				
		void addBook(){
			int id;
			string n, a;
			char ch;
			head = b.makeList();
			a:
			cout<<"\n\n\t\t\t\t\t\t\tEnter Book ID: ";
			cin>>id;
			if(b.idExists(head, id)){
				cout<<"\n\n\t\t\t\t\t\t\tThis Book ID exists!\n\n\t\t\t\t\t\t\tPress any key to go back to menu: ";
				getch();
				menu2();
			}
			cin.ignore();
			cout<<"\n\n\t\t\t\t\t\t\tEnter Book Name: ";
			getline(cin, n);
			cout<<"\n\n\t\t\t\t\t\t\tEnter Author Name: ";
			getline(cin, a);
			cout<<"\n\n\n\t\t\t\t\t\t\tBook added successfully! ";
			Node *temp = new Node;
			temp->name = n;
			temp->id = id;
			temp->author = a;
			temp->next = NULL;
			fstream file;
			file.open("LibBooks2.csv",ios::app);
			if(!file.is_open()){
				cout<<"\n\n\t\t\t\t\t\t\tCannot open file to update record!\n";
			}
			else{
				file<<temp->id<<","<<temp->name<<","<<temp->author<<'\n';
				file.close();
			}
			b.addToTail(head,temp);
		}
		void bookRecord(){
			head = b.makeList();
			b.show(head);
		}
		void update(){
			int id;
			Node *temp = new Node;
			head = b.makeList();
			cout<<"\n\n\t\t\t\t\t\t\tEnter Book ID to modify: ";
			cin>>id;
			if(b.idExists(head, id)){
				head = b.makeList();
				b.modify(head, id);
			}
			else	cout<<"\n\n\t\t\t\t\t\t\tThis book ID does not exist\n";
		}
		void delBook(){
			int id;
			cout<<"\n\n\t\t\t\t\t\t\tEnter book ID to delete:  ";
			cin>>id;
			head = b.makeList();
			if(b.idExists(head, id)){
				b.delNode(head, id);
			}
			else	cout<<"\n\n\t\t\t\t\t\t\tThis book ID does not exist\n";
		}
		void delRecord(){
			ofstream file;
			file.open("LibBooks2.csv");
			if(!file.is_open()){
				cout<<"\n\n\t\t\t\t\t\t\tCannot open file!\n";
				return;
			}
			file.close();
			cout<<"\n\n\t\t\t\t\t\t\tRecord deleted successfully!\n";
		}
		void searchBook(){
			string name;
			cin.ignore();
			cout<<"\n\n\t\t\t\t\t\t\tEnter Book Name to search: ";
			getline(cin, name);
			head = b.makeList();
			b.search(head, name);
		}
		void bookDetails(string name){
			head = b.makeList();
			b.search(head, name);
		}
		SNode *head2 = NULL;
		void addStu(){
			head2 = s.stuList();
			string name, dep;
			int roll;
			char ch;
			b:
			cout<<"\n\n\t\t\t\t\t\t\tEnter Student Roll no.: ";
			cin>>roll;
			if(s.rollExists(head2, roll)){
				cout<<"\n\n\t\t\t\t\t\t\tThis Roll No. exists!\n\n\t\t\t\t\t\t\tPress any key to go back to menu: ";
				getch();
				menu2();
			}
			cin.ignore();
			cout<<"\n\n\t\t\t\t\t\t\tEnter Student Name: ";
			getline(cin, name);
			cout<<"\n\n\t\t\t\t\t\t\tEnter Student Department: ";
			cin>>dep;
			cout<<"\n\n\t\t\t\t\t\t\tStudent added successfully! ";
			SNode *temp = new SNode;
			temp->name = name;
			temp->rollNo = roll;
			temp->dep = dep;
			temp->issue = 0;
			temp->book1 = "None";
			temp->book2 = "None";
			temp->date1 = "Nil";
			temp->date2 = "Nil";
			temp->fine = 0;
			temp->next = NULL;
			fstream file;
			file.open("Students.csv",ios::app);
			if(!file.is_open()){
				cout<<"\n\n\t\t\t\t\t\t\tCannot open file to update record!\n";
			}
			else{
				file<<temp->rollNo<<","<<temp->name<<","<<temp->dep<<","<<temp->issue<<","
				<<temp->book1<<","<<temp->book2<<","<<temp->date1<<","<<temp->date2<<","<<temp->fine<<'\n';
				file.close();
			}
			s.addToTail(head2,temp);
		}
		void removeStu(){
			int roll;
			cout<<"\n\n\t\t\t\t\t\t\tEnter roll No. of student to delete:  \n";
			cin>>roll;
			head2 = s.stuList();
			if(s.rollExists(head2, roll)){
				s.delstu(head2, roll);
			}
		}
		void StuRecord(){
			head2 = s.stuList();
			s.show(head2);
		}
		void delStuRecord(){
			ofstream file;
			file.open("Students.csv");
			if(!file.is_open()){
				cout<<"\n\n\t\t\t\t\t\t\tCannot open file!\n";
				return;
			}
			file.close();
			cout<<"\n\n\t\t\t\t\t\t\tRecord deleted successfully!\n";
		}
		void fine(){
			string date;
			int roll;
			head2 = s.stuList();
			cout<<"\n\n\t\t\t\t\t\t\tEnter Roll no.: ";
			cin>>roll;
			if(s.noOfBooks(head2, roll) == 0){
				cout << "\n\n\t\t\t\t\t\t\tThis roll number has not issued any book!" << endl;
				cout<<"\n\n\t\t\t\t\t\t\tPress any key to go to menu";
				getch();
				return;
			}
			cin.ignore();
			cout<<"\n\n\t\t\t\t\t\t\tEnter Today's Date: ";
			getline(cin,date);
			s.fineIssue(head2, roll, date);
		}
};
#endif