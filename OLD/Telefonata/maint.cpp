

#include "../Orario/orario.cpp"
#include "telefonata.cpp"


// ==== main()

int main()
{
	cout << "+____________[exercise: telefonata]____________+" << endl;
	cout << "|" << endl;

	orario ora(15,20,25);
	orario ora2(15,22,30);
	int prova = 334553242;
	telefonata tel(ora, ora2, prova);
	orario xy;
	xy = tel.Fine();

	//cout << tel.Fine();

	cout << "| Sono le ore: " << ora << endl;

	cout << "| DEBUG: " << tel << endl; 

	cout << "|" << endl;
	cout << "|___________________[end]__________________|" << endl;

}