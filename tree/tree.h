#ifndef TREE_H
#define TREE_H

#include "nodo.h"

class Tree
{
    public:
        Tree();
        Tree(const Tree&);
        Tree& operator= (const Tree&);
        ~Tree();
    private:
        Nodo* root;
        static Nodo* copy(Nodo*);
        static void destroy(Nodo*);
};

#endif // TREE_H
