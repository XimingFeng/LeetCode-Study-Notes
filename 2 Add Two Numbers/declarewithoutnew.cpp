#include <iostream>
using namespace std;

void main()
{
	int* a;
	for(int i = 0; i < 2; i ++)
	{
	    int b = 0;
	    a = &b;
	    cout << "The address of the integer is " << a << endl;
	}

	cout << "-------------------------------------" << endl;
	int* c;
	for(int i = 0; i < 2; i ++)
	{
	    c = new int(0);
	    cout << "The address of the integer is " << c << endl;
	}
}




/*
Output


*/