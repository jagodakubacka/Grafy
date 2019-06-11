#pragma once

class Krawedzie
{

public:

	virtual ~Krawedzie() {}; 
	virtual void dodaj_k(int od_wierz, int do_wierz, int waga) = 0; 
	virtual int pobierz_wage(int od_wierz, int do_wierz) = 0; 
	void losuj_k(double procent); 
	int ilosc_wierz(); 
	virtual void wyswietl() = 0; 

protected: 
	int ilosc_wierzch; 


};