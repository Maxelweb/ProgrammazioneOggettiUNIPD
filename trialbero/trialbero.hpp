
/*
ESERCIZIO DISCUSSO NELLE LEZIONI DEL 5-6.11.2018

Definire un template di classe albero<T> i cui oggetti rappresentano
un albero 3-ario ove i nodi memorizzano dei valori di tipo T ed hanno
3 figli (invece dei 2 figli di un usuale albero binario). Il template
albero<T> deve soddisfare i seguenti vincoli:
1. Deve essere disponibile un costruttore di default che costruisce l’albero vuoto.
2. Gestione della memoria senza condivisione.
3. Metodo void insert(const T&): a.insert(t) inserisce nell'albero a una nuova radice che memorizza il valore t ed avente come figli 3 copie di a
4. Metodo bool search(const T&): a.search(t) ritorna true se t occorre nell'albero a, altrimenti ritorna false.
5. Overloading dell'operatore di uguaglianza.
6. Overloading dell'operatore di output.

*/

#include <iostream>


template <class T>
class trialbero;

template <class T>
std::ostream& operator<<(std::ostream&, const trialbero<T>&);

/** -------- Dichiarazione -------- */

template <class T>
class trialbero
{
    friend std::ostream& operator<< <T> (std::ostream&, const trialbero&);

    private:
        class nodo
        {
            public:
                T info;
                nodo *sx, *cx, *dx;
                nodo(const T& t, nodo *s=0, nodo *c=0, nodo *d=0)
                    : info(t), sx(s), cx(c), dx(d) {}

        };

        nodo *root;
        static void distruggi(nodo*); // metodo statico ausiliario per la distruzione profonda
        static nodo* copia(nodo*); // metodo ausiliario per la copia profonda
        static bool equals(nodo*, nodo*); // metodo statico ausiliario per uguaglianza dei campi dei nodi
        static bool recursiveSearch(nodo*, const T&); // ricerca di un elemento di tipo T in un nodo ricorsivamente
        static std::ostream& print(std::ostream&, nodo*);
    public:
        trialbero() : root(nullptr) {}
        trialbero(const trialbero&);
        ~trialbero();
        void insert(const T&);
        bool search(const T&) const;
        trialbero& operator=(const trialbero&);
        bool operator== (const trialbero& t) const;

};



/** -------- Definizione -------- */

//template <class T> using trialbero<T>;


template <class T> 
void trialbero<T>::distruggi(nodo *r)
{
    // Distruzione profonda

    if(r)
    {
        distruggi(r->sx);
        distruggi(r->cx);
        distruggi(r->dx);
        delete r;
    }
}

template <class T> 
nodo* trialbero<T>::copia(nodo * r)
{
    /* Copia profonda: 
     *   dato un nodo *r (== root), copio il campo info corrente
     *   quindi continuo ricorsivamente sugli altri nodi
    */
    
    // (caso base) Se il nodo non esiste, ritorno un puntatore nullo.
    if(!r) return nullptr;
    // (caso induttivo) Ritorno il nuovo nodo con la info copiata ed eseguo la copia nei nodi figli
    return new nodo(r->info, copia(r->sx), copia(r->cx), copia(r->dx));
}


template <class T>
trialbero<T>::trialbero(const trialbero& t)
    : root(copia(t.root))
{
    // Quando costruisco un nuovo albero da un altro albero, 
    // lo copio profondamente dalla root
}


template <class T>
trialbero& trialbero<T>::operator=(const trialbero& t)
{
    /* Assegnazione con distruzione e copia profonda 
    */

    if(*this != &t) // Preservo sempre dalla copia a = a
    {
        distruggi(root);
        root = copia(t.root);
    }

    return *this;
}


template <class T>
trialbero<T>::~trialbero()
{
    // Ridefinizione della distruzione
    distruggi(root);
}


template <class T>
void trialbero<T>::insert(const T& x)
{
    // la nuova radice sarà formata da tre copie del nodo root originale.
    root = new nodo(x, root, copia(root), copia(root))
}

template <class T>
bool trialbero<T>::equals (nodo * n1, nodo * n2)
{
    // Funzione per operatore di uguaglianza casi base + induzione

    if(!n1 && !n2) return true;
    // esistono n1 || n2
    if(!n1 || !n2) return false; // --> entrambi devono esistere
    // esiste n1 && n2

    return n1->info == n2->info || 
           equals(n1->sx, n2->sx) ||
           equals(n1->cx, n2->cx) ||
           equals(n1->dx, n2->dx);
}

template <class T>
bool trialbero<T>::operator== (const trialbero& t) const
{
    return equals(root, t.root);
}


template <class T>
bool trialbero<T>::recursiveSearch(nodo * n, const T& t)
{
    // Funzione ausiliaria per la ricerca di una informazione in un nodo n
    if(!n) return false; 
    // il nodo esiste
    return n->info == t || recursiveSearch(n->sx) || recursiveSearch(n->cx) || recursiveSearch(n->dx);

}

template <class T>
bool trialbero<T>::search(const T& x) const
{
    // a.search(b): ricerco in a (dalla root) se c'è una informazione x di tipo T
    return recursiveSearch(root, x);
}

template <class T>
std::ostream print(std::ostream& os, nodo* x);
{
    if(!x) return os;
    os << "[" << x->info << ";";
    print(x->sx,os); os << ",";
    print(x->cx,os); os << ",";
    print(x->dx,os); os << "]";
    return os;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const trialbero<T>& t)
{
    return print(os, t.root);
}
