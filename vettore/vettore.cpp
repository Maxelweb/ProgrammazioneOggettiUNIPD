#include "vettore.h"

/** Costruttore di default */
vettore::vettore() :
    size(0), arr(nullptr) {}


/** Costruttore con la size */
vettore::vettore(int x) :
    size(1), arr(new int[1]) { arr[0] = x;}


/** Costruttore di copia profonda */
vettore::vettore(const vettore& v) :
    size(v.size), arr(v.copy()) {}


/** Funzione di copia profonda */
int * vettore::copy() const
{
    int * newArr;
    newArr = !size ? nullptr : new int[size];

    for(unsigned int i=0; i < size; i++)
        newArr[i] = arr[i];

    return newArr;
}


/** Distruttore */
vettore::~vettore()
{
    if(arr) delete[] arr;
}


/** Recupero la size del vettore */
int vettore::getSize() const
{
    return size;
}


/** Funzione che "appende" un vettore ad un altro vettore
 *   (simile a somma di vettori)
 *   Richiede overloading di + e =
 */
void vettore::append(const vettore &v)
{
    *this = *this + v;
}


/** Overloading operatore di somma (v3 = v1+v2)*/
vettore vettore::operator +(const vettore &v) const
{
    vettore x;
    unsigned int n = size + v.size;
    if(n)
    {
        x.arr = new int[n];
        x.size = n;

        for(unsigned int i=0; i < size; i++)
            x.arr[i] = arr[i];

        for(unsigned int i=0; i < v.size; i++)
            x.arr[size+i] = v.arr[i];
    }
    return x;
}


/** Overloading operatore di uguaglianza */
bool vettore::operator==(const vettore &v) const
{
    return size == v.size && arr == v.arr;
}


/** Overloading operatore di indicizzazione */
int& vettore::operator[](unsigned int i)
{
    return arr[i];
}


/** Overloading operatore di assegnazione */
vettore& vettore::operator=(const vettore& v)
{
    if(this != &v) // protezione contro a == b
    {
        if(arr) delete[] arr; // rimuovo a
        arr = v.copy(); // copio tutti gli elementi di b su a.
        size = v.size; // copio i campi rimanenti
    }

    return *this;
}


/** Overloading operatore di output */
std::ostream& operator<< (std::ostream &os, const vettore &v)
{
    os << '[';
    for(unsigned int i=0; i<v.size; i++)
    {
       os << v.arr[i];
       if(i != v.size-1) os << ',';
    }
    os << "] (size: " << v.size << ')';

    return os;
}





