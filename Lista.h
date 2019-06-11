#pragma once
#include "Krawedzie.h"
struct Element_listy
{
	int waga;
	int do_wierz; 

	Element_listy* nastepny; 
};

class Lista :
	public Krawedzie
{
public: 
	Lista(int wierzcholki); 
	~Lista(); 

	virtual void dodaj_k(int od_wierz, int do_wierz, int waga);
	virtual int pobierz_wage(int od_wierz, int do_wierz);
	virtual void wyswietl();
private: 
	Element_listy** lista; 
};