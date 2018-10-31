#ifndef VETTORE_H
#define VETTORE_H

#include<ostream>

class vettore
{
    public:
        vettore(); // c. default
        vettore(int); // c. con dentro un valore
        vettore(const vettore&); // c. copy

        void append(const vettore&); // operazione di v1.append(v2)
        int getSize() const;
        ~vettore(); // distruttore

        vettore operator+(const vettore&) const; // v1+v2
        bool operator==(const vettore&) const; // uguaglianza
        friend std::ostream& operator<<(std::ostream&, const vettore&); // output
        int& operator[](unsigned int); // indicizzazione
        vettore& operator=(const vettore&); // copia profonda
    private:
        int * arr;
        unsigned int size;
        int * copy() const;

};

#endif // VETTORE_H
