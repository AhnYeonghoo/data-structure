#include <iostream>
using namespace std;

int main2738()
{
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	int a[101][101], b[101][101];
	int result[101][101];
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> a[i][j];
		}
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> b[i][j];
		}
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << a[i][j] + b[i][j] << " ";
		}
		cout << '\n';
	}
	
	return 0;
}