#include "bolletta.h"

// Il costruttore di Default è definito inline.
// first è il primo elemento della lista
//
// Definisco prima la classe interna "nodo"
//
bolletta::nodo::nodo() : next(0) {}
bolletta::nodo::nodo(const telefonata& t, nodo* n) :
    info(t), next(n) {}


bool bolletta::Vuota() const
{
    return first == 0;
}

// Aggiungo in testa la nuova telefonata
//
void bolletta::aggiungiTel(telefonata t)
{
    first = new nodo(t, first);
}

void bolletta::togliTel(telefonata t)
{
    nodo *p = first, *prec = 0;
    while(p && !(p->info == t))
    {
        prec = p;
        p = p->next;
    }

    if(p)
    {
        // Se p punta al primo nodo (e quindi non ha precedenti)
        // allora il nuovo nodo iniziale sarà il secondo nodo.
        // nella lista.
        //
        if(!prec)
            first = p->next;

        // Altrimenti, se p è in un nodo in mezzo alla lista
        // aggancio il nodo precedente col nodo successivo
        // a quello ricercato da eliminare
        //
        else
        {
            prec->next = p->next;
            delete p;
        }
    }
}

// Estraggo la prima bolletta, rimuovendola dalla lista
//
telefonata bolletta::estraiPrima()
{
    if(!first) return telefonata();

    nodo *p = first;
    first = first->next;
    telefonata aux = p->info;
    delete p;
    return aux;
}

// Ritorno il numero di telefonata nella bolletta.
//
int bolletta::totalNodes() const
{
    int x = 0;
    nodo *p = first;
    while(p)
    {
        p = p->next;
        x++;
    }
    delete p;
    return x;
}

// Overloading dell'operatore <<
//
std::ostream& operator<<(std::ostream& os, bolletta b1)
{
    os << "TELEFONATE IN BOLLETTA:" << std::endl;

    bolletta b2 = b1;
    int total = b2.totalNodes();

    for(int i = 0; i < total; i++)
    {
        os << '\t' << (i+1) << ") " << b2.estraiPrima() << std::endl;
    }

    os << '\t' << "--------------------" << std::endl
       << '\t' << "TELEFONATE TOTALI: " << total
       << std::endl;

    return os;
}

