#ifndef BOLLETTA_H
#define BOLLETTA_H

#include "../telefonata/telefonata.h"

class bolletta
{
    public:
        bolletta() : first(0) {}
        bool Vuota() const;
        void aggiungiTel(telefonata);
        void togliTel(telefonata);
        telefonata estraiPrima();
        int totalNodes() const;


    private:
        class nodo
        {
            public:
                nodo();
                nodo(const telefonata&, nodo*);
                telefonata info;
                nodo* next;
        };
        nodo* first;
};

std::ostream& operator<<(std::ostream&, bolletta);

#endif // BOLLETTA_H
