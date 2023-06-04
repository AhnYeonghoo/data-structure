#include <iostream>
using namespace std;

int maintte()
{
	unsigned short a, b;
	int sum = 0;
	cin >> a >> b;
	for (int i = a + 1; i < b; i++)
	{
		sum += i;
	}
	cout << sum << endl;
	return 0;
}