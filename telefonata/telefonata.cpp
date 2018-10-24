#include "telefonata.h"


telefonata::telefonata() :
numero("0") {}


// Costruttore di copia
telefonata::telefonata(const orario& i, const orario& f, string n) :
inizio(i), fine(f), numero(n) {}


orario telefonata::Inizio() const { return inizio; }
orario telefonata::Fine() const { return fine; }
string telefonata::Numero() const { return numero; }

bool telefonata::operator==(const telefonata& t) const
{
    return inizio == t.inizio && fine == t.fine && numero == t.numero;
}

std::ostream& operator<<(std::ostream& os, const telefonata& t)
{
    return os << "[PHONE CALL] start: " << t.Inizio() << " | end: " << t.Fine() << " | number: " << t.Numero();
}
