#ifndef STUDENT
#define STUDENT
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "node.cpp"
#include "StudentList.cpp"
#include "Librarian.cpp"
#include "BookList.cpp"

using namespace std;

void stu(){
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
class Student{
	SList s;
	Librarian l;
	BList b;
	public:
		SNode* head = NULL;
		void menu(){
			p:
				HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
				system("cls");
				stu();
				int choice;
				SetConsoleTextAttribute(color, 4);
				cout <<"\t\t\t\t\t\t\t<--------------------";
				SetConsoleTextAttribute(color, 11);
				cout<<"  STUDENT  MENU  ";
				SetConsoleTextAttribute(color, 4);
				cout<<"-------------------->" << endl;
				SetConsoleTextAttribute(color, 3);
				cout << "\n\n\t\t\t\t\t\t\t 1.View Student List.";
				SetConsoleTextAttribute(color, 10);
				cout << "\n\n\t\t\t\t\t\t\t 2.Search Your Name in Student List.";
				SetConsoleTextAttribute(color, 12);
				cout << "\n\n\t\t\t\t\t\t\t 3.View Book List.";
				SetConsoleTextAttribute(color, 14);
				cout << "\n\n\t\t\t\t\t\t\t 4.Search BOOK.";
				SetConsoleTextAttribute(color, 9);
				cout << "\n\n\t\t\t\t\t\t\t 5.Issue BOOK.";
				SetConsoleTextAttribute(color, 15);
				cout << "\n\n\t\t\t\t\t\t\t 6.Re-Issue BOOK.";
				SetConsoleTextAttribute(color, 4);
				cout << "\n\n\t\t\t\t\t\t\t 7.View your Issued BOOKS.";
				SetConsoleTextAttribute(color, 7);
				cout << "\n\n\t\t\t\t\t\t\t 8.Return Book.";
				SetConsoleTextAttribute(color, 6);
				cout << "\n\n\t\t\t\t\t\t\t 9.View Your Fine.";
				SetConsoleTextAttribute(color, 2);
				cout << "\n\n\t\t\t\t\t\t\t 10.Exit.";
				SetConsoleTextAttribute(color, 8);
				cout << "\n\n\n\t\t\t\t\t\t\t Enter your choice.";
				cin >> choice;
				switch (choice)
				{
				case 1:
					system("cls");
					stu();
					SetConsoleTextAttribute(color, 3);
					cout <<"\t\t\t\t\t\t\t<--------------------  VIEW STUDENT LIST  ------------------->" << endl;
					StuRecord();
					break;
				case 2:
					system("cls");
					stu();
					SetConsoleTextAttribute(color, 10);
					cout <<"\t\t\t\t\t\t\t<--------------------  SEARCH YOUR NAME  -------------------->" << endl;
					SearchStu();
					break;
				case 3:
					system("cls");
					stu();
					SetConsoleTextAttribute(color, 12);
					cout <<"\t\t\t\t\t\t\t<--------------------  VIEW BOOK RECORD  -------------------->" << endl;
					l.bookRecord();
					break;
				case 4:
					system("cls");
					stu();
					SetConsoleTextAttribute(color, 14);
					cout <<"\t\t\t\t\t\t\t<-----------------------  SEARCH BOOK  ---------------------->" << endl;
					l.searchBook();
					break;
				case 5:
					system("cls");
					stu();
					SetConsoleTextAttribute(color, 9);
					cout <<"\t\t\t\t\t\t\t<-----------------------  ISSUE BOOK  ----------------------->" << endl;
					issue();
					break;
				case 6:
					system("cls");
					stu();
					SetConsoleTextAttribute(color, 15);
					cout <<"\t\t\t\t\t\t\t<---------------------  RE-ISSUE BOOK  ---------------------->" << endl;
					reIssue();
					break;
				case 7:
					system("cls");
					stu();
					SetConsoleTextAttribute(color, 4);
					cout <<"\t\t\t\t\t\t\t<----------------  VIEW YOUR  ISSUED BOOKS  ------------------>" << endl;
					view();
					break;
				case 8:
					system("cls");
					stu();
					SetConsoleTextAttribute(color, 7);
					cout <<"\t\t\t\t\t\t\t<-----------------------  RETURN BOOK  ----------------------->" << endl;
					returning();
					break;
				case 9:
					system("cls");
					stu();
					SetConsoleTextAttribute(color, 6);
					cout <<"\t\t\t\t\t\t\t<----------------------  VIEW YOUR FINE  --------------------->" << endl;
					viewFine();
					break;
				case 10:
					exit(0);
				default:
					SetConsoleTextAttribute(color, 15);
					cout << "\n\n\t\t\t\t\t\t\tInvalid choice\n";
				}
				getch();
				goto p;
		}
				
		void StuRecord(){
			head = s.stuList();
			s.show(head);
		}
		void SearchStu(){
			string name;
			cin.ignore();
			cout<<"\n\n\t\t\t\t\t\t\tEnter Your Name: ";
			getline(cin, name);
			head = s.stuList(head);
			s.searchName(head, name);
			return;
		}
		void issue(){
			string name, date;
			char ch;
			int roll;
			head = s.stuList();
			cout<<"\n\n\t\t\t\t\t\t\tEnter your roll number: ";
			cin>>roll;
			if(s.rollExists(head, roll)){
				if(s.noOfBooks(head, roll) == 2){
				cout << "\n\n\t\t\t\t\t\t\tYou have issued your both books!\n\n\t\t\t\t\t\t\tReturn them to issue more!" << endl;
				cout<<"\n\n\t\t\t\t\t\t\tPress any key to go to menu";
				getch();
				menu();
				}
				cin.ignore();
				cout<<"\n\n\t\t\t\t\t\t\tEnter Book Name to issue: ";
				getline(cin, name);
				j:
				if(b.bookExists(name)){
					cout<<"\n\n\t\t\t\t\t\t\tEnter Date of issuing: ";
					getline(cin,date);
					s.bookIssue(head, roll, name, date);
				}
				else{
					cout<<"\n\n\t\t\t\t\t\t\tThis book is not available in book record"<<endl;
					return;
				}
			}
			else{
				cout<<"\n\n\t\t\t\t\t\t\tThis roll number is not enrolled in student list"<<endl;
				cout<<"\n\n\t\t\t\t\t\t\tPress any key to go to menu";
				getch();
				menu();
			}
		}
		void view(){
			int roll;
			head = s.stuList();
			cout<<"\n\n\t\t\t\t\t\t\tEnter your roll number: ";
			cin>>roll;
			if(s.rollExists(head, roll)){
				s.viewIssued(head, roll);
			}
			else{
				cout<<"\n\n\t\t\t\t\t\t\tThis roll number is not enrolled in student list"<<endl;
				cout<<"\n\n\t\t\t\t\t\t\tPress any key to go to menu";
				getch();
				menu();
			}
		}
		void returning(){
			int roll;
			head = s.stuList();
			cout<<"\n\n\t\t\t\t\t\t\tEnter your roll number: ";
			cin>>roll;
			if(s.rollExists(head, roll)){
				if(s.noOfBooks(head, roll) == 0){
					cout << "\n\n\t\t\t\t\t\t\tYou have not issued any book!"<< endl;
					cout<<"\n\n\t\t\t\t\t\t\tPress any key to go to menu";
					getch();
					menu();
					return;
				}
				cin.ignore();
				string name;
				cout<<"\n\n\t\t\t\t\t\t\tEnter Book Name to return: ";
				getline(cin, name);
				if(b.bookExists(name)){
					s.returnBook(head, roll, name);
				}
				else{
					cout<<"\n\n\t\t\t\t\t\t\tThis book is not available in book record"<<endl;
					return;
				}
			}
			else{
				cout<<"\n\n\t\t\t\t\t\t\tThis roll number is not enrolled in student list"<<endl;
				cout<<"\n\n\t\t\t\t\t\t\tPress any key to go to menu";
				getch();
				menu();
			}
		}
		void viewFine(){
			int roll;
			head = s.stuList();
			cout<<"\n\n\t\t\t\t\t\t\tEnter your roll number: ";
			cin>>roll;
			if(s.rollExists(head, roll)){
				if(s.Fine(head, roll) == 0){
					cout<<"\n\n\t\t\t\t\t\t\tYou don't have any fine to pay\n";
				}
				else{
					cout<<"\n\n\t\t\t\t\t\t\tYou have to pay "<<s.Fine(head, roll)<<"Rs. fine\n";
				}
			}
			else{
				cout<<"\n\n\t\t\t\t\t\t\tThis roll number is not enrolled in student list"<<endl;
				cout<<"\n\n\t\t\t\t\t\t\tPress any key to go to menu";
				getch();
				menu();
			}
		}
		void reIssue(){
			int roll;
			head = s.stuList();
			cout<<"\n\n\t\t\t\t\t\t\tEnter your roll number: ";
			cin>>roll;
			if(s.rollExists(head, roll)){
				if(s.noOfBooks(head, roll) == 0){
					cout << "\n\n\t\t\t\t\t\t\tYou have not issued any book!"<< endl;
					cout<<"\n\n\t\t\t\t\t\t\tPress any key to go to menu";
					getch();
					menu();
					return;
				}
				
				if(s.Fine(head, roll) == 0){
					cin.ignore();
					string name;
					cout<<"\n\n\t\t\t\t\t\t\tEnter Book Name to re-issue: ";
					getline(cin, name);
					if(b.bookExists(name)){
						s.issueAgain(head, roll, name);
					}
					else{
						cout<<"\n\n\t\t\t\t\t\t\tThis book is not available in book record"<<endl;
						return;
					}
				}
				else{
					cout<<"\n\n\t\t\t\t\t\t\tPay Your fine to re-issue any book"<<endl;
				}
			}
			else{
				cout<<"\n\n\t\t\t\t\t\t\tThis roll number is not enrolled in student list"<<endl;
				cout<<"\n\n\t\t\t\t\t\t\tPress any key to go to menu";
				getch();
				menu();
			}
		}
};
#endif