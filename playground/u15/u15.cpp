#include <stdio.h>

const int MAX_POINTS = 305;

inline int min(int a, int b)
{
	return (a < b ? a : b);
}

inline int max(int a, int b)
{
	return (a > b ? a : b);
}

inline int det(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return (x1 * y2 + x2 * y3 + x3 * y1 - (y2 * x3 + y3 * x1 + y1 * x2));
}

inline int sgn(int a)
{
	return a >= 0;
}

inline bool concurrent(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	if (((det(x1, y1, x2, y2, x3, y3) == 0) && (min(x1, x2) <= x3 && min(y1, y2) <= y3 && max(x1, x2) >= x3 && max(y1, y2) >= y3) ||
		(det(x1, y1, x2, y2, x4, y4) == 0) && (min(x1, x2) <= x4 && min(y1, y2) <= y4 && max(x1, x2) >= x4 && max(y1, y2) >= y4) ||
		(det(x3, y3, x4, y4, x1, y1) == 0) && (min(x3, x4) <= x1 && min(y3, y4) <= y1 && max(x3, x3) >= x1 && max(y3, y4) >= y1) ||
		(det(x3, y3, x4, y4, x2, y2) == 0) && (min(x3, x4) <= x2 && min(y3, y4) <= y2 && max(x3, x3) >= x2 && max(y3, y4) >= y2)) ||
		(sgn(det(x1, y1, x2, y2, x3, y3) != sgn(det(x1, y1, x2, y2, x4, y4)) && 
		 sgn(det(x3, y3, x4, y4, x1, y1) != sgn(det(x3, y3, x4, y4, x2, y2))))))
		return true;
	return false;
}

int main()
{
	int x[MAX_POINTS], y[MAX_POINTS], z, n;
	
	scanf("%d", &z);
	while (z--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d%d", &x[i], &y[i]);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (i != j)
				{
					
				}
	}
	return 0;
}
