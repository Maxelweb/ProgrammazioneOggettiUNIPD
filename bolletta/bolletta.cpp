#include "bolletta.h"

// Il costruttore di Default è definito inline.
// first è il primo elemento della lista
//
// Definisco prima la classe interna "nodo"
//
bolletta::nodo::nodo() : next(0) {}
bolletta::nodo::nodo(const telefonata& t, nodo* n) :
    info(t), next(n) {}

bolletta::nodo* bolletta::copia(nodo* p)
{
    if(!p) return 0;
    else return new nodo(p->info, copia(p->next));
}

void bolletta::distruggi(nodo* p)
{
    if(p)
    {
        distruggi(p->next);
        delete p;
    }
}

bolletta::bolletta(const bolletta & b) :
    first(copia(b.first)) {}

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
        }

        delete p;
    }
}

// Estraggo la prima bolletta, rimuovendola dalla lista
//
telefonata bolletta::estraiPrima()
{
   // if(!first) return telefonata();

    nodo *p = first;
    first = first->next;
    telefonata aux = p->info;
    delete p;
    return aux;
}

// Ritorno il numero di telefonate nella bolletta.
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
    return x;
}

// Estrai info telefonata i
//
telefonata bolletta::estraiInfo(int i) const
{
    nodo *current = first;
    while(current && i>0 && i<totalNodes())
    {
        current = current->next;
        i--;
    }
    telefonata aux = current->info;
    return aux;
}

// Overloading dell'operatore <<
//
std::ostream& operator<<(std::ostream& os, const bolletta& b)
{
    os << endl <<"TELEFONATE IN BOLLETTA:" << endl;

    if(b.Vuota())
        return os << "\t Nessuna telefonata trovata." << endl;

    int total = b.totalNodes();

    for(int i = 0; i < total; i++)
    {
        //b.estraiInfo(i);
        os << '\t' << (i+1) << ") " << b.estraiInfo(i) << endl;
    }

    os << "\t- TOTALE: " << total
       << std::endl;

    return os;
}


// Overloading operatore di assegnazione, per copia profonda
//
bolletta& bolletta::operator=(const bolletta& b)
{
    if(this != &b) // Controllo che a != b
    {
        distruggi(first); // Con a = b, dealloco a.
        first = copia(b.first);
    }
    return *this;
}
