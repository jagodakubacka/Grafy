#include <iostream>
#include "Dijkstry.h"

int* dijkstra(Krawedzie* krawedzie,  unsigned wierzch_start)
{
	int* odleglosci = new int[krawedzie->ilosc_wierz()];
	bool* czy_odw = new bool[krawedzie->ilosc_wierz()]{ false };
	unsigned min_indeks_odleglosc;

	for (unsigned i = 0; i < krawedzie->ilosc_wierz(); ++i)
	{
		odleglosci[i] = INT_MAX;
	}
	odleglosci[wierzch_start] = 0;

	for (unsigned i = 0; i < krawedzie->ilosc_wierz() - 1; ++i)
	{
		int min_odleglosc = INT_MAX;
		for (unsigned j = 0; j < krawedzie->ilosc_wierz(); ++j)
		{
			if (!czy_odw[j] && odleglosci[j] <= min_odleglosc)
			{
				min_odleglosc = odleglosci[j];
				min_indeks_odleglosc = j;
			}
		}
		czy_odw[min_indeks_odleglosc] = true;

		for (unsigned j = 0; j < krawedzie->ilosc_wierz(); ++j)
		{
			int temp = krawedzie->pobierz_wage(min_indeks_odleglosc, j);

			if (!czy_odw[j] &&
				temp != INT_MAX &&
				odleglosci[min_indeks_odleglosc] != INT_MAX &&
				odleglosci[min_indeks_odleglosc] + temp < odleglosci[j])
			{
				odleglosci[j] = odleglosci[min_indeks_odleglosc] + temp;
			}
		}
	}

	return odleglosci;
}