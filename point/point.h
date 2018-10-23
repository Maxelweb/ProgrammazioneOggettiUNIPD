#ifndef POINT_H
#define POINT_H

#include <iostream>


/**
    Classe "punto" in uno spazio tridimensionale
*/


class point
{
    private:
        double x, y, z;

    public:
        // point();
        point(double = 0, double = 0, double = 0);
        void negate(); // Trasforma un punto nel suo opposto
        double norm(); // restituisce la distanza di un punto dall'origine
        void print(); // Stampa le coordinate di un punto --> faccio anche un override del cout
        double getX();
        double getY();
        double getZ();
};

std::ostream& operator<<(ostream& os, const point&);
point operator + (const point&, const point&); // override della somma


#endif
