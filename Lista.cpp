#include "Lista.h"
#include <iostream>



Lista::Lista(int wierzcholki)
{
	ilosc_wierzch = wierzcholki; 
	lista = new Element_listy*[wierzcholki] {nullptr};
}

Lista::~Lista()
{
	Element_listy* tymcz;

	for (unsigned i = 0; i < ilosc_wierzch; ++i)
	{
		while (lista[i] != nullptr)
		{
			tymcz = lista[i]->nastepny;
			delete lista[i];

			lista[i] = tymcz;
		}
	}
	delete lista;
}

void Lista::dodaj_k(int od_wierz, int do_wierz, int waga)
{
	Element_listy* tymcz =  lista[od_wierz];
	Element_listy* krawedz = new Element_listy{ waga, do_wierz, nullptr };

	if ( lista[od_wierz] == nullptr)
	{
		 lista[od_wierz] = krawedz;
	}
	else
	{
		while (tymcz->nastepny != nullptr)
		{
			tymcz = tymcz->nastepny;
		}

		tymcz->nastepny = krawedz;
	}
}

int Lista::pobierz_wage(int od_wierz, int do_wierz)
{
	Element_listy* nastepny = lista[od_wierz];

	for (unsigned q = 0; q <= ilosc_wierzch; ++q)
	{
		if (nastepny == nullptr)
		{
			return INT_MAX;
		}

		if (nastepny->do_wierz == do_wierz)
		{
			return nastepny->waga;
		}

		nastepny = nastepny->nastepny;
	}
}

void Lista::wyswietl()
{
	for (unsigned q = 0; q < ilosc_wierzch; ++q)
	{
		Element_listy* nastepny = lista[q];

		while (nastepny != nullptr)
		{
			std::cout << '(' << nastepny->do_wierz << ',' << nastepny->waga << ')' << "\t";
			nastepny = nastepny->nastepny;
		}

		std::cout << "\n";
	}
}
