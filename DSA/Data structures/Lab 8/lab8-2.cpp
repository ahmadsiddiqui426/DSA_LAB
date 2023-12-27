#include<iostream>

int count_characters(char *str,char c);

using namespace std;

int main()
{
	int characters=count_characters("",'o');
	cout << "No of times are: "<< characters;
	return 0;
}

int count_characters(char *str, char c){
	int count=0;
	if(str[0]=='\0')
		return count;
	else{
		if(str[0]==c)
			count++;
		return count+count_characters(str+1,c);
	}
}