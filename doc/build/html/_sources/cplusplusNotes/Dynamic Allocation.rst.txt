.. _dynamic-allcation:

============================
Dynamic Allocation 
============================

Guess the output:


.. code-block:: c
	:linenos:

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

When you are creating an variable/object in for loop, because they are local, they are created in stack. When one loop is done, it will be removed from stack. If you are using "new" key word, you are creating the varible in heap, which will be removed at the end of the program unless you explicitly deallocate it, which is what you should do. 
Here is the detail of `dynamic memory allocation <https://www.geeksforgeeks.org/new-and-delete-operators-in-cpp-for-dynamic-memory/>`_ .

So, as you know, the result of the code above is 

.. code-block:: c
	:linenos:

	The address of the integer is 00DEFCF0
	The address of the integer is 00DEFCF0
	-------------------------------------
	The address of the integer is 012CF5F8
	The address of the integer is 012CF658