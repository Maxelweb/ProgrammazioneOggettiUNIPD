/** ESERCIZIO VETTORE */
/* Definire una classe vettore i cui oggetti
rappresentano array di interi.

vettore deve includere:
    - un costruttore di default,
    - una operazione di concatenazione
      che restituisce un nuovo vettore v1+v2,
    - una operazione di append v1.append(v2),
    - l'overloading dell'uguaglianza,
    - dell'operatore di output
    - e dell'operatore di indicizzazione.
Deve inoltre includere il
    - costruttore di copia profonda,
    - l'assegnazione profonda
    - e la distruzione profonda.
*/

#include <iostream>
#include "vettore.h"

int main() {
  vettore v1, v2(3), v3(5);
  v1 = v2+v3;
  v2.append(v2);
  v3.append(v1);
  v2.append(v3);
  v2.append(v2);
  std::cout << v1 << std::endl;
  std::cout << v2 << std::endl;
  std::cout << v3 << std::endl;
}


/* OUTPUT
    v1 = [3,5] (size: 2)
    v2 = [3,3,5,3,5,3,3,5,3,5] (size: 10)
    v3 = [5,3,5] (size: 3)
*/
