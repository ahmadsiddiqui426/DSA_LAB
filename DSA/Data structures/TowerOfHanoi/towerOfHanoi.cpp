#include <iostream>
using namespace std;

void towerOfHanoi(int n , char S , char A , char D)
{
	if(n == 0)	return;
	towerOfHanoi(n-1 , S, D, A);
	cout<<"Move disk "<<n<<" from "<<S<<" to "<<D<<'\n';
	towerOfHanoi(n-1, A, S, D);
}
int towerOfHanoi(int n , int S , int A , int D)
{
	int count =1;
	if(n == 0) return 0;
	
	count+=towerOfHanoi(n-1 , S, D, A);
	//cout<<"Move disk "<<n<<" from "<<S<<" to "<<D<<'\n';
	//count++; 
	count+=towerOfHanoi(n-1, A, S, D);
	return count;
}
void glassHour(int n, int b){
	if(n == -1)	return;
	else{
		for(int i=0; i<b; i++)
			cout<<" ";
		for(int j=0; j<n; j++)
			cout<<"*";
		for(int k=0; k<b; k++)
			cout<<" ";
		cout<<endl;
		glassHour(n-2, b+1);
		for(int i=0; i<b; i++)
			cout<<" ";
		for(int j=0; j<n; j++)
			cout<<"*";
		for(int k=0; k<b; k++)
			cout<<" ";
		cout<<endl;
	}
}
void replace(string s, char to, char from){
	if(s[0] == '\0')	return;
	if(s[0] == from)	s[0] = to;
	replace(*s+1, to, from);
}
int main(){
	towerOfHanoi(3, 'A', 'B' ,'C');
	cout<<"\nNo. of steps: ";
	cout<<towerOfHanoi(3, 1,2,3)<<endl;
	glassHour(5, 5);
	string s = replace("Maedah", e, a);
	cout<<s;
	return 0;
}