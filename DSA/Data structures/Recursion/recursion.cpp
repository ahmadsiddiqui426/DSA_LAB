#include <iostream>
using namespace std;
int sum(int n)
{
	if(n == 1)	return 1;
	return n+sum(n-1);
}
void reverse(char* c)
{
	if(*c == '\0')	return ;
	else{
		reverse(c+1);
		cout<<*c;
	}             
} 
void decimal(int num)
{
	if(num == 1){
		cout<<"1";
		return;
	}
	decimal(num/2);
	cout<<num%2;
	
}
void anyBase(int num , int base)
{
	if(num<base){
		cout<<num;
		return;
	}
	anyBase(num/base,base);
	cout<<num%base;
}
void rightTriangle(int n)
{
	if(n==1){
		cout<<"*\n";
		return;
	}
	rightTriangle(n-1);
	for(int i = 0; i<n; i++)
		cout<<"*";
	cout<<endl;
}
void triangle(int n)
{

	if(n == 1){
		cout<<"*\n";
		return;
	}
	
	triangle(n-1);
	for(int i =0;i<n-1; i++)
		cout<<" ";
	for(int i = 0; i<2*n-1 ;i++)
		cout<<"*";
	cout<<endl;
	
}

void hourGlass(int n , int b)
{
	if (n == 0) {
    cout<<endl;
  } else if (b == 0) {
    cout<<"*";
    hourGlass(n-1, 0);
  } else {
    cout<<" ";
    hourGlass(n, b-1);
  }
}
void diamond(int star, int n,int b){
	if(n==-1||star==-1)	return;
	diamond(star,n-2,b+1);
	 diamond(star,star,b+1);
	for(int i=0;i<b;i++)
		cout<<' ';
	for(int i=0;i<n;i++)
		cout<<"*";
	cout<<endl;
	
	star=star-2; cout<<star;
}
int main(){
	cout<<sum(5)<<'\n';
	reverse("maedah");
	cout<<endl;
	decimal(15);
	cout<<endl;
	anyBase(15,9);
	cout<<endl;
	//hourGlass(3,0);
	diamond(5,5,0);
	return 0;
}