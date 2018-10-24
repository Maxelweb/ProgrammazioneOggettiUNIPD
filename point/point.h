#ifndef POINT_H
#define POINT_H

#include <iostream>


/**
    Classe "punto" in uno spazio tridimensionale
*/

class Point
{
    private:
        double x, y, z;

    public:
        // point();
        Point(double = 0, double = 0, double = 0);
        void negate(); // Trasforma un punto nel suo opposto
        double norm() const; // restituisce la distanza di un punto dall'origine
        // void print(); // Stampa le coordinate di un punto --> faccio direttamente override del cout
        double getX() const;
        double getY() const;
        double getZ() const;
};

std::ostream& operator<<(std::ostream&, const Point&);
Point operator + (const Point&, const Point&); // override della somma


#endif
