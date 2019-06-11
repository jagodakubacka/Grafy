#include "Krawedzie.h"
#include <iostream>
#include <random>

void Krawedzie::losuj_k(double procent)
{
	unsigned max_krawedzi = ilosc_wierzch * (ilosc_wierzch - 1) / 2;
	unsigned indeks_wierzcholka[2] = { 1 };

	for (unsigned q = 0; q < max_krawedzi * procent; ++q)
	{
		dodaj_k(indeks_wierzcholka[1], indeks_wierzcholka[0], 5 + rand() % 100);

		if (indeks_wierzcholka[0] - 1 == indeks_wierzcholka[1])
		{
			++indeks_wierzcholka[0];
			indeks_wierzcholka[1] = 0;
		}
		else
		{
			++indeks_wierzcholka[1];
		}

	}
}

int Krawedzie::ilosc_wierz()
{
	return ilosc_wierzch;
}