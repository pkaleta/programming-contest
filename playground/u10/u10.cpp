#include <stdio.h>
#include <string.h>

const int MAX_VERTICES = 10;
const int MAX_EDGES = 101;

bool hamiltonian;
int n, d[MAX_VERTICES][MAX_VERTICES], visited[MAX_VERTICES];

void visit(int v, int vNum)
{
	for (int i = 0; i <= n; ++i)
	{
		if (d[v][i] && !visited[i])
		{
			if (i == 0)
			{
				//printf("wchodzimy do 0, vNum = %d, n = %d\n", vNum, n);
				if (vNum == n)
					hamiltonian = true;
			}
			else
			{
				visited[i] = 1;
				//printf("wchodzimy do: %d\n", i);
				visit(i, vNum + 1);
				visited[i] = 0;
			}
		}
	}
}

int main()
{
	int z, m, a, b;

	scanf("%d", &z);
	while (z--)
	{
		hamiltonian = false;
		memset(d, 0, sizeof(d));
		memset(visited, 0, sizeof(visited));
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; ++i)
		{
			scanf("%d%d", &a, &b);
			d[a][b] = 1;
			d[b][a] = 1;
		}
		visit(0, 0);
		if (hamiltonian)
			printf("TAK\n");
		else
			printf("NIE\n");
	}
	return 0;
}
