/**
   Template Classe Queue e QueueItem (pag 131)
   ---------------------
   La dichiarazione e l'implementazione devono essere inseriti
   all'interno dello stesso file
*/

#include <iostream>
using namespace std;


/* ============= Dichiarazione output ============= */

// Fare attenzione alle dichiarazioni! (pag 137)

template <class T>
class Queue;

template <class T>
ostream& operator<<(ostream&, const Queue<T>&);


/* ============= Dichiarazione di QueueItem ============= */

template <class T>
class QueueItem
{
    friend ostream& operator<< <T>(ostream&, const Queue<T>&);
    public:
        QueueItem(const T &v) : info(v), next(0) {}
        T info;
        QueueItem* next;
};


/* ============= Dichiarazione di Queue ============= */

template <class T>
class Queue
{
    friend ostream& operator<< <T>(ostream&, const Queue<T>&);
    public:
        Queue() : primo(0), ultimo(0) {}
        ~Queue();
        bool is_empty() const;
        void add(const T&);
        T first() const;
        T remove();
    private:
        QueueItem<T>* primo;
        QueueItem<T>* ultimo;
};


/* ============= Implementazioni ============= */

template <class T>
bool Queue<T>::is_empty() const { return primo == 0; }

template <class T>
void Queue<T>::add(const T& v)
{
    QueueItem<T>* p = new QueueItem<T>(v);

    if(!primo) // coda vuota, primo elemento
    {
        primo = p;
        ultimo = p;
    }
    else // aggiungo in coda
    {
        ultimo->next = p;
        ultimo = p;
    }
}

template <class T>
T Queue<T>::remove()
{
    if(is_empty())
    {
        std::cerr << "Rimozione su coda vuota!" << std::endl;
        exit(1);
    }

    QueueItem<T>* p = primo;
    primo = primo->next;
    T aux = p->info;
    delete p;
    return aux;
}

template <class T>
Queue<T>::~Queue()
{
    while(!is_empty()) remove();
}

template <class T>
T Queue<T>::first() const
{
    if(is_empty())
    {
        std::cerr << "La coda risulta vuota!" << std::endl;
        exit(1);
    }

    return primo->info;
}

template <class T>
ostream& operator<<(ostream& os, const QueueItem<T>& qi)
{
    return os << qi.info;
}

template <class T>
ostream& operator<<(ostream& os, const Queue<T> &v)
{
    os << '[';
    QueueItem<T> *p = v.primo;
    for(; p!=0; p = p->next)
        os << *p << ' ';
    os << ']' << std::endl;
    return os;
}

