#ifndef NODO_H
#define NODO_H


class Nodo
{
    friend class Tree;
    public:
        Nodo(char ='*', Nodo* =0, Nodo* =0);
        Nodo* sx;
        Nodo* dx;
        char info;
};

#endif // NODO_H
