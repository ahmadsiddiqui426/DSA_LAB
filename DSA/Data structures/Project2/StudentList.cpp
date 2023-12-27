#ifndef SL
#define SL
#include<iostream>
#include<fstream>
#include <string>
#include<conio.h>
#include <windows.h>
#include "node.cpp"
using namespace std;

class SList{
	public:
		HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
		void addToTail(SNode *&head , SNode *n){
			if(head == NULL){
				head = n;
			}
			else{
				SNode *t;
				for(t=head;t->next!=NULL;)
					t=t->next;
				t->next=n;
			}
		}
		void show(SNode* head){
			if (head == NULL)
				{
					SetConsoleTextAttribute(color, 15);
					cout << "\n\n\t\t\t\t\t\t\tEmpty Record" << endl;
					return;
				}
			SNode *ptr = head;
			SetConsoleTextAttribute(color, 15);
			cout << "\n\n\t\t\t\t\t\t\t<---------------Saved Record of All Students--------------->\n\n " << endl;
			while (ptr != NULL)
			{
				SetConsoleTextAttribute(color, 15);
				cout << "\n\n\t\t\t\t\t\t\t=>";
				SetConsoleTextAttribute(color, 3);
					cout << "\n\t\t\t\t\t\t\t\tRoll # : " << ptr->rollNo << endl;
				SetConsoleTextAttribute(color, 15);
				cout << "\n\t\t\t\t\t\t\t\tStudent NAME: " << ptr->name << endl;
				SetConsoleTextAttribute(color, 3);
				cout << "\n\t\t\t\t\t\t\t\tDepartment : " << ptr->dep << endl;
				cout << endl;
				ptr = ptr->next;
			}
		}
		SNode* stuList(SNode* head = NULL){
			ifstream file;
			file.open("Students.csv");
			if(file.is_open()){
				string i, iss, date1, date2, fine;
				while(file.peek()!=EOF){
					SNode *n = new SNode;
					getline(file,i,',');
					n->rollNo = atoi(i.c_str());
					getline(file,n->name,',');
					getline(file,n->dep,',');
					getline(file,iss,',');
					n->issue = atoi(iss.c_str());
					getline(file,n->book1,',');
					getline(file,n->book2,',');
					getline(file,n->date1,',');
					getline(file,n->date2,',');
					getline(file,fine,'\n');
					n->fine = atoi(fine.c_str());
					n->next = NULL;
					addToTail(head, n);
				}
			}
			else{
				cout<<"\n\n\t\t\t\t\t\t\tCannot open record! ";
				cout<<"\n\n\t\t\t\t\t\t\tPress any key to exit: ";
				getch();
			}
			return head;
		}
		bool rollExists(SNode* &head, int r){
			SNode* ptr = head;
			while (ptr != NULL){
				if(ptr->rollNo == r)	return 1;
				ptr = ptr->next;
			}
			return 0;
		}
		void searchName(SNode* &head, string n){
			SNode* ptr = head;
			while (ptr != NULL){
				if(ptr->name == n){
					cout << "\n\n\t\t\t\t\t\t\t=>\n\t\t\t\t\t\t\t\tRoll # : " << ptr->rollNo << endl;
					cout << "\n\t\t\t\t\t\t\t\tStudent NAME: " << ptr->name << endl;
					cout << "\n\t\t\t\t\t\t\t\tDepartment : " << ptr->dep << endl;
					cout << endl;
					return;
				}
				ptr = ptr->next;
			}
			cout<<"\n\n\t\t\t\t\t\t\tYou are not enrolled in student list"<<endl;
		}
		void bookIssue(SNode *&head,int roll, string name, string date){
			SNode* ptr = head;
			char n;
			while (ptr != NULL)
			{
				if (roll == ptr->rollNo)
				{
					if(ptr->book1 == name || ptr->book2 == name)
						cout << "\n\n\t\t\t\t\t\t\tYou have already issued this book!"<< endl;
					else{
						string d1, d2;
						int i;
						for(i=0;date[i]!=' ';i++)
							d1[i] = date[i]; 
						i++;
						for(int j=0;date[i]!='\0';i++,j++)
							d2[j] = date[i]; 
						int d = atoi(d1.c_str());
						int m = atoi(d2.c_str());
						d += 10;
						m+=(d/30);
						m = m%12;
						if(ptr->book1 == "None" && ptr->book2 == "None"){			
							cout << "\n\n\t\t\t\t\t\t\tCongratulations! You have issued your first book!" << endl;
							if(m == 1)			cout << "\n\n\t\t\t\t\t\t\tYou have to return this book till "<<d%30<<" of "<<m<<"st month" << endl;
							else if (m == 2)	cout << "\n\n\t\t\t\t\t\t\tYou have to return this book till "<<d%30<<" of "<<m<<"nd month" << endl;
							else if(m == 3)		cout << "\n\n\t\t\t\t\t\t\tYou have to return this book till "<<d%30<<" of "<<m<<"rd month" << endl;
							else 				cout << "\n\n\t\t\t\t\t\t\tYou have to return this book till "<<d%30<<" of "<<m%12<<"th month" << endl;
							ptr->book1 = name;
							ptr->issue += 1;
							ptr->date1 = date;
						}
						else if(ptr->book1 != "None" && ptr->book2 == "None"){			
							cout << "\n\n\t\t\t\t\t\t\tCongratulations! You have issued your second book!" << endl;
							if(m == 1)			cout << "\n\n\t\t\t\t\t\t\tYou have to return this book till "<<d%30<<" of "<<m<<"st month" << endl;
							else if (m == 2)	cout << "\n\n\t\t\t\t\t\t\tYou have to return this book till "<<d%30<<" of "<<m<<"nd month" << endl;
							else if(m == 3)		cout << "\n\n\t\t\t\t\t\t\tYou have to return this book till "<<d%30<<" of "<<m<<"rd month" << endl;
							else 				cout << "\n\n\t\t\t\t\t\t\tYou have to return this book till "<<d%30<<" of "<<m<<"th month" << endl;
							ptr->book2 = name;
							ptr->issue += 1;
							ptr->date2 = date;
						}
						else if(ptr->book1 == "None" && ptr->book2 != "None"){			
							cout << "\n\n\t\t\t\t\t\t\tCongratulations! You have issued your second book!" << endl;
							if(m == 1)			cout << "\n\n\t\t\t\t\t\t\tYou have to return this book till "<<d%30<<" of "<<m<<"st month" << endl;
							else if (m == 2)	cout << "\n\n\t\t\t\t\t\t\tYou have to return this book till "<<d%30<<" of "<<m<<"nd month" << endl;
							else if(m == 3)		cout << "\n\n\t\t\t\t\t\t\tYou have to return this book till "<<d%30<<" of "<<m<<"rd month" << endl;
							else 				cout << "\n\n\t\t\t\t\t\t\tYou have to return this book till "<<d%30<<" of "<<m<<"th month" << endl;
							ptr->book1 = name;
							ptr->issue+=1;
							ptr->date1 = date;
						}
					}
				}
				ptr = ptr->next;
			}
			convertToFile(head);
		}
		int noOfBooks(SNode *&head, int roll){
			SNode *ptr = head;
			while (ptr != NULL)
			{
				if (roll == ptr->rollNo)
				{
					return ptr->issue;
				}
				ptr = ptr->next;
			}
			return 0;
		}
		void viewIssued(SNode *&head, int roll){
			SNode *ptr = head;
			while (ptr != NULL)
			{
				
				if (roll == ptr->rollNo)
				{
					if(ptr->book1 != "None"){
						string d1, d2;
						int i;
						for(i=0;ptr->date1[i]!=' ';i++)
							d1[i] = ptr->date1[i]; 
						i++;
						for(int j=0;ptr->date1[i]!='\0';i++,j++)
							d2[j] = ptr->date1[i]; 
						int d = atoi(d1.c_str());
						int m = atoi(d2.c_str());
						d += 10;
						m += (d/30);
						m = m%12;
						if(m == 1)			cout << "\n\n\t\t\t\t\t\t\tYou have issued book named '"<<ptr->book1<<"'\n\n\t\t\t\t\t\t\tYou have to return this book till "<<d%30<<" of "<<m<<"st month\n";
						else if (m == 2)	cout << "\n\n\t\t\t\t\t\t\tYou have issued book named '"<<ptr->book1<<"'\n\n\t\t\t\t\t\t\tYou have to return this book till "<<d%30<<" of "<<m<<"nd month\n";
						else if(m == 3)		cout << "\n\n\t\t\t\t\t\t\tYou have issued book named '"<<ptr->book1<<"'\n\n\t\t\t\t\t\t\tYou have to return this book till "<<d%30<<" of "<<m<<"rd month\n";
						else 				cout << "\n\n\t\t\t\t\t\t\tYou have issued book named '"<<ptr->book1<<"'\n\n\t\t\t\t\t\t\tYou have to return this book till "<<d%30<<" of "<<m<<"th month\n";
					}
					if(ptr->book2 != "None"){
						string d1, d2;
						int i;
						for(i=0;ptr->date2[i]!=' ';i++)
							d1[i] = ptr->date2[i]; 
						i++;
						for(int j=0;ptr->date2[i]!='\0';i++,j++)
							d2[j] = ptr->date2[i]; 
						int d = atoi(d1.c_str());
						int m = atoi(d2.c_str());
						d += 10;
						m += (d/30);
						m = m%12;
						if(m == 1)			cout << "\n\n\t\t\t\t\t\t\tYou have issued book named '"<<ptr->book2<<"'\n\n\t\t\t\t\t\t\tYou have to return this book till "<<d%30<<" of "<<m<<"st month\n";
						else if (m == 2)	cout << "\n\n\t\t\t\t\t\t\tYou have issued book named '"<<ptr->book2<<"'\n\n\t\t\t\t\t\t\tYou have to return this book till "<<d%30<<" of "<<m<<"nd month\n";
						else if(m == 3)		cout << "\n\n\t\t\t\t\t\t\tYou have issued book named '"<<ptr->book2<<"'\n\n\t\t\t\t\t\t\tYou have to return this book till "<<d%30<<" of "<<m<<"rd month\n";
						else 				cout << "\n\n\t\t\t\t\t\t\tYou have issued book named '"<<ptr->book2<<"'\n\n\t\t\t\t\t\t\tYou have to return this book till "<<d%30<<" of "<<m<<"th month\n";
					}
					if(ptr->book1 == "None" && ptr->book2 == "None")
					{
						cout<<"\n\n\t\t\t\t\t\t\tYou have not issued any book\n";
						return;
					}
				}
				ptr = ptr->next;
			}
		}
		void returnBook(SNode* &head, int r, string n){
			SNode *ptr = head;
			while (ptr != NULL)
			{
				if (r == ptr->rollNo)
				{
					if(ptr->fine == 0){
						if(ptr->book1 == n){		
						ptr->book1 = "None";
						ptr->issue = ptr->issue-1;
						ptr->date1 = "Nil";
						cout<<"\n\n\t\t\t\t\t\t\tBook returned\n";
						}
						else if(ptr->book2 == n){		
							ptr->book2 = "None";
							ptr->issue = ptr->issue-1;
							ptr->date2 = "Nil";
							cout<<"\n\n\t\t\t\t\t\t\tBook returned\n";
						}
						else{
							cout<<"\n\n\t\t\t\t\t\t\tYou have not issued this book!\n";
						}
					}
					else{
						cout<<"\n\n\t\t\t\t\t\t\tSubmit your fine to return book\n";
					}
				}
				ptr = ptr->next;
			}
			convertToFile(head);
		}
		void fineIssue(SNode* &head, int r, string date){
			SNode *ptr = head;
			string d1, d2;
			int i;
			for(i=0;date[i]!=' ';i++)
				d1[i] = date[i]; 
			i++;
			for(int j=0;date[i]!='\0';i++,j++)
				d2[j] = date[i]; 
			int d = atoi(d1.c_str());
			int m = atoi(d2.c_str());
			m += (d/30);
			while(ptr != NULL){
				if(ptr->rollNo == r){
					if(ptr->book1 != "None" && ptr->book2 != "None"){
						string s1, s2, s3, s4;
						int i, date1, month1, date2, month2;
						for(i=0;ptr->date1[i]!=' ';i++)
							s1[i] = ptr->date1[i]; 
						i++;
						for(int j=0;ptr->date1[i]!='\0';i++,j++)
							s2[j] = ptr->date1[i]; 
						date1 = atoi(s1.c_str());
						month1 = atoi(s2.c_str());
						date1 += 10;
						month1 += (date1/30);
						date1 = date1%30;
						for(i=0;ptr->date2[i]!=' ';i++)
							s3[i] = ptr->date2[i]; 
						i++;
						for(int j=0;ptr->date2[i]!='\0';i++,j++)
							s4[j] = ptr->date2[i]; 
						date2 = atoi(s3.c_str());
						month2 = atoi(s4.c_str());
						date2 += 10;
						month2 += (date2/30);
						date2 = date2%30; 
						if(month1 < m && month2 < m)
							ptr->fine = 2000;
						else if(month1 < m || month2 < m)
							ptr->fine += 1000;
						else if((month1 == m && date1 < d) && (month2 == m && date2 <d))
							ptr->fine = 2000;
						if((month1 == m && date1 < d) || (month2 == m && date2 <d))
							ptr->fine += 1000;
					}
					else if((ptr->book1 != "None" && ptr->book2 == "None") || (ptr->book1 == "None" && ptr->book2 != "None")){
						string s1, s2;
						int i, date1, month1;
						if(ptr->book1 != "None"){
							for(i=0;ptr->date1[i]!=' ';i++)
								s1[i] = ptr->date1[i]; 
							i++;
							for(int j=0;ptr->date1[i]!='\0';i++,j++)
								s2[j] = ptr->date1[i]; 
							date1 = atoi(s1.c_str());
							month1 = atoi(s2.c_str());
							date1 += 10;
							month1 += (date1/30);
							date1 = date1%30;
							if(month1 < m)	ptr->fine +=1000;
							else if(month1 == m && date1 < d)	ptr->fine +=1000;
						}
						else if(ptr->book2 != "None"){
							for(i=0;ptr->date2[i]!=' ';i++)
								s1[i] = ptr->date2[i]; 
							i++;
							for(int j=0;ptr->date2[i]!='\0';i++,j++)
								s2[j] = ptr->date2[i]; 
							date1 = atoi(s1.c_str());
							month1 = atoi(s2.c_str());
							date1 += 10;
							month1 += (date1/30);
							date1 = date1%30;
							if(month1 < m)	ptr->fine +=1000;
							else if(month1 == m && date1 < d)	ptr->fine +=1000;
						}
					}
				}
				ptr = ptr->next;	
			}
			cout<<"\n\n\t\t\t\t\t\t\tFine Issued\n";
			convertToFile(head);
		}
		void delstu(SNode* &head, int r){
			SNode* n;
			if(head->rollNo == r){
				n = head;
				head = head->next;
				delete n;
			}
			else{
				SNode *t;
				while (head->next->rollNo != r)
					head = head->next;
				t = head->next;
				head->next = t->next;
				delete t;
			}
			n = head;
			cout << "\n\n\t\t\t\t\t\t\tStudent removed successfully!" << endl;
			convertToFile(n);
			return;
		}
		int Fine(SNode *&head, int roll){
			SNode *ptr = head;
			while (ptr != NULL)
			{
				if (roll == ptr->rollNo){
					if(ptr->fine == 0){
						return 0;
					}
					return ptr->fine;
				}
					
				ptr = ptr->next;
			}
			return 0;
		}
		void issueAgain(SNode *&head, int roll, string name){
			SNode *ptr = head;
			string s1, s2, res;
			int i, date1, month1;
			while (ptr != NULL)
			{
				if (roll == ptr->rollNo)
				{
					if(ptr->fine == 0){
						if(ptr->book1 == name){	
							
								for(i=0;ptr->date1[i]!=' ';i++)
									s1[i] = ptr->date1[i]; 
								for(int j=0;ptr->date1[i]!='\0';i++,j++)
									s2[j] = ptr->date1[i]; 
								date1 = atoi(s1.c_str());
								month1 = atoi(s2.c_str());
								date1 += 10;
								month1 += (date1/30);
								date1 = date1%30;
								string s3 = to_string(date1);
								string s4 = to_string(month1);
								res = s3+" "+s4;
								ptr->date1 = res;
								cout<<"\n\n\t\t\t\t\t\t\tBook Re-issued successfully\n";
							}
							else if(ptr->book2 == name){		
								for(i=0;ptr->date2[i]!=' ';i++)
									s1[i] = ptr->date2[i]; 
								for(int j=0;ptr->date2[i]!='\0';i++,j++)
									s2[j] = ptr->date2[i]; 
								date1 = atoi(s1.c_str());
								month1 = atoi(s2.c_str());
								date1 += 10;
								month1 += (date1/30);
								date1 = date1%30;
								string s3 = to_string(date1);
								string s4 = to_string(month1);
								string s = " ";
								s4 = s3+s+s4;
								ptr->date2 = s4;
								cout<<"\n\n\t\t\t\t\t\t\tBook Re-issued successfully\n";
							}
							else{
								cout<<"\n\n\t\t\t\t\t\t\tYou have not issued this book!\n";
							}
						}	
					}
					else{
						cout<<"\n\n\t\t\t\t\t\t\tSubmit your fine to re-issue book\n";
					}
				ptr = ptr->next;
			}
			convertToFile(head);
		}
		void convertToFile(SNode *&head){
			SNode *ptr = head;
			ofstream file;
			file.open("Students.csv");
			if(!file.is_open()){
				cout<<"\n\n\t\t\t\t\t\t\tCannot open your record!\n";
				return;
			}
			file.close();
			fstream file2;
			file2.open("Students.csv",ios::app);
			while (ptr != NULL)
			{
				file2<<ptr->rollNo<<","<<ptr->name<<","<<ptr->dep<<","<<ptr->issue<<","<<ptr->book1<<","
				<<ptr->book2<<","<<ptr->date1<<","<<ptr->date2<<","<<ptr->fine<<'\n';
				ptr = ptr->next;
			}
			file2.close();
		}
};
#endif