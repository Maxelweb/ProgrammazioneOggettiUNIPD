#include "raz.h"

//Raz::Raz() : num(0), den(1) {} --> Inutile, definito dopo

Raz::Raz(int x, int y) : num(x), den(y)
{
    if(den == 0) { den=1; num=0; }
}

Raz Raz::inverso() const{
    return Raz(den, num);
}

// Uso questo metodo per ritornare la divisione tra num e den.
// Uso double poichè potrebbe avere la virgola.
Raz::operator double() const {
    return static_cast<double>(num) / static_cast<double>(den);
}

Raz Raz::operator+ (const Raz& x) const{
    return Raz(num*x.den + x.num*den, den*x.den);
}

Raz Raz::operator* (const Raz& x) const{
    return Raz(num*x.num, den*x.den);
}

bool Raz::operator== (const Raz& x) const{
    return num == x.num && den == x.den;
}

Raz Raz::operator++ (int) // postfisso
{
    // Prima dereferenzio con un Razionale temporaneo di copia
    Raz tmp(*this);
    // Quindi incremento di uno
    num += den;
    // Infine ritorno la variabile prima dell'incremento.
    return tmp;
}

Raz& Raz::operator++ () // prefisso
{
    // Incremento subito
    num += den;
    // Ritorno il risultato con incremento
    return *this;
}

Raz Raz::unTerzo(){
    return Raz(1, 3);
}

std::ostream& operator<< (std::ostream& os, const Raz& x)
{
    // Solo a lvl grafico: return os << x.num << '/' << x.den;
    return os << x.operator double();
}
