#include <iostream>
#include "Macierz.h"

Macierz::Macierz(int wierzcholki)
{
	ilosc_wierzch = wierzcholki; 

	macierz = new int*[wierzcholki];
	for (int i = 0; i < wierzcholki; i++)
	{
		macierz[i] = new int[wierzcholki];
		for (int j = 0; j < wierzcholki; j++)
		{
			macierz[i][j] = INT_MAX; 
		}

	}
}

Macierz::~Macierz()
{
	for (int i = 0; i < ilosc_wierzch; i++)
	{
		delete []  macierz[i];
	}

	delete [] macierz; 
}

void Macierz::dodaj_k(int od_wierz, int do_wierz, int waga)
{
	macierz[od_wierz][do_wierz] = waga; 
}

int Macierz::pobierz_wage(int od_wierz, int do_wierz)
{
	return macierz[od_wierz][do_wierz];
}

void Macierz::wyswietl()
{
	for (int i = 0; i < ilosc_wierzch; i++)
	{
		
		for (int j = 0; j < ilosc_wierzch; j++)
		{
			std::cout << macierz[i][j] << "   ";
		}
		std::cout << std::endl; 

	}
}
