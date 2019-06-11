#include "Krawedzie.h"
#include "Macierz.h"
#include "Lista.h"
#include <iostream>
#include"Dijkstry.h"
#include <fstream>
#include <chrono>

constexpr unsigned ILOSC_TEST = 100;

constexpr unsigned GRAF_KRAWEDZIE[] = { 10, 50, 100, 500, 1000 };
constexpr unsigned GRAF_KRAWEDZIE_ROZMIAR = sizeof(GRAF_KRAWEDZIE) / sizeof(unsigned);

constexpr double PROCENT_WYPELNIENIA[] = { 0.25, 0.5, 0.75, 1.0 };
constexpr unsigned GRAPH_PERCENT_SIZE = sizeof(PROCENT_WYPELNIENIA) / sizeof(double);

using namespace std; 

int main()
{
	fstream fResults[2] = { fstream("Macierz.txt", ios::out), fstream("List.txt", ios::out) };
	uint64_t time[2];

	for (unsigned I = 0; I < GRAF_KRAWEDZIE_ROZMIAR; ++I)
	{
		cout << "size: " << GRAF_KRAWEDZIE[I] << endl;

		for (unsigned k = 0; k < GRAPH_PERCENT_SIZE; ++k)
		{
			cout << "\tpercent: " << PROCENT_WYPELNIENIA[k] << endl;

			memset(time, 0, sizeof(time));

			for (unsigned j = 0; j < ILOSC_TEST; ++j)
			{
				Krawedzie* graf[2] = {new Macierz(GRAF_KRAWEDZIE[I]), new Lista(GRAF_KRAWEDZIE[I]) };

				for (unsigned r = 0; r < 2; ++r)
				{
					graf[r]->losuj_k(PROCENT_WYPELNIENIA[k]);
					
					auto begin = std::chrono::high_resolution_clock::now();
					delete dijkstra(graf[r],0);
					auto end = std::chrono::high_resolution_clock::now();

					time[r] += std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();

					delete graf[r];
				}
				
			}

			for (unsigned j = 0; j < 2; ++j)
			{
				time[j] /= ILOSC_TEST;
				fResults[j] << GRAF_KRAWEDZIE[I] << "\t" << PROCENT_WYPELNIENIA[k] << "\t" << time[j] << endl;
			}
		}
	}

	fResults[0].close();
	fResults[1].close();


}