
// DECLARATION

#ifndef ORARIO_H
#define ORARIO_H
#include <iostream>


/*using std::ostream; 
using std::cout;
using std::endl;*/
using namespace std; 


class orario
{
	public:

	// Costruttori
	//
		orario(); 				// Default
		orario(int);			// Ore
		orario(int,int);		// Ore-Min
		orario(int,int,int);	// Ore-Min-Sec

		// explicit orario(int); // errore, non usiamo quello come convertitore di tipo implicito.

	// Metodi
	//
		int Ore() const;
		int Minuti() const;
		int	Secondi() const;
		orario AumentaUnOra();
		void PrintSec() const;
		static orario OraDiPranzo(); // Metodo statico
		static int UnOra; // Campo dati statico


	// Overloading operatori
	//
		orario operator+(orario); 
		bool operator==(orario) const;

	private: 
	
	// Campi dati
	//
		int sec;
};

ostream& operator<<(ostream&, const orario&); 

#endif
