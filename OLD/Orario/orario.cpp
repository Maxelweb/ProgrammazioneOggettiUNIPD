
// INTERFACE / DEFINITION

#include "orario.h"


// ==== Costruttori

orario::orario(){
	sec = 0;
}

orario::orario(int o){
	if(o<0 || o>23) sec = 0; // Controllo di sanità
	else sec = o*3600;
}

orario::orario(int o, int m){
	if(o<0 || o>23 || m < 0 || m > 59) sec = 0; // "
	else sec = o*3600 + m*60;
}

orario::orario(int o, int m, int s){
	if(o<0 || o>23 || m < 0 || m > 59 || s < 0 || s > 59) sec = 0; // ""
	else sec = o*3600 + m*60 + s;
}


// ==== Metodi

int orario::Ore() const  { return sec / 3600; }
int orario::Minuti() const { return (sec/60) % 60;}
int orario::Secondi() const { return (sec%60);}

orario orario::AumentaUnOra() {
	orario aux;
	aux.sec = (sec + 3600) %  86400; 
	return aux; 
}

void orario::PrintSec() const{
	cout << "Secondi totali: " << sec << endl;
}

orario orario::OraDiPranzo() {
	return orario(13,15,00); 
}


// ==== Overloading operatori

orario orario::operator+(orario x){
	orario aux;
	aux.sec = (sec + x.sec) % 86400;
	return aux;
}

bool orario::operator==(orario x) const {
	return (sec == x.sec);
}

ostream& operator<<(ostream& os, const orario &o) {
	return os << o.Ore() << ':' << o.Minuti() << ':' << o.Secondi();
} // Altrimenti mettevo using std::ostream sul .h; 




// ==== Campi Dati

int orario::UnOra = 3600;

