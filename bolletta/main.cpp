#include "../orario/orario.h"
#include "../telefonata/telefonata.h"
#include "bolletta.h"

int main()
{
    bolletta b1;
    telefonata t1(orario(9,23,12), orario(10,4,53), "212121");
    telefonata t2(orario(11,15,4), orario(11,22,1), "313131");
    b1.aggiungiTel(t1);b1.aggiungiTel(t2);
    cout << b1;
    bolletta b2;
    b2 = b1;
    b2.togliTel(t1);
    cout << b1 << b2;
}
