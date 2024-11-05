#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

void cout_matrix(int edges, int vertexes, int** G);

void main()
{
	srand(time(NULL));
	int vertex_amount = 1, graph_size = 0, tmp = 0;

	// t1 p1

	cout << "input graph size: ";
	cin >> vertex_amount;

	int** G = new int* [vertex_amount];
	for (int z = 0; z < vertex_amount; z++)
	{
		G[z] = new int[vertex_amount];
	}

	for (int i = 0; i < vertex_amount; i++)
	{
		for (int j = 0; j < vertex_amount; j++)
		{
			if (j < i) 
			{
				G[i][j] = G[j][i];
			}
			else if (j > i) 
			{
				G[i][j] = rand() % 2;
			}
			else 
			{
				G[i][j] = 0;
			}
		}
	}
	
	cout_matrix(vertex_amount, vertex_amount, G);

	// t1 p2

	for (int i = 0; i < vertex_amount; i++)
	{
		for (int j = i + 1; j < vertex_amount; j++)
		{
			if (G[i][j] == 1)
			{
				graph_size++;
			}
		}
	}
	cout << endl << "graph size = " << graph_size << endl;
	
	// t1 p3

	for (int i = 0; i < vertex_amount; i++)
	{
		for (int j = 0; j < vertex_amount; j++)
		{
			if ((G[i][j] == 1) && (i != j))
			{
				tmp++;
			}
		}
		if (tmp == vertex_amount - 1)
		{
			cout << i + 1 << " is dominant vertex" << endl;
		}
		else if (tmp == 0)
		{
			cout << i + 1 << " vertex is isolated vertex" << endl;
		}
		else if (tmp == 1)
		{
			cout << i + 1 << " vertex is terminal vertex" << endl;
		}
		tmp = 0;
	}

	// t2 p1
	
	int edges = 0;
	for (int i = 0; i < vertex_amount; i++) 
	{
		for (int j = i + 1; j < vertex_amount; j++)
		{
			if (G[i][j] == 1) 
			{
				edges++;
			}
		}
	}

	int** G_in = new int* [vertex_amount];
	for (int i = 0; i < vertex_amount; i++) 
	{
		G_in[i] = new int[edges];
	}

	for (int i = 0; i < vertex_amount; i++) 
	{
		for (int j = 0; j < edges; j++) 
		{
			G_in[i][j] = 0;
		}
	}

	int m = 0;

	for (int i = 0; i < vertex_amount; i++) 
	{
		for (int j = i + 1; j < vertex_amount; j++) 
		{
			if (G[i][j] == 1)
			{
				G_in[i][m] = 1;
				G_in[j][m] = 1;
				m++;
			}
		}
	}

	cout_matrix(edges, vertex_amount, G_in);
	
	// t2 p2

	tmp = 0;
	graph_size = 0;
	for (int j = 0; j < edges; j++)
	{
		for (int i = 0; i < vertex_amount; i++)
		{
			if (G_in[i][j] == 1)
			{
				tmp++;
			}
		}
		if (tmp == 1) 
		{
			graph_size = graph_size + 2;
		}
		else if (tmp == 2) 
		{
			graph_size++;
		}
		tmp = 0;
	}

	cout << endl << "graph size = " << graph_size << endl;

	// t2 p3

	for (int i = 0; i < vertex_amount; i++) 
	{
		for (int j = 0; j < edges; j++) 
		{
			if (G_in[i][j])
			{
				tmp++;
			}
		}
		if (tmp == vertex_amount - 1)
		{
			cout << i + 1 << " is dominant vertex" << endl;
		}
		else if (tmp == 0)
		{
			cout << i + 1 << " vertex is isolated vertex" << endl;
		}
		else if (tmp == 1)
		{
			cout << i + 1 << " vertex is terminal vertex" << endl;
		}
		tmp = 0;
	}
	


	delete[]G;
	delete[]G_in;
	return;
}

void cout_matrix(int edges, int vertexes, int** G)
{
	cout << endl << "    ";
	for (int i = 1; i <= edges; i++)
	{
		cout << i << " ";
	}
	cout << endl << endl;
	for (int i = 0; i < vertexes; i++)
	{
		cout << i + 1 << "   ";
		for (int j = 0; j < edges; j++)
		{
			cout << G[i][j] << " ";
		}
		cout << endl;
	}
}