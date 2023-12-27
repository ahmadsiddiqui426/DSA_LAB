#include<iostream>

void printHourGlass(int totalstars,int n, int b);
void printHourGlass2(int n, int b);

using namespace std;

int main()
{
	printHourGlass(5,5,0);
	return 0;
}

void printHourGlass(int n, int b){
	if(n==-1)
		return;
	else{
		for(int i=0;i<b;i++)
			cout << " ";
		for(int j=0;j<n;j++)
			cout << "*";
		for(int k=0;k<b;k++)
			cout << " ";
		cout << "\n";
		printHourGlass(n-2,b+1);
		for(int i=0;i<b;i++)
			cout << " ";
		for(int j=0;j<n;j++)
			cout << "*";
		for(int k=0;k<b;k++)
			cout << " ";
		cout << "\n";
	}
}

void printHourGlass2(int n, int b){
	if(n==-1)
		return;
	else{
		printHourGlass2(n-2,b+1);
		for(int i=0;i<b;i++)
			cout << " ";
		for(int j=0;j<n;j++)
			cout << "*";
		for(int k=0;k<b;k++)
			cout << " ";
		cout << "\n";
	}
}
