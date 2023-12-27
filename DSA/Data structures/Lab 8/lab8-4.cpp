#include<iostream>
#include<cstring>

using namespace std;

void printToAnyBase(int n, int base);

int main()
{
	int n, b;

	cout << "Integer: ";
	cin >> n;
	cout << "base (0-9): ";
	cin >> b;

	cout << n << " in base " << b << " is ";
	printToAnyBase(n, b);
	cout << '\n';

	return 0;
}

void printToAnyBase(int n, int base)
{
	int rem = n % base;
	if( n / base == 0 )
	{
		cout << rem;
		return;
	}
	printToAnyBase(n/base, base);
	cout << rem;
}