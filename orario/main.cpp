#include<iostream>
#include<orario.h>

using namespace std;

int main(int argc, char *argv[])
{
    orario mezzanotte(12,25);

    cout << "-------- ORA ESATTA --------" << endl;
    cout << "Ore: " << mezzanotte.Ore() << endl;
    cout << "Minuti: " << mezzanotte.Minuti() << endl;


    orario* ptr = new orario(7, 15);

    cout << "-------- POINTERS --------" << endl;
    cout << "Sono le " << ptr->Ore() << ":" << ptr->Minuti() << endl;


}
