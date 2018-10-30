#include "tree.h"

/** Costruttore base, creo un albero senza nodi */
Tree::Tree() : root(0) {}

/** Costruttore di copia */
Tree::Tree(const Tree& t) : root(copy(t.root)) {}

/** Overloading operatore di uguaglianza per copia profonda (a=b) */
Tree& Tree::operator= (const Tree &t)
{
    if(this != &t) // preservo dal fatto che siano uguali (a!=b)
    {
        destroy(root); // distruggo i nodi di "a"
        root = copy(t.root); // copio i nodi di "b" su "a"
    }
    return *this;
}

/** Definisco un distruttore */
Tree::~Tree()
{
    destroy(root);
}

/** Agisco nella parte privata, definisco copy per copia profonda */
Nodo* Tree::copy(Nodo * r)
{
    // Caso base
    if(!r) return 0;
    // Caso induttivo
    return new Nodo(r->info, copy(r->sx), copy(r->dx));
    /* Copio ogni nodo procedendo per esplorazione dei relativi branch */
}

void Tree::destroy(Nodo* r)
{
    if(r) // Se il nodo esiste, eseguo l'eliminazione ricorsivamente.
    {
        destroy(r->dx);
        destroy(r->sx);
        delete r;
    }
}
