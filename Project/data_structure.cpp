#include <iostream>
#include "CLinkedList.h"

using namespace std;

int main()
{
	CLinkedList<int> list_int;
	
	for (int i = 0; i < 100; i++)
	{
		list_int.push_back(i);
	}
	
	cout << "size: " << list_int.size() << endl;
	return 0;
}