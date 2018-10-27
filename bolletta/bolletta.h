#ifndef BOLLETTA_H
#define BOLLETTA_H

#include "../telefonata/telefonata.h"

class bolletta
{
    public:
        bolletta() : first(0) {}
        bolletta(const bolletta&);
        bool Vuota() const;
        void aggiungiTel(telefonata);
        void togliTel(telefonata);
        telefonata estraiPrima();
        int totalNodes() const;
        telefonata estraiInfo(int) const;
        bolletta& operator=(const bolletta &);


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
        static nodo* copia(nodo*);
        static void distruggi(nodo*);
};

std::ostream& operator<<(std::ostream&, const bolletta&);

#endif // BOLLETTA_H
