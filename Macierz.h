#pragma once

#include "Krawedzie.h"

class Macierz :
	public Krawedzie

{
public:
	Macierz(int wierzcholki);
	~Macierz();

	virtual void dodaj_k(int od_wierz, int do_wierz, int waga);
	virtual int pobierz_wage(int od_wierz, int do_wierz);
	virtual void wyswietl();
private: 
	int **macierz; 
};
