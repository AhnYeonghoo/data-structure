#include <iostream>
using namespace std;

int main()
{
	int n;
	int a, b;
	cin >> n;
	int *result = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		result[i] = a + b;
	}

	for (int i = 0; i < n; i++)
	{
		cout << result[i] << endl;
	}
	delete[] result;
	return 0;
}