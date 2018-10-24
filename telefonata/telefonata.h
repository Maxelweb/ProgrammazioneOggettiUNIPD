#ifndef TELEFONATA_H
#define TELEFONATA_H

#include <iostream>
#include <string>
#include "../orario/orario.h"

using std::ostream;

class telefonata
{
    public:
        telefonata ();
        telefonata(const orario&, const orario&, string);
        orario Inizio() const;
        orario Fine() const;
        string Numero() const;
        bool operator == (const telefonata &) const;
    private:
        orario inizio, fine;
        const string numero;
};

std::ostream& operator<<(std::ostream&, const telefonata&);

#endif // TELEFONATA_H
