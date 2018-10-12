
// DECLARATION

#ifndef TELEFONATA_H
#define TELEFONATA_H
#include <iostream>
#include <string>
#include "../Orario/orario.h"


class telefonata
{

	private: 
		orario inizio, fine; // relazione has-a
		const int numero; // campo dati costante!

		/*
		 *	Scegliere il numero di telefono con un INT è sbagliata dal momento che
		 *	ci vorrebbe una classe apposita e quindi un tipo apposito perchè non si possono salvare numeri
		 *  che iniziano con 0.
		 */

	public: 
		telefonata(const orario&,const orario&,int); // passato per valore (per ora)
		telefonata();
		orario Inizio() const;
		orario Fine() const; 
		int Numero() const; 
		bool operator==(const telefonata&) const;
		

};

ostream& operator<<(ostream&, const telefonata&);

#endif
