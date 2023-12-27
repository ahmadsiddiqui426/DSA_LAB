#include<iostream>
#include<cstring>

using namespace std;

void replace(char* s, char from, char to);
void replace(char* s, char from, char to, int i);

int main()
{
	char *s = new char[50];
	strcpy(s,"Hola Mejor Amigo");
	replace(s, 'o', 'a',0);
	cout << "After Replacing:  " << s << '\n';
	delete []s;
	return 0;
}

//void replace(char* str, char from, char to){
//	replace(str, from, to, 0);
//}

void replace(char* str, char from, char to, int i){
	if(str[i]=='\0')
		return;
	
	if(str[i]==from)
		str[i]=to;

	replace(str, from, to, i+1);
}