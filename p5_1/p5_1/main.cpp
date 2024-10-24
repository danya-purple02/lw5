#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

void main()
{
	srand(time(NULL));

	int vertex_amount = 1, graph_size = 0, vertex_number = 0, tmp_flag = 0, dom_vertex = 0, dom_vertex_degree = 0;
	cout << "input graph size: ";
	cin >> vertex_amount;
	cout << endl;

	int* vertexes_degrees = new int[vertex_amount];
	int** G = new int* [vertex_amount];
	for (int z = 0; z < vertex_amount; z++)
	{
		G[z] = new int[vertex_amount];
		vertexes_degrees[z] = 0;
	}

	cout << "    ";
	for (int i = 1; i <= vertex_amount; i++) 
	{
		cout << i << " ";
	}
	cout << endl << endl;

	for (int i = 0; i < vertex_amount; i++)
	{
		cout << i+1 << "   ";
		for (int j = 0; j < vertex_amount; j++)
		{
			if (j < i) 
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

	for (int i = 0; i < vertex_amount; i++)
	{
		for (int j = i; j < vertex_amount; j++)
		{
			if (G[i][j] == 1)
			{
				if (i == j) 
				{
					graph_size++;
				}
				graph_size++;
			}
		}
	}
	cout << endl << graph_size << endl;

	for (int i = 0; i < vertex_amount; i++)
	{
		for (int j = 0; j < vertex_amount; j++)
		{
			vertex_number = i + 1;
			if ((G[i][j] == 1) && (i != j))
			{
				tmp_flag++;
			}
		}
		if (tmp_flag == 0) 
		{
			cout << vertex_number << " is isolated vertex" << endl;
		}
		else if (tmp_flag == 1) 
		{
			cout << vertex_number << " is terminal vertex" << endl;
		}
		vertexes_degrees[i] = tmp_flag;
		tmp_flag = 0;
	}

	for (int i = 0; i < vertex_amount; i++) 
	{
		if (vertexes_degrees[i] == (vertex_amount - 1)) 
		{
			dom_vertex_degree = vertexes_degrees[i];
			dom_vertex = i + 1;
		}
	}
	if (dom_vertex != 0) 
	{
		cout << "dominant vertex is " << dom_vertex << " and it's degree = " << dom_vertex_degree << endl;
	}
}