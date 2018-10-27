#include "../orario/orario.h"
#include "../telefonata/telefonata.h"
#include "bolletta.h"

int main()
{
    /* In questo esempio, c'è un problema di interferenza (pag. 60)
       -----------------  OUTPUT --------------------
        TELEFONATE IN BOLLETTA:
                1) [PHONE CALL] start: 11:15:4 | end: 11:22:1 | number: 313131
                2) [PHONE CALL] start: 9:23:12 | end: 10:4:53 | number: 212121
                - TOTALE: 2

        TELEFONATE IN BOLLETTA:
                1) [PHONE CALL] start: 11:15:4 | end: 11:22:1 | number: 313131
                - TOTALE: 1

        TELEFONATE IN BOLLETTA:
                1) [PHONE CALL] start: 11:15:4 | end: 11:22:1 | number: 313131
                - TOTALE: 1
        ----------------- --------- --------------------
    */
    bolletta b1;
    telefonata t1(orario(9,23,12), orario(10,4,53), "212121");
    telefonata t2(orario(11,15,4), orario(11,22,1), "313131");
    b1.aggiungiTel(t1);b1.aggiungiTel(t2);
    cout << b1;
    bolletta b2;
    b2 = b1;
    b2.togliTel(t1);
    cout << b1 << b2;

    /*
        E' opportuno risolvere impiegando i costruttori di copia profonda all'interno
        così da evitare la copia di default che fa puntare nella stessa
        cella di memoria dell'oggetto "copiato".

        Il costruttore di copia profonda va usato nodo per nodo, campo per campo.
        E' opportuno fare pulizia degli elementi non più in uso cui si eseguono
        assegnazioni (vedi distruggi(nodo*)).
    */
}
