

#include "orario.cpp"

//#define SECPERMIN 60 // Macro



// ==== main()

int main()
{
	cout << "+____________[exercise: orario]____________+" << endl;
	cout << "|" << endl;


	/* =============== Costruttori / Puntatori ================= */
	//orario* ptr = new orario(9,37);
	//orario oramia(0,0,24);

	//cout << ptr->Minuti() << endl;
	//cout << oramia.Secondi() << endl;

	/* mezzanotte.sec = 0; // Non funziona in quanto sec è campo privato */

	//orario x,y;
	//x = 15; 	// Convertitore di tipo da int a orario
	//y = 2+3; // vale come assegnazione del costruttore a 1 parametro


	/* =============== Print di Metodi ================= */
	//cout << y.Ore() << endl;
	//oramia = oramia.AumentaUnOra();
	//cout << oramia.Ore() << endl;
	//oramia.PrintSec();

	/* =============== Static prompt ================= */
	//cout << "Si pranza alle: " << orario::OraDiPranzo().Ore() << endl; // Metodo static
	//cout << orario::UnOra << endl; // Campo dati static

	/* =============== Overloading operatori ================= */

	orario ora(16,51,52);
	//orario pomeriggio(16,30,51);
	//ora = ora + pomeriggio; 
	//cout << "| Nuova ora = " << ora.Ore() << ":" << ora.Minuti() << endl; 
	cout << "| Ora sono le " << ora << endl; // overloading operatore << di ostream


	cout << "|" << endl;
	cout << "|___________________[end]__________________|" << endl;

}