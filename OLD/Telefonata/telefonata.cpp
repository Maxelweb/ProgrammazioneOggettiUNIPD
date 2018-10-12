
// INTERFACE / DEFINITION

//#include "../Orario/orario.cpp"
#include "telefonata.h"

	// Potrei usare "using namespace telefonata;" 

// ==== Costruttori

telefonata::telefonata(const orario& i, const orario& f, int n) : inizio(i), fine(f), numero(n) {}

// Se mettiamo const int numero, non compila!
// telefonata::telefonata () { numero = 0;} 
// gli altri campi vengono inizializzati tramite il costruttore di default
// usiamo
telefonata::telefonata () : numero(0) {}

// ==== Metodi

orario telefonata::Inizio() const { return inizio; }

orario telefonata::Fine() const { return fine; }

int telefonata::Numero() const { return numero; }


// ==== Overloading operatori


bool telefonata::operator==(const telefonata& t) const {
	return inizio == t.inizio && fine == t.fine && numero == t.numero;
}


ostream& operator<<(ostream& out, const telefonata& tel)
{
	// !# Non funziona senza variabili ausiliarie.. Perchè? ok, mancava const -_-
	//orario inizio = tel.Inizio();
	//orario fine = tel.Fine();
	return out << "[INIZIO] " << tel.Inizio() << " - [FINE] " << tel.Fine() << " [NUMERO] " << tel.Numero();
	//return out << tel.Inizio(); 

}


// ==== Campi Dati



