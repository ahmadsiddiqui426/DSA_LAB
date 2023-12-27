#include<iostream>
#include<cstring>

using namespace std;

void printSequence(int n);
void printSequence(int num, int n, int s);
int findNumber(int n);
int findNumber(int num, int n, int s, int count);

int main()
{
	int n;
	printSequence(23);

	cout << "\n\nEnter nth number to find in the sequence: ";
	cin >> n;

	cout << n << "th number is: " << findNumber(n) << '\n';

	return 0;
}

void printSequence(int n){
	printSequence(0, n, 0);
}

void printSequence(int num, int n, int s){
	if(num>n )
		return;
	cout << num << ' ';
	s++;
	printSequence(num+s, n, s);
}

int findNumber(int n){
	return findNumber(0, n, 0, 1);
}

int findNumber(int num, int n, int s, int count){
	if( count == n )
		return num;
	
	count++;
	s++;
	return findNumber(num+s, n, s, count);
}