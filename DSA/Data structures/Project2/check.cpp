#include <iostream>
#include "librarian.cpp"
#include "Student.cpp"
#include <conio.h>
#include <windows.h>
using namespace std;

void welcome(){
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, 9);
	cout<<"\n\n\n\t\t\t\t\t\t\t=============================================================\n";
	cout<<"\t\t\t\t\t\t\t=============================================================\n";
	SetConsoleTextAttribute(color, 14);
	cout<<"\t\t\t\t\t\t\t========================  WELCOME TO  =======================\n";
	cout<<"\t\t\t\t\t\t\t====================  LIBRARY MANAGEMENT  ===================\n";
	cout<<"\t\t\t\t\t\t\t=========================  SYSTEM  ==========================\n";
	SetConsoleTextAttribute(color, 9);
	cout<<"\t\t\t\t\t\t\t=============================================================\n";
	cout<<"\t\t\t\t\t\t\t=============================================================\n\n\n\n";
}
class Library{
	
	public:
		void menu(){
			
			HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
			a:
			system("cls");
			welcome();
			SetConsoleTextAttribute(color, 4);
			cout<<"\t\t\t\t\t\t\tPress any key to continue ";
			getch();
			system("cls");
			welcome();
			int choice;
			SetConsoleTextAttribute(color, 4);
			cout<<"\n\n\t\t\t\t\t\t\tDescribe Yourself as:";
			SetConsoleTextAttribute(color, 11);
			cout<<"\n\n\n\t\t\t\t\t\t\t1. Librarian";
			SetConsoleTextAttribute(color, 10);
			cout<<"\n\n\n\t\t\t\t\t\t\t2. Student";
			SetConsoleTextAttribute(color, 14);
			cout<<"\n\n\n\t\t\t\t\t\t\t3. Close Application";
			SetConsoleTextAttribute(color, 6);
			cout<<"\n\n\n\t\t\t\t\t\t\tEnter choice => ";
			cin>>choice;
			
			SetConsoleTextAttribute(color, 2);
			if(choice == 1){
				system("cls");
				Librarian l;
				l.menu2();
				return;
			}
			else if(choice == 2){
				system("cls");
				Student s;
				s.menu();
				return;
			}
			else if(choice == 3){
				exit(0);
			}
			else
					cout << "\n\n\n\t\t\t\t\t\t\tInvalid choice\n\t\t\t\t\t\t\tEnter Again";
				
				getch();
				goto a;
		}
};
int main(){
	Library lib;
	lib.menu();
	return 0;
}
