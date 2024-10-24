#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

void main() 
{
	srand(time(NULL));

	int vertex_amount = 1;
	cout << "input graph size: ";
	cin >> vertex_amount;
	cout << endl;


	int** G = new int* [vertex_amount];
	for (int z = 0; z< vertex_amount; z++) 
	{
		G[z] = new int[vertex_amount];
	}

	for (int i = 0; i < vertex_amount; i++)
	{
		for (int j = 0; j < vertex_amount; j++)
		{
			if (i == j)
			{
				G[i][j] = 0;
			}
			else if (j < i) 
			{
				G[i][j] = G[j][i];
			}
			else 
			{
				G[i][j] = rand() % 2;
			}
			cout << G[i][j] << " ";
		}
		cout << endl;
	}
}