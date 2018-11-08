
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

#include <ostream>


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

    public:
        trialbero() : radice(nullptr) {}
        trialbero(const trialbero&);
        ~trialbero();
        void insert(const T&);
        bool search(const T&);
        trialbero& operator=(const trialbero&);
}



/** -------- Definizione -------- */

template <class T> using trialbero<T>;


template <class T> void distruggi(nodo *r)
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

template <class T> nodo* copia(nodo * r)
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
trialbero(const trialbero& t) 
    : root(copia(t.root))
{
    // Quando costruisco un nuovo albero da un altro albero, 
    // lo copio profondamente dalla root
}


template <class T>
trialbero& operator=(const trialbero& t)
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
~trialbero() 
{
    // Ridefinizione della distruzione
    distruggi(root);
}


template <class T>
void insert(const T& x)
{
    // la nuova radice sarà formata da tre copie del nodo root originale.
    root = new nodo(x, root, copia(root), copia(root))
}




