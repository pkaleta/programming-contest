#include <cstdio>
#include <cstdlib>
#include <time.h>

#define REP(a,b) for (int a = 0; a<(b); ++a)
#define FOR(a,b,c) for (int a = (b); a<=(c); ++a)

#define SIZE 10

int plansza[SIZE][SIZE];
int moj_numer;

////////// POCZATKOWY STAN PLANSZY ////////

void przygotuj_plansze()
{
	plansza[0][3] = plansza[3][0] = plansza[9][3] = plansza[6][0] = 1;
	plansza[0][6] = plansza[3][9] = plansza[9][6] = plansza[6][9] = 2;
}

///////////// MODYFIKOWANIE PLANSZY STOSOWNIE DO RUCHOW //////////

void przesun(int x0, int y0, int x1, int y1)
{
	plansza[x1][y1] = plansza[x0][y0];
	plansza[x0][y0] = 0;
}

void zamuruj(int xs, int ys)
{
	plansza[xs][ys] = 3;
}

////////////// MOJE RUCHY ///////////////////

int ruchy[SIZE*SIZE][2], ile_ruchow;

void znajdz_wolne(int x0, int y0)
{
	int dx[8] = {1, 1, -1, -1, 1, -1, 0, 0};
	int dy[8] = {1, -1, 1, -1, 0, 0, 1, -1};
	REP(d, 8)
	{
		int x = x0+dx[d], y = y0+dy[d];
		while (x>=0 && y>=0 && x<SIZE && y<SIZE && !plansza[x][y])
		{
			ruchy[ile_ruchow][0] = x;
			ruchy[ile_ruchow][1] = y;
			++ile_ruchow;
			x += dx[d]; 
			y += dy[d];
		}
	}
}

void zrob_ruch()
{
	ile_ruchow = 0;
	REP(x0, SIZE)
		REP(y0, SIZE)
			if (plansza[x0][y0]==moj_numer)
			{
				znajdz_wolne(x0, y0);
				if (ile_ruchow)
				{
					int k = rand()%ile_ruchow;
					int x1 = ruchy[k][0], y1 = ruchy[k][1];
					przesun(x0, y0, x1, y1);
					ile_ruchow = 0;
					znajdz_wolne(x1, y1);
					k = rand()%ile_ruchow;
					int xs = ruchy[k][0], ys = ruchy[k][1];
					zamuruj(xs, ys);
					++x0; ++y0; ++x1; ++y1; ++xs; ++ys;
					printf("%d %d %d %d %d %d\n", x0, y0, x1, y1, xs, ys);
					fflush(stdout);
					return;
				}
			}
}

//////////////// ODCZYTAJ RUCHY PRZECIWNIKA ////////////////

void zrobiono_ruch()
{
	int x0, y0, x1, y1, xs, ys;
	scanf("%d%d%d%d%d%d", &x0, &y0, &x1, &y1, &xs, &ys);
	--x0; --y0; --x1; --y1; --xs; --ys;
	przesun(x0, y0, x1, y1);
	zamuruj(xs, ys);
}

//////////////// MAIN /////////////////

int main()
{
	srand(time(NULL));
	scanf("%d", &moj_numer);
	int czy_ja = moj_numer==1;
	przygotuj_plansze();
	for(;;)
	{
		if (czy_ja)
		{
			int czas;
			scanf("%d", &czas);
			zrob_ruch();
		}
		else
			zrobiono_ruch();
		czy_ja = !czy_ja;
	}
}
