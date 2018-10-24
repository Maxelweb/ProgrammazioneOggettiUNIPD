#ifndef ORARIO_H
#define ORARIO_H

#include<iostream>
using namespace std;

class orario
{
    public:
        orario(); // default costructor
        orario(int, int); // costructor for hours and minutes
        orario (int, int, int); // ..
        int Ore() const;
        int Minuti() const;
        int Secondi() const;
        int getSec() const;
        orario operator+(orario); // overloading for sum
        bool operator==(const orario&) const; // overloading for ==
    private:
        int sec;
};

ostream& operator<<(ostream&, const orario&);


#endif // ORARIO_H
